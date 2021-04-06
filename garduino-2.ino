#include "utils.h"
#include "config.h"
#include "sensors.h"
#include "connection.h"

#define BOARD_IDENTIFY_WARNING

void setup() {
  Serial.begin(SERIAL_SPD);
  setup_sensors();
  setup_connection(str_SSID, str_PASSWORD);
  #if defined (LED_BUILTIN)
    pinMode(LED_BUILTIN, OUTPUT);
  #endif
}

void loop() {
  // Temp + Humidity
  float hum, temp;
  HUM_STAT hum_stat = HUM_NORMAL;
  get_dht_sensor_value(hum, temp, hum_stat);
  https_get(String(url) + String(dht_idx) + String("&nvalue=0&svalue=") + String(temp) + String(";") + String(hum) + String(";") + String(hum_stat));
  
  // Soil
  int soil_hum, cb;
  get_soil_hum_sensor_value(soil_hum, cb);
  https_get(String(url) + String(soil_idx) + String("&nvalue=") + String(cb));
  https_get(String(url) + String(soil_perc_idx) + String("&nvalue=0&svalue=") + String(soil_hum));
  
  // Light Sensitivity
  float lux;
  get_lux_sensor_value(lux);
  https_get(String(url) + String(lux_idx) + String("&svalue=") + String(lux));

  ota_update(); // check for updates
  blink(); // blink when done
  delay(1000 * 60 * 10); // 10 minuten
}
