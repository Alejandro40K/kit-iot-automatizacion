/**
 * ====================================================================
 * KIT DIDÁCTICO DE HARDWARE - ESP32 AUTOMATIZACIÓN
 * PRÁCTICA 01: Test de Salidas (Relés en Cascada con Lógica Inversa)
 * ====================================================================
 */

// ==== CONFIGURACIÓN DE LÓGICA INVERSA ====
#define PRENDER_RELE LOW  
#define APAGAR_RELE  HIGH 

// ==== ASIGNACIÓN DE PINES ====
#define RELAY_1 18
#define RELAY_2 5
#define RELAY_3 17
#define RELAY_4 16
#define RELAY_5 4

void setup() {
  Serial.begin(115200);
  Serial.println("[PRÁCTICA 1] Iniciando prueba de salidas...");

  pinMode(RELAY_1, OUTPUT);
  pinMode(RELAY_2, OUTPUT);
  pinMode(RELAY_3, OUTPUT);
  pinMode(RELAY_4, OUTPUT);
  pinMode(RELAY_5, OUTPUT);

  // Apagado físico inicial
  digitalWrite(RELAY_1, APAGAR_RELE);
  digitalWrite(RELAY_2, APAGAR_RELE);
  digitalWrite(RELAY_3, APAGAR_RELE);
  digitalWrite(RELAY_4, APAGAR_RELE);
  digitalWrite(RELAY_5, APAGAR_RELE);
}

void loop() {
  Serial.println("-> Encendido en cascada acumulativa (LOW)...");
  digitalWrite(RELAY_1, PRENDER_RELE); delay(400);
  digitalWrite(RELAY_2, PRENDER_RELE); delay(400);
  digitalWrite(RELAY_3, PRENDER_RELE); delay(400);
  digitalWrite(RELAY_4, PRENDER_RELE); delay(400);
  digitalWrite(RELAY_5, PRENDER_RELE); delay(1500); 

  Serial.println("-> Desactivación simultánea de potencia (HIGH)...");
  digitalWrite(RELAY_1, APAGAR_RELE);
  digitalWrite(RELAY_2, APAGAR_RELE);
  digitalWrite(RELAY_3, APAGAR_RELE);
  digitalWrite(RELAY_4, APAGAR_RELE);
  digitalWrite(RELAY_5, APAGAR_RELE);
  
  delay(2000); 
}
