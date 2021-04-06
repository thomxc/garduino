#define DHT_SENSOR_PIN D1
#define DHTTYPE DHT11
#define SOIL_HUM_ANALOG_PIN A0
#define LUX_ADDR BH1750_TO_VCC
#ifndef LED_BUILTIN
  #define LED_BUILTIN 2
#endif

// general
const int SERIAL_SPD = 115200;

// wifi
const char* str_SSID = "99 Problems but a Wifi ain't one";
const char* str_PASSWORD = "versefriet";

// domoticz
const String domoticz_username = "OTlwcm9ibGVtcw==";
const String domoticz_password = "Wnlla2o0VDQ2NFVScnJy";
const char* url = "https://domoticz.thomasw.nl/json.htm?type=command&param=udevice&idx=";
const int dht_idx = 74;
const int soil_idx = 76;
const int soil_perc_idx = 77;
const int lux_idx = 75;

// OTA 
const short VERSION = 1;

const char* OTA_SERVER = "ota.thomasw.nl"; // must be string for HttpClient
const unsigned short OTA_SERVER_PORT = 80;
const char* OTA_SERVER_PATH = "/gorilla/gorilla.ino.nodemcu.bin";
