#include <iterator>
#include <iostream>

#include <ModbusRTU.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266HTTPUpdateServer.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ModbusIP_ESP8266.h>
#include <SoftwareSerial.h>
#include <ArduinoOTA.h>

// Load configuration
#include "config.h"

// Load pages templates
#include "pages.h"

// Load registers addresses
#include "registers.h"


ModbusRTU mb_rtu;
ModbusIP mb_tcp;
ESP8266WebServer httpServer(80);
ESP8266HTTPUpdateServer httpUpdater;
SoftwareSerial ModbusSerial(4, 5);

const char* ssid = SSID;
const char* password = PSK;
const char* hostname = HOSTNAME;

uint16_t RegInitVal = 0;
uint16_t cReg = 0;

void handleNotFound() {
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += httpServer.uri();
  message += "\nMethod: ";
  message += (httpServer.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += httpServer.args();
  message += "\n";
  for (uint8_t i = 0; i < httpServer.args(); i++) {
    message += " " + httpServer.argName(i) + ": " + httpServer.arg(i) + "\n";
  }

  httpServer.send(404, "text/plain", page_404);
}


void otaInit() {
  ArduinoOTA.setHostname(HOSTNAME);
  ArduinoOTA.begin();
}

void setup() {

  // Init serials
  Serial.begin(115200);

  
  ModbusSerial.begin(9600, SWSERIAL_8N1);

  // Init wifi
  WiFi.mode(WIFI_STA);
  WiFi.hostname(HOSTNAME);
  WiFi.begin(SSID, PSK);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    delay(5000);
    ESP.restart();
  }

  // Init OTA and webui
  MDNS.begin(HOSTNAME);
  httpUpdater.setup(&httpServer);
  httpServer.begin();
  MDNS.addService("http", "tcp", 80);
 
  otaInit();

  httpServer.onNotFound(handleNotFound);
  httpServer.on("/", []() {
    httpServer.send(200, "text/html", index_page);
  });

  // Init modbus rtu and tcp
  mb_rtu.begin(&ModbusSerial);
  mb_rtu.master();
  mb_tcp.server(502);

  // Get size of array with register's addresses
  auto array_length = std::end(sdm_registers) - std::begin(sdm_registers);

  // Init local input register
  for ( int i = 0; i < array_length; i++) {
    mb_tcp.addIreg(sdm_registers[i], RegInitVal);
    mb_tcp.addIreg(sdm_registers[i] + 0x0001, RegInitVal);
  };

}


void loop() {
  ArduinoOTA.handle();
  httpServer.handleClient();
  MDNS.update();

  auto array_length = std::end(sdm_registers) - std::begin(sdm_registers);
  if (!mb_rtu.slave()) {

    switch (array_length - cReg) {
      case 0:
        cReg = 0;
        break;

      default:
        mb_rtu.pullIreg(1, sdm_registers[cReg], sdm_registers[cReg], 2);
        uint16_t var_reg1 = mb_tcp.Ireg(sdm_registers[cReg]);
        uint16_t var_reg2 = mb_tcp.Ireg(sdm_registers[cReg] + 0x0001);
        uint32_t var_reg = (var_reg1 << 16) +  var_reg2;
        float var = *((float*)&var_reg);
        cReg++;
    }

  };

  mb_rtu.task();
  mb_tcp.task();

}
