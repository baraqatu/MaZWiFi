/**
 * 
 * The example code you can use for Board Arduno Family
 * - Arduino UNO / Arduino Nano -> TX to 2, RX to 3.
 * - Arduino Mega -> TX to RX1, RX to TX1.
 * 
 * Thank's
 */

#include<MaZWiFi.h>

char* SSID = "your-wifi-ssid";
char* PASS = "your-wifi-password";

void setup(){
    Serial.begin(9600);
    setWiFi(SSID, PASS);
}

void loop(){
    // add your code here
}