/**
 * ====================================================================
 * KIT DIDÁCTICO DE HARDWARE - ESP32 AUTOMATIZACIÓN
 * PRÁCTICA 05: Servidor Web IoT (Control Inalámbrico Invertido)
 * ====================================================================
 */

#include <WiFi.h>

// ==== CONFIGURACIÓN DE LÓGICA INVERSA ====
#define PRENDER_RELE LOW
#define APAGAR_RELE  HIGH

// ==== ASIGNACIÓN DE PINES REALES ====
#define RELAY_1 18

const char* ssid_RED = "ESCRIBE_AQUI_EL_SSID";
const char* pass_RED = "ESCRIBE_AQUI_EL_PASSWORD";

WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  pinMode(RELAY_1, OUTPUT);
  digitalWrite(RELAY_1, APAGAR_RELE); // Inicia apagado físico (HIGH)

  WiFi.begin(ssid_RED, pass_RED);
  Serial.print("Conectando al ruteador local");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("\nConexión inalámbrica establecida.");
  Serial.print("IP oficial de la PCB: ");
  Serial.println(WiFi.localIP()); 
  
  server.begin();
}

void loop() {
  WiFiClient cliente = server.available(); 
  if (!cliente) return;

  String peticion = cliente.readStringUntil('\r');
  cliente.flush();

  // Mapear comandos de la web hacia la lógica inversa física
  if (peticion.indexOf("/ACTIVAR_R1") != -1)  digitalWrite(RELAY_1, PRENDER_RELE);  // Manda LOW
  if (peticion.indexOf("/DESACTIVAR_R1") != -1) digitalWrite(RELAY_1, APAGAR_RELE); // Manda HIGH

  cliente.println("HTTP/1.1 200 OK");
  cliente.println("Content-Type: text/html");
  cliente.println("Connection: close");
  cliente.println();
  cliente.println("<!DOCTYPE html><html>");
  cliente.println("<head><meta name='viewport' content='width=device-width, initial-scale=1'><meta charset='utf-8'>");
  cliente.println("<style>body{text-align:center; font-family:Arial; margin-top:50px;} .btn{padding:15px 35px; font-size:18px; margin:10px; color:white; border:none; border-radius:5px; cursor:pointer;} .on{background-color:#4CAF50;} .off{background-color:#f44336;}</style></head>");
  cliente.println("<body>");
  cliente.println("<h1>Consola IoT de Control</h1>");
  cliente.println("<p><a href='/ACTIVAR_R1'><button class='btn on'>ENCENDER RELÉ 1</button></a></p>");
  cliente.println("<p><a href='/DESACTIVAR_R1'><button class='btn off'>APAGAR RELÉ 1</button></a></p>");
  cliente.println("</body></html>");
  
  delay(1);
}
