#include "WiFiEsp.h"
#include "SoftwareSerial.h"

SoftwareSerail(2, 3);

#endif 
int status = WL_IDLE_STATUS;
WiFiESPCLient client;
String getHttpStatus;
String getData;

void httpGet(char* maziot_server, String maziot_path, int maziot_port){
    client.stop();
    if (client.connect(maziot_server, maziot_port)){
        client.print("GET ");
        client.print(maziot_path);
        client.println(" HTTP/1.1");
        client.print("Host: ");
        client.println(maziot_server);
        client.println("Connection: close");
        client.println();
        char endOfHeaders[] = "\r\n\r\n";
        client.find(endOfHeaders);
        getData = client.readString();
        getData.trim();
        getHttpStatus = "Status: Connection Success!";
    }
    else {
        getHttpStatus = "Status: Connection Failde!";
    }
}

void setWiFi(char* maziot_ssid, char* maziot_pass){
    Serial.begin(115200);
    Serial.println("AT+UART_DEF=9600,8,1,0,0");
    delay(500);
    Serial.begin(9600);
    WiFi.init(&Serial);
    if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("[WIFI]: WiFi not Detected!");
    while (true);
  }
  while(status != WL_CONNECTED){
      Serial.print("[WIFI]: Try To reconnecting to SSID ...");
      Serial.println(maziot_ssid);
      status = WiFi.begin(maziot_ssid, maziot_pass);
  }
  Serial.print("[WIFI]: Successful Connection to");
  Serial.println(maziot_ssid);

  Serial.print("[WIFI]: SSID: ");
  Serial.println(WiFi.SSID());
  long rssi = WiFi.RSSI();
  Serial.print("[WIFI]: Kekuatan Sinyal (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}