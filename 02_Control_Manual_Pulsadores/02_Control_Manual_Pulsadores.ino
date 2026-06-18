/**
 * ====================================================================
 * KIT DIDÁCTICO DE HARDWARE - ESP32 AUTOMATIZACIÓN
 * PRÁCTICA 02: Control Manual (Lógica Inversa en Relés)
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

#define BUTTON_1 36
#define BUTTON_2 39
#define BUTTON_3 34
#define BUTTON_4 35

void setup() {
  Serial.begin(115200);
  Serial.println("[PRÁCTICA 2] Modo manual activo. Leyendo pulsadores...");
  
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

  pinMode(BUTTON_1, INPUT);
  pinMode(BUTTON_2, INPUT);
  pinMode(BUTTON_3, INPUT);
  pinMode(BUTTON_4, INPUT);
}

void loop() {
  // RELÉ 1: Si pulsador está HIGH (presionado), manda un LOW (prende el relé)
  if (digitalRead(BUTTON_1) == HIGH) {
    digitalWrite(RELAY_1, PRENDER_RELE);
  } else {
    digitalWrite(RELAY_1, APAGAR_RELE);
  }

  // RELÉ 2
  if (digitalRead(BUTTON_2) == HIGH) {
    digitalWrite(RELAY_2, PRENDER_RELE);
  } else {
    digitalWrite(RELAY_2, APAGAR_RELE);
  }

  // RELÉ 3
  if (digitalRead(BUTTON_3) == HIGH) {
    digitalWrite(RELAY_3, PRENDER_RELE);
  } else {
    digitalWrite(RELAY_3, APAGAR_RELE);
  }

  // RELÉ 4
  if (digitalRead(BUTTON_4) == HIGH) {
    digitalWrite(RELAY_4, PRENDER_RELE);
  } else {
    digitalWrite(RELAY_4, APAGAR_RELE);
  }
  
  delay(50); 
}
