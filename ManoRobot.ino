#include <Servo.h>  // Arduino servo library

Servo servoIndice;  // servomotor motor dedo indice
Servo servoMedio; 
Servo servoAnular;
Servo servoMenique;
Servo servoPulgar;

const int ADC_pinIndice = A1;
const int ADC_pinMedio = A2;
const int ADC_pinAnular = A3;
const int ADC_pinMenique = A4;
const int ADC_pinPulgar = A5;

const float VCC = 5;      
const float fixed_resistor = 470000.0; 

void setup() {
  Serial.begin(9600);
  pinMode(ADC_pinIndice, INPUT);
  pinMode(ADC_pinMedio, INPUT);
  pinMode(ADC_pinAnular, INPUT);
  pinMode(ADC_pinMenique, INPUT);
  pinMode(ADC_pinPulgar, INPUT);

  servoIndice.attach(2);
  servoMedio.attach(3); 
  servoAnular.attach(4);
  servoMenique.attach(5);
  servoPulgar.attach(6);
}

void loop() {
  int flex_ADC_Indice = analogRead(ADC_pinIndice);
  int flex_ADC_Medio = analogRead(ADC_pinMedio);
  int flex_ADC_Anular = analogRead(ADC_pinAnular);
  int flex_ADC_Menique = analogRead(ADC_pinMenique);
  int flex_ADC_Pulgar = analogRead(ADC_pinPulgar);

  // float flex_resistance = (fixed_resistor * (VCC / flex_voltage - 1.0))/1000;
  float flex_voltage_Indice = flex_ADC_Indice * VCC / 1023.0;
  float flex_voltage_Medio = flex_ADC_Medio * VCC / 1023.0;
  float flex_voltage_Anular = flex_ADC_Anular * VCC / 1023.0;
  float flex_voltage_Menique = flex_ADC_Menique * VCC / 1023.0;
  float flex_voltage_Pulgar = flex_ADC_Pulgar * VCC / 1023.0;

  Serial.print("ADC_Indice value: ");
  Serial.print(flex_ADC_Indice);
  Serial.print("|| Voltage Indice value: ");
  Serial.println(flex_voltage_Indice);
  // Serial.println("Resistance value: " + String(flex_resistance) + " kilo-ohm");
  Serial.print("ADC Medio value: ");
  Serial.print(flex_ADC_Medio);
  Serial.print("|| Voltage Medio value: ");
  Serial.println(flex_voltage_Medio);

  Serial.print("ADC Anular value: ");
  Serial.print(flex_ADC_Medio);
  Serial.print("|| Voltage Anular value: ");
  Serial.println(flex_voltage_Anular);

  Serial.print("ADC Menique value: ");
  Serial.print(flex_ADC_Menique);
  Serial.print("|| Voltage Menique value: ");
  Serial.println(flex_voltage_Menique);

  Serial.print("ADC Pulgar value: ");
  Serial.print(flex_ADC_Pulgar);
  Serial.print("|| Voltage Pulgar value: ");
  Serial.println(flex_voltage_Pulgar);

  if (flex_ADC_Indice > 910) {
    servoIndice.write(0);
  }
  else if (flex_ADC_Indice >= 890 && flex_ADC_Indice <= 910) {
    servoIndice.write(90);
  }
  else if (flex_ADC_Indice < 890) {
    servoIndice.write(160);
  }

  if (flex_ADC_Medio > 910) {
    servoMedio.write(0);
  }
  else if (flex_ADC_Medio >= 890 && flex_ADC_Medio <= 910) {
    servoMedio.write(90);
  }
  else if (flex_ADC_Medio < 890) {
    servoMedio.write(160);
  }

  if (flex_ADC_Anular > 910) {
    servoAnular.write(0);
  }
  else if (flex_ADC_Anular >= 890 && flex_ADC_Anular <= 910) {
    servoAnular.write(90);
  }
  else if (flex_ADC_Anular < 890) {
    servoAnular.write(160);
  }

  if (flex_ADC_Menique > 910) {
    servoMenique.write(0);
  }
  else if (flex_ADC_Menique >= 890 && flex_ADC_Menique <= 910) {
    servoMenique.write(90);
  }
  else if (flex_ADC_Menique < 890) {
    servoMenique.write(160);
  }

  if (flex_ADC_Pulgar > 910) {
    servoPulgar.write(0);
  }
  else if (flex_ADC_Pulgar >= 890 && flex_ADC_Pulgar <= 910) {
    servoPulgar.write(90);
  }
  else if (flex_ADC_Pulgar < 890) {
    servoPulgar.write(160);
  }

  Serial.println();
  delay(500);

}
