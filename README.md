# RFID-projekt

##Bakgrund

Vårt mål var att göra en RFID-scanner med uppkoppling till internet, med syftet att ta närvaro på elever genom deras passerkort. Vid lektionsstart blippar eleverna sina kort och deras närvaro registreras på en hemsida, där läraren lätt kan se vilka som är närvarande och inte, samt när varje elev blippade sitt kort. 

##Tillvägagångssätt

Projektet har delats upp i tre huvuddelar: konstruktion, backend och frontend. 

###Konstruktion

Konstruktionen består av en mikrodator (Arduino ESP8266) och en RFID-scanner (RD522), omslutna av en 3D-printad låda/hållare. 

###Backend

Backend består av en databas där samtliga registrerade elever lagras samt tidpunkten då de blippade sina kort. Databasen hostas i Firebase. 

###Frontend

Hemsidan är byggd med hjälp av JavaScript-ramverket Vue.

##Utvecklingsmöjligheter


