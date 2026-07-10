/***********************************************************************
 Project: ESP32 Ultrasonic Sensor with UART Communication

 Description:
 Measures distance using an HC-SR04 ultrasonic sensor connected to an
 ESP32 and communicates detection events to a PIC microcontroller via
 UART.

 Technologies:
 - ESP32
 - Arduino C++
 - UART
 - Embedded Systems
************************************************************************/

#define TRIG_PIN 5
#define ECHO_PIN 18
#define RXD2 16  // Conectado a TX de la PIC
#define TXD2 17  // Conectado al divisor que llega a RX de la PIC

void setup() {
  Serial.begin(115200);
  Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  // Medir distancia
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH, 30000);
  float distance = duration * 0.0343 / 2;

  Serial.print("Distancia: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance < 50 && distance > 2) {
    Serial2.write('1');
    Serial.println("Enviado: 1");
  } else if (distance < 400) {
    Serial2.write('0');
    Serial.println("Enviado: 0");
  }

  if (Serial2.available()) {
    char respuesta = Serial2.read();
    Serial.print("Respuesta PIC: ");
    Serial.println(respuesta);
  }

  delay(1000);
}
