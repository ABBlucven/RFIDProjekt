#include <Arduino.h>
/**
 * Created by K. Suwatchai (Mobizt)
 * 
 * Email: k_suwatchai@hotmail.com
 * 
 * Github: https://github.com/mobizt
 * 
 * Copyright (c) 2021 mobizt
 *
*/

/** This example will show how to authenticate using 
 * the legacy token or database secret with the new APIs (using config and auth data).
*/
#if defined(ESP32)
#include <WiFi.h>
#include <FirebaseESP32.h>
#elif defined(ESP8266)
#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>
#endif

//Provide the RTDB payload printing info and other helper functions.
#include <addons/RTDBHelper.h>

//MFRC522
#include <SPI.h>
#include <MFRC522.h>

/* 1. Define the WiFi credentials */
#define WIFI_SSID "ABB_Gym_IOT"
#define WIFI_PASSWORD "Welcome2abb"

/* 2. If work with RTDB, define the RTDB URL and database secret */
#define DATABASE_URL "rfid-project-e703f-default-rtdb.europe-west1.firebasedatabase.app" //<databaseName>.firebaseio.com or <databaseName>.<region>.firebasedatabase.app
#define DATABASE_SECRET "LQAA7kMX5asJ5fs10uZMIly00tDz4j5t7PqUAjBL"


/*rfid */
#define RST_PIN         2          //D4
#define SS_PIN          15         //(CS) D8 (sda)
#define D5 14 // SPI Bus SCK (clock) (Clk)
#define D6 12 // SPI Bus MISO 
#define D7 13 // SPI Bus MOSI
 
MFRC522 rfid(SS_PIN, RST_PIN); // Instance of the class

MFRC522::MIFARE_Key key; 

// Init array that will store new NUID 
String UID = "";
String path = "";
String name = "";
String Confirm = "";

/* 3. Define the Firebase Data object */
FirebaseData fbdo;

/* 4, Define the FirebaseAuth data for authentication data */
FirebaseAuth auth;

/* Define the FirebaseConfig data for config data */
FirebaseConfig config;

unsigned long dataMillis = 0;
int count = 0;

void setup()
{

    Serial.begin(115200);
    SPI.begin(); // Init SPI bus
    rfid.PCD_Init(); // Init MFRC522 

    for (byte i = 0; i < 6; i++) {
      key.keyByte[i] = 0xFF;
    }

    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    Serial.print("Connecting to Wi-Fi");
    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.print(".");
        delay(300);
    }
    Serial.println();
    Serial.print("Connected with IP: ");
    Serial.println(WiFi.localIP());
    Serial.println();

    Serial.printf("Firebase Client v%s\n\n", FIREBASE_CLIENT_VERSION);

    /* Assign the certificate file (optional) */
    //config.cert.file = "/cert.cer";
    //config.cert.file_storage = StorageType::FLASH;

    /* Assign the database URL and database secret(required) */
    config.database_url = DATABASE_URL;
    config.signer.tokens.legacy_token = DATABASE_SECRET;

    Firebase.reconnectWiFi(true);

    /* Initialize the library with the Firebase authen and config */
    Firebase.begin(&config, &auth);

    //Or use legacy authenticate method
    //Firebase.begin(DATABASE_URL, DATABASE_SECRET);
}

void loop()
{
  UID = "";
  
  
  
  // Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
  if ( ! rfid.PICC_IsNewCardPresent())
    return;

  // Verify if the NUID has been readed
  if ( ! rfid.PICC_ReadCardSerial())
    return;

  Serial.print(F("PICC type: "));
  MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);
  Serial.println(rfid.PICC_GetTypeName(piccType));

  // Check is the PICC of Classic MIFARE type
  if (piccType != MFRC522::PICC_TYPE_MIFARE_MINI &&  
    piccType != MFRC522::PICC_TYPE_MIFARE_1K &&
    piccType != MFRC522::PICC_TYPE_MIFARE_4K) {
    Serial.println(F("Your tag is not of type MIFARE Classic."));
    return;
  }
    // Store NUID into nuidPICC array
    for (byte i = 0; i < 4; i++) {
      UID += String(rfid.uid.uidByte[i], HEX);
    }
    Serial.println(UID);

  // Halt PICC
  rfid.PICC_HaltA();

  // Stop encryption on PCD
  rfid.PCD_StopCrypto1();
  
  path = "/students/190S/" + UID ;

  Serial.print("Name: ");
  while (Serial.available() == 0)
  {}
  name = Serial.readString();

    // say what you got:
  Serial.println(name);

  Serial.println("Confirm? Y/N");
  while (Serial.available() == 0)
  {}
  Confirm = Serial.readString();
  if (Confirm != "Y" and Confirm != "y")
  {
    Serial.println("Scan card");  
    return;
  }

  if (millis() - dataMillis > 5000)
    {
        dataMillis = millis();
        //Serial.printf("Set rfid... %s\n", Firebase.setString(fbdo, path + "/class", "190S")  ? "ok" : fbdo.errorReason().c_str());
        Serial.printf("Set timestamp... %s\n", Firebase.setTimestamp(fbdo, path + "/timestamp") ? "ok" : fbdo.errorReason().c_str()); //new Date(timestamp) javascript
        Serial.printf("Set rfid... %s\n", Firebase.setString(fbdo, path + "/name", name)  ? "ok" : fbdo.errorReason().c_str());
        Serial.printf("Get timestamp... %s\n", Firebase.getDouble(fbdo, path + "/timestamp") ? "ok" : fbdo.errorReason().c_str());
        Serial.printf("TIMESTAMP: %lld\n", fbdo.to<uint64_t>());
    }
  
  Serial.println("Scan card");  

}