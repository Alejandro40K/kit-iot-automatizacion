/**
 * ====================================================================
 * KIT DIDÁCTICO DE HARDWARE - ESP32 AUTOMATIZACIÓN
 * PRÁCTICA 04: Alarma de Nivel Ultrasónico (Medición de Distancia)
 * ====================================================================
 */

// ==== ASIGNACIÓN DE PINES ====
#define DIST_TRIG 12
#define DIST_ECHO 13
#define BUZZER    26 // El buzzer se activa con HIGH de forma estándar

const float UMBRAL_DISTANCIA = 12.0; 

void setup() {
  Serial.begin(115200);
  pinMode(DIST_TRIG, OUTPUT);
  pinMode(DIST_ECHO, INPUT);
  pinMode(BUZZER, OUTPUT);
  
  digitalWrite(DIST_TRIG, LOW);
  digitalWrite(BUZZER, LOW); // Apagado inicial
  Serial.println("[PRÁCTICA 4] Sensor ultrasónico activo...");
}

void loop() {
  digitalWrite(DIST_TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(DIST_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(DIST_TRIG, LOW);

  long microsegundos = pulseIn(DIST_ECHO, HIGH);
  float cm = microsegundos * 0.0343 / 2.0;

  if (cm > 0 && cm < 400) { 
    Serial.print("Nivel de proximidad: "); Serial.print(cm); Serial.println(" cm");

    if (cm < UMBRAL_DISTANCIA) {
      Serial.println("[ALERTA DE PROXIMIDAD] Objeto detectado.");
      digitalWrite(BUZZER, HIGH); // Enciende con HIGH
      delay(100);
      digitalWrite(BUZZER, LOW);
      delay(100);
    }
  }
  delay(150);
}
