# Kit de Desarrollo IoT y Automatización (ESP32)

Este repositorio contiene el material didáctico, esquemas de hardware y códigos de ejemplo para la tarjeta de desarrollo basada en ESP32, diseñada específicamente para el aprendizaje de sistemas embebidos, automatización e Internet de las Cosas (IoT) en bachillerato técnico.

## 🚀 Características de la Tarjeta
* **Cerebro:** Microcontrolador ESP32 (NodeMCU) con conectividad Wi-Fi y Bluetooth.
* **Salidas de Potencia Aisladas:** 5 Relés controlados mediante optoacopladores PC817 para máxima seguridad del estudiante.
* **Monitoreo Visual:** LEDs indicadores de estado para cada relé.
* **Interfaz de Usuario:** Botonera física integrada (4 botones) y Buzzer para alertas sonoras.
* **Entradas de Sensores:** Bornes dedicados para sensores digitales/analógicos (DHT, Ultrasónico, Flujo).
* **Alimentación Segura:** Regulador Buck LM2596 integrado (Entrada de 12V, salida regulada).

---

## 🗺️ Mapa de Pines (Pinout)

| Componente | Tipo de Señal | GPIO ESP32 | Descripción |
| :--- | :--- | :--- | :--- |
| **RELE 1** | Salida Digital | `GPIO 23` | Extractor de aire |
| **RELE 2** | Salida Digital | `GPIO 25` | Resistencia de Calor 1 |
| **RELE 3** | Salida Digital | `GPIO 26` | Resistencia de Calor 2 |
| **RELE 4** | Salida Digital | `GPIO 27` | Humidificador |
| **RELE 5** | Salida Digital | `GPIO 14` | Ventilador Calefactor |
| **BUZZER** | Salida Digital | `GPIO 4` | Alertas sonoras |
| **BTN_SELECT**| Entrada Digital | `GPIO 19` | Botón de selección |
| **BTN_UP** | Entrada Digital | `GPIO 18` | Botón Arriba |
| **BTN_DOWN** | Entrada Digital | `GPIO 5` | Botón Abajo |
| **BTN_BACK** | Entrada Digital | `GPIO 17` | Botón Atrás |
| **DHT_PIN_A** | Entrada Digital | `GPIO 32` | Sensor de Temp/Humedad A |
| **TRIG_PIN** | Salida Digital | `GPIO 12` | Trigger - Ultrasónico |
| **ECHO_PIN** | Entrada Digital | `GPIO 13` | Echo - Ultrasónico |
| **S_FLUJO** | Entrada Digital | `GPIO 35` | Sensor de Flujo de Agua |

---

## 📚 Índice de Prácticas Didácticas

Las prácticas están organizadas de menor a mayor complejidad:

1. **`01_Test_Reles_Cascada`**: Secuencia básica para entender salidas digitales y el clic de los relés.
2. **`02_Termometro_Ambiental`**: Lectura del sensor DHT y lógica de control por temperatura.
3. **`03_Nivel_Ultrasonico`**: Medición de distancia y activación del Buzzer como alarma de nivel.
4. **`04_Menu_Botonera`**: Lógica de navegación en pantalla/terminal usando los 4 botones físicos.
5. **`05_Servidor_Web_IoT`**: Control de los relés de forma inalámbrica desde el teléfono celular.

---

## 🛠️ Requisitos de Software
1. Descargar e instalar [Arduino IDE](https://arduino.cc).
2. Agregar el soporte para tarjetas ESP32 en el Gestor de Tarjetas.
3. Instalar las siguientes librerías desde el Gestor de Librerías:
   * *DHT sensor library* (Adafruit)
   * *ESP32Servo* (Si se usan los bornes auxiliares)
