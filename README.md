### RFID Närvaro

# Innehåll:
  * [Projektbeskrivning](#Projektbeskrivning)
  * [Installationer](#installationer)
  * [Hjälp](#hjälp)
  * [Filer och mappar](#filer-och-mappar)
  * [Programmet](#programmet)
  * [Starta Programmet](#starta-programmet)
  * [Förbättringar](#förbättringar)
---



# Projektbeskrivning
Grundidén var att göra en RFID-scanner med uppkoppling till internet, vars syfte är att ta närvaro på elever med deras passerkort. Vid lektionsstart blippar eleverna sina kort och de registreras som närvarande på en hemsida, där läraren lätt kan se vilka som är närvarande och inte samt när varje elev blippade sitt kort. 


# Installationer
Följande behövs installeras innan start:
  
* [Firebase ESP8266](https://github.com/mobizt/Firebase-ESP8266?utm_source=platformio&utm_medium=piohome) av Mobizt för att ansluta till **Firebase** från **ESP8266**

* [MFRC522](https://github.com/miguelbalboa/rfid?utm_source=platformio&utm_medium=piohome) av Mobizt för att ansluta till **Firebase** från **ESP8266**

* För att ansluta **Firebase** och hemsidan behöver **vuefire** installeras. Kör `npm install vuefire firebase` i **Frontend/** mappen.




# Hjälp
* För att få **RFID** att fungera med **arduino** följde vi [denna](https://lastminuteengineers.com/how-rfid-works-rc522-arduino-tutorial/ "What is RFID? How It Works? Interface RC522 RFID Module with Arduino") guide.

* För att få **Firebase** att fungera med **hemsidan** följde vi [Vuefire dokumentationen](https://vuefire.vuejs.org/vuefire/getting-started.html#installation "What is RFID? How It Works? Interface RC522 RFID Module with Arduino").

# Filer och mappar
* **Frontend/**: Innehåler kod för att köra hemsidan.
* **Backend/**: Innehåller kod för att köra **ESP8266**.


# Programmet:
Programmet fungerar genom att **RFID-läsaren** uppdaterar timestamp i en [**Firebase Realtime Database**](https://firebase.google.com/products/realtime-database?gclid=CjwKCAiA78aNBhAlEiwA7B76p5hw5cjylFw5hevQAQ5zlwed0q_6vzpe9LaTPOGAasoVHiOKVOgRehoCZRQQAvD_BwE&gclsrc=aw.ds) när användaren skannar sitt kort. Hemsidan uppdateras sedan elevens närvaro genom att jämföra timestampen med tiderna på elevens [**TimeEdit**](https://cloud.timeedit.net/abbindustrigymnasium/web/public1/ri1Q7.html) schema. Detta schema hämtas genom prenumeration funktionen som ger en **iCalendar file (.ics)** som hämtas via en [**asynchronous HTTP request**](https://github.com/learnTrack/Q-A/issues/8).


# Starta programmet
* Gå in i mappen **Frontend/** med valfri terminal och skriv `npm run serve` för att starta hemsida.

* Ladda upp **C++** koden i **Backend/** mappen till en **ESP8226** som är kopplad till en **RFID-läsare**.


# Förbättringar
* Projektet skulle kunna förbättras genom att göra en sida där lärare kan se närvaro för alla sina lektioner och inte bara närvaro för varje klass.

* Schemat skulle kunna sparas i databasen och hämtas när första användaren varje månad besöker hemsidan.

* Datan skulle kunna sparas så att man kan se närvaro för tidigare lektioner och inte bara den nuvarande.

* Om en användare skannar sitt kort två gånger under samma lektion så ska den första räknas.


