#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <ESP8266HTTPUpdateServer.h>

ESP8266WebServer server ( 80 );
MDNSResponder mdns;
ESP8266HTTPUpdateServer httpUpdater;

#define HOST_NAME  "Fi-Del"
#define ACCESS_POINT_NAME  "Fi-Del"
#define ACCESS_POINT_PASSWORD  "12345678"
String Statuses[] =  { "WL_IDLE_STATUS=0",
                       "WL_NO_SSID_AVAIL=1",
                       "WL_SCAN_COMPLETED=2",
                       "WL_CONNECTED=3",
                       "WL_CONNECT_FAILED=4",
                       "WL_CONNECTION_LOST=5",
                       "WL_DISCONNECTED=6"
                       };
String st;
String content;
int statusCode;


bool testWifi(void) {
  int c = 0;
  Serial.println("En attente de la connection Wifi");
  while ( c < 20 ) {
    if (WiFi.status() == WL_CONNECTED) { return true; }
    delay(500);
    Serial.print("Interval=");
    Serial.print(c);
    Serial.print(", WiFi.status= ");
    Serial.println(Statuses[WiFi.status()]);
    c++;
  }
  Serial.println("");
  Serial.println("Connect timed out, Creation Wifi AP");
  return false;
}

void createWebServer(int webtype)
{
  if ( webtype == 1 ) {
    server.on("/ip", []() {
        IPAddress ip = WiFi.softAPIP();
        String ipStr = String(ip[0]) + '.' + String(ip[1]) + '.' + String(ip[2]) + '.' + String(ip[3]);
        content = "<!DOCTYPE HTML>\r\n<html>Hello from ESP8266 at ";
        content += ipStr;
        content += "<p>";
        content += st;
        content += "</p><form method='get' action='setting'><label>SSID: </label><input name='ssid' length=32><input name='pass' length=64><input type='submit'></form>";
        content += "</html>";
        server.send(200, "text/html", content);
    });

  } else if (webtype == 0) {
    server.on("/ip", []() {
      IPAddress ip = WiFi.localIP();
      String ipStr = String(ip[0]) + '.' + String(ip[1]) + '.' + String(ip[2]) + '.' + String(ip[3]);
      server.send(200, "application/json", "{\"IP\":\"" + ipStr + "\"}");
    });
  }
      server.on("/cleareeprom", []() {
      content = "<!DOCTYPE HTML>\r\n<html>";
      content += "<p>Clearing the EEPROM</p></html>";
      server.send(200, "text/html", content);
      Serial.println("clearing eeprom");
      for (int i = 0; i < 96; ++i) { EEPROM.write(i, 0); }
      EEPROM.commit();
      WiFi.disconnect();
    });
        server.on("/setting", []() {
        String qsid = server.arg("ssid");
        String qpass = server.arg("pass");
        if (qsid.length() > 0 && qpass.length() > 0) {
          Serial.println("clearing eeprom");
          for (int i = 0; i < 96; ++i) { EEPROM.write(i, 0); }
          Serial.println(qsid);
          Serial.println("");
          Serial.println(qpass);
          Serial.println("");

          Serial.println("Ecriture eeprom ssid:");
          for (int i = 0; i < qsid.length(); ++i)
            {
              EEPROM.write(i, qsid[i]);
              Serial.print("Ecriture: ");
              Serial.println(qsid[i]);
            }
          Serial.println("Ecriture eeprom pass:");
          for (int i = 0; i < qpass.length(); ++i)
            {
              EEPROM.write(32+i, qpass[i]);
              Serial.print("Ecriture: ");
              Serial.println(qpass[i]);
            }
          EEPROM.commit();
          content = "{\"Success\":\"Le nouveau SSID et MDP sont sauvegarde... Un redemarrage du serveur est effectue\"}";
          statusCode = 200;
        } else {
          content = "{\"Error\":\"404 not found\"}";
          statusCode = 404;
          Serial.println("Sending 404");
        }
        server.send(statusCode, "application/json", content);
        if (statusCode == 200){
          delay(2000);
          ESP.restart();
        }
    });
}

void launchWeb(int webtype) {
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("Local IP: ");
  Serial.println(WiFi.localIP());
  Serial.print("SoftAP IP: ");
  Serial.println(WiFi.softAPIP());
  createWebServer(webtype);
}

void setupAP(void) {
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
  int n = WiFi.scanNetworks();
  Serial.println("scan Ok");
  if (n == 0)
    Serial.println("Pas de Wifi trouver");
  else
  {
    Serial.print(n);
    Serial.println(" reseaux trouve");
    for (int i = 0; i < n; ++i)
     {
      // Print SSID and RSSI for each network found
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.print(WiFi.SSID(i));
      Serial.print(" (");
      Serial.print(WiFi.RSSI(i));
      Serial.print(")");
      Serial.println((WiFi.encryptionType(i) == ENC_TYPE_NONE)?" ":"*");
      delay(10);
     }
  }
  Serial.println("");
  st = "<ol>";
  for (int i = 0; i < n; ++i)
    {
      // Print SSID and RSSI for each network found
      st += "<li>";
      st += WiFi.SSID(i);
      st += " (";
      st += WiFi.RSSI(i);
      st += ")";
      st += (WiFi.encryptionType(i) == ENC_TYPE_NONE)?" ":"*";
      st += "</li>";
    }
  st += "</ol>";
  delay(100);
  WiFi.softAP(ACCESS_POINT_NAME, ACCESS_POINT_PASSWORD, 6);
  Serial.println("softap");
  launchWeb(1);
  Serial.println("over");
}

// MDNS
void MDNSConnect() {
  if (!MDNS.begin(HOST_NAME)) {
   Serial.println("Error setting up MDNS responder!");
    while (1) {
      delay(1000);
    }
  }
  Serial.println("mDNS responder started");
  MDNS.addService("http", "tcp", 80);
}
