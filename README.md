# Kit de Desarrollo IoT y Automatización (ESP32)

Este repositorio contiene el material didáctico, esquemas de hardware y códigos de ejemplo para la tarjeta de desarrollo basada en ESP32. Está diseñada específicamente para el aprendizaje de sistemas embebidos, automatización e Internet de las Cosas (IoT).

## 🚀 Características de la Tarjeta
* **Cerebro:** Microcontrolador ESP32 (NodeMCU, 30 pines) con conectividad Wi-Fi y Bluetooth.
* **Salidas de Potencia Aisladas:** 5 Relés controlados mediante optoacopladores PC817 para máxima seguridad del estudiante.
* **Monitoreo Visual:** LEDs indicadores de estado para cada relé.
* **Interfaz de Usuario:** Entradas para 4 pulsadores físicos y Buzzer para alertas sonoras.
* **Entradas de Sensores:** Bornes dedicados para sensores digitales/analógicos (DHT, Ultrasónico, Flujo).
* **Alimentación y Salidas Auxiliares:** Regulador Buck LM2596 integrado con salidas auxiliares protegidas de 12V y 5V.

<img width="3960" height="3467" alt="entradas_salidas kit automatización" src="https://github.com/user-attachments/assets/273603aa-0855-4e55-b014-67a76cc79f76" />

---

## 🗺️ Mapa de Pines (Pinout Oficial)

| Bloque en Imagen | Nombre en Código | Tipo de Señal | GPIO ESP32 |
| :--- | :--- | :--- | :--- |
| **RELÉS** | `RELAY_1` | Salida Digital | `GPIO 18` |
| **RELÉS** | `RELAY_2` | Salida Digital | `GPIO 5`  |
| **RELÉS** | `RELAY_3` | Salida Digital | `GPIO 17` |
| **RELÉS** | `RELAY_4` | Salida Digital | `GPIO 16` |
| **RELÉS** | `RELAY_5` | Salida Digital | `GPIO 4`  |
| **Entradas de Pulsadores** | `BUTTON_1` | Entrada Digital | `GPIO 36` |
| **Entradas de Pulsadores** | `BUTTON_2` | Entrada Digital | `GPIO 39` |
| **Entradas de Pulsadores** | `BUTTON_3` | Entrada Digital | `GPIO 34` |
| **Entradas de Pulsadores** | `BUTTON_4` | Entrada Digital | `GPIO 35` |
| **Entradas de Sensores** | `SENSOR_DIG_1` | Entrada Digital | `GPIO 33` |
| **Entradas de Sensores** | `SENSOR_DIG_2` | Entrada Digital | `GPIO 25` |
| **Entradas de Sensores** | `SENSOR_DIG_3` | Entrada Digital | `GPIO 27` |
| **Entradas de Sensores** | `SENSOR_ANALOG`| Entrada Analógica| `GPIO 32` |
| **Entradas de Sensores** | `SENSOR_EXTRA` | Entrada Digital | `GPIO 14` |
| **Actuadores 12V PWM** | `PWM_OUT_1` | Salida PWM | `GPIO 2`  |
| **Actuadores 12V PWM** | `PWM_OUT_2` | Salida PWM | `GPIO 15` |
| **Salida Display LCD I2C** | `BUS_SDA` / `SCL` | Bus I2C | `GPIO 21 / 22` |
| **Salida Auxiliar I2C** | `AUX_SDA` / `SCL` | Bus I2C | `GPIO 19 / 23` |
| **Interno** | `BUZZER` | Salida Digital | `GPIO 26` |
| **Entradas de Sensores** | `DIST_TRIG` | Salida Digital | `GPIO 12` |
| **Entradas de Sensores** | `DIST_ECHO` | Entrada Digital | `GPIO 13` |

<img width="2058" height="1749" alt="Copia de entradas_salidas" src="https://github.com/user-attachments/assets/66a89df3-e098-4758-8e9d-91df4791bdef" />

---

## 📚 Índice de Prácticas Didácticas

Las prácticas están organizadas de menor a mayor complejidad utilizando los nombres de variables genéricos de la tabla:

1. **`01_Test_Reles_Cascada`**: Secuencia básica para entender salidas digitales y el comportamiento de los relés.
2. **`02_Control_Manual_Pulsadores`**: Lectura de pulsadores en configuración Pull-Down y control de activación directa.
3. **`03_Termometro_Ambiental`**: Lectura del sensor DHT en entradas digitales y lógicas de control térmico.
4. **`04_Alarma_Nivel_Ultrasonico`**: Medición de distancia por ultrasonido y activación del Buzzer como alerta por proximidad.
5. **`05_Servidor_Web_IoT`**: Creación de un punto de acceso web local para conmutar los relés desde el teléfono móvil.

---

## 🛠️ Requisitos de Software y Configuración

### 1. Instalación de Controladores (Drivers)
Para que la computadora reconozca la tarjeta ESP32 a través del cable USB, es necesario instalar el driver del chip puente integrado en tu módulo (comúnmente CH340 o CP210X).
* 📥 [Descargar Driver CH340 (Sitio Oficial WCH)](https://wch-ic.com) -> *Común en NodeMCU económicos.*
* 📥 [Descargar Driver CP210x (Silicon Labs)](https://silabs.com) -> *Común en módulos DOIT.*

### 2. Configuración en Arduino IDE
1. Descarga e instala [Arduino IDE](https://arduino.cc).
2. Ve a **Archivo** > **Preferencias** y en el campo *Gestor de URLs Adicionales de Tarjetas* pega el siguiente enlace:
   `https://githubusercontent.com`
3. Ve a **Herramientas** > **Placa** > **Gestor de Tarjetas**, busca `esp32` e instálalo.
4. Selecciona la placa: **ESP32 Dev Module** (o NodeMCU-32S) antes de cargar tus códigos.

### 📚 3. Lista Oficial de Librerías y Sensores Compatibles
Los alumnos deben instalar estas librerías desde el *Gestor de Librerías* del IDE (Ctrl + Mayús + I) para habilitar los sensores del kit:

| Sensor / Actuador | Bornera en PCB | Librería Oficial Necesaria | Autor | Propósito |
| :--- | :--- | :--- | :--- | :--- |
| **Sensor de Clima** | `SENSOR_DIG_1 / 2` | **DHT sensor library** | Adafruit | Lectura de temperatura y humedad (DHT11/DHT22/AM2302) |
| **Sensor de Temperatura**| `SENSOR_DIG_3` | **DallasTemperature** | Miles Burton | Lectura de temperatura industrial (DS18B20) |
| **Sensor de Gases/Humo** | `SENSOR_ANALOG` | **MQUnifiedsensor** | Miguel Krumenacker| Calibración y lectura de PPM (MQ2, MQ135, etc.) |
| **Servomotores** | `PWM_OUT_1 / 2` | **ESP32Servo** | Kevin McGrath | Control preciso de posición de servos de 0° a 180° |
| **Pantalla de Texto** | `BUS_SDA / SCL` | **LiquidCrystal_I2C** | Frank de Brabander| Despliegue de datos en pantallas LCD 16x2 o 20x4 I2C |
