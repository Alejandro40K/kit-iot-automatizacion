/**
 * ====================================================================
 * KIT DIDÁCTICO DE HARDWARE - ESP32 AUTOMATIZACIÓN
 * PRÁCTICA 03: Termómetro Ambiental (DHT11 y Lógica Inversa)
 * ====================================================================
 */

#include "DHT.h"

// ==== CONFIGURACIÓN DE LÓGICA INVERSA ====
#define PRENDER_RELE LOW
#define APAGAR_RELE  HIGH

// ==== ASIGNACIÓN DE PINES ====
#define SENSOR_DIG_1 33  
#define RELAY_1      18  

#define DHTTYPE DHT11    
DHT dht(SENSOR_DIG_1, DHTTYPE);

const float CONTROL_TEMP = 28.5; 

void setup() {
  Serial.begin(115200);
  Serial.println("[PRÁCTICA 3] Inicializando protocolo DHT11...");
  dht.begin();
  
  pinMode(RELAY_1, OUTPUT);
  digitalWrite(RELAY_1, APAGAR_RELE); // Inicia apagado físico (HIGH)
}

void loop() {
  float hum = dht.readHumidity();
  float temp = dht.readTemperature();

  if (isnan(hum) || isnan(temp)) {
    Serial.println("Error Crítico: No se detectan señales del sensor DHT11.");
    delay(2000);
    return;
  }

  Serial.print("Muestreo -> Humedad: "); Serial.print(hum);
  Serial.print("% | Temperatura: "); Serial.print(temp); Serial.println("°C");

  // Control de ventilación automática con lógica inversa
  if (temp > CONTROL_TEMP) {
    digitalWrite(RELAY_1, PRENDER_RELE); // Enciende mandando un LOW
    Serial.println("[ESTADO] Temperatura excedida. RELAY_1 encendido.");
  } else {
    digitalWrite(RELAY_1, APAGAR_RELE);  // Apaga mandando un HIGH
  }

  delay(2000); 
}
