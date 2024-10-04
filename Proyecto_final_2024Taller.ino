#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <Servo.h>
#define sensor 2
#define sw1 3
#define sw2 4
#define sw3 5
#define sw4 6
#define l1 A0
#define l2 A1
#define l3 A2
#define l4 A3
#define l5 A6
#define buzz 13
#define trigger 8
#define echo 7
#define time delay(2000);
#define time2 delay(1000);
#define time3 delay(3000);
#define time4 delay(100);

int a = 0;
int b = 0;
int c = 0;
long sensor_us;
long distancia;

Servo servo;
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  pinMode(sw1, INPUT);
  pinMode(sw2, INPUT);
  pinMode(sw3, INPUT);
  pinMode(sw4, INPUT);
  pinMode(l1, OUTPUT);
  pinMode(l2, OUTPUT);
  pinMode(l3, OUTPUT);
  pinMode(l4, OUTPUT);
  pinMode(l5, OUTPUT);
  pinMode(sensor, INPUT);
  pinMode(buzz, OUTPUT);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  digitalWrite(trigger, LOW);
  servo.attach(9);
  servo.write(90);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(2, 0);
  lcd.print("Comida para");
  lcd.setCursor(3, 1);
  lcd.print("mascotas");
  time
  // put your setup code here, to run once:

}

void loop() {
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  sensor_us = pulseIn(echo, HIGH);
  time4
  distancia = sensor_us/59;
  Serial.println(distancia);
  Serial.print("cm");

  if(b == 0){
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("Elija el modo");
  lcd.setCursor(1, 1);
  lcd.print(">Manual   Autom.");
  b = 1;
  a = 0;
  }

  if(digitalRead(sw1)== LOW){
  b = 0;
  }

  if(digitalRead(sw3)==HIGH && a == 0){
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("Eligio el modo");
    lcd.setCursor(5, 1);
    lcd.print("manual");
    time
    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print("Presione el");
    lcd.setCursor(2, 1);
    lcd.print("Boton (Abrir)");
  }
  if(digitalRead(sw2)== HIGH && a == 0){
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("Sirviendo.");
    time2
    lcd.setCursor(2, 0);
    lcd.print("Sirviendo..");
    time2
    lcd.setCursor(2, 0);
    lcd.print("Sirviendo...");
    servo.write(90);
    time
    servo.write(0);
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("Operacion con");
    lcd.setCursor(5, 1);
    lcd.print("exito");
    time
    b = 0;
  }

    if(digitalRead(sw4)==HIGH){
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("Elija el modo");
  lcd.setCursor(1, 1);
  lcd.print(" Manual  >Autom.");
  a = 1;
  }
  if(digitalRead(sw3)==HIGH && a == 1){
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("Eligio el modo");
    lcd.setCursor(3, 1);
    lcd.print("automatico");
    a = 3;
    time
  }
  if(a == 3){
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("Esperando...");
    lcd.setCursor(1, 1);
    lcd.print("Salir (Volver)");
    time4
    }
  if(digitalRead(sensor)== LOW && a == 3){
      lcd.clear();
      lcd.setCursor(2, 0);
      lcd.print("Sirviendo.");
      time2
      lcd.setCursor(2, 0);
      lcd.print("Sirviendo..");
      time2
      lcd.setCursor(2, 0);
      lcd.print("Sirviendo...");
      servo.write(90);
      time
      servo.write(0);
      lcd.clear();
      lcd.setCursor(2, 0);
      lcd.print("Operacion con");
      lcd.setCursor(5, 1);
      lcd.print("exito");
      time
    }
    if(digitalRead(sw3)==HIGH && a == 3){
            lcd.clear();
            lcd.setCursor(3, 0);
            lcd.print("Automatico");
            lcd.setCursor(2, 1);
            lcd.print("desactivado");
            b = 0;
            time
           }
    

  if(distancia >11 && distancia <15){
    digitalWrite(l1, HIGH);
    digitalWrite(l2, HIGH);
    digitalWrite(l3, HIGH);
    digitalWrite(l4, HIGH);
    digitalWrite(l5, HIGH);
  }

  if(distancia >14 && distancia <18){
    digitalWrite(l1, HIGH);
    digitalWrite(l2, HIGH);
    digitalWrite(l3, HIGH);
    digitalWrite(l4, HIGH);
    digitalWrite(l5, LOW);
  }

  if(distancia >17 && distancia <21){
    digitalWrite(l1, HIGH);
    digitalWrite(l2, HIGH);
    digitalWrite(l3, HIGH);
    digitalWrite(l4, LOW);
    digitalWrite(l5, LOW);
  }

  if(distancia >20 && distancia <24 && c == 0){
    digitalWrite(l1, HIGH);
    digitalWrite(l2, HIGH);
    digitalWrite(l3, LOW);
    digitalWrite(l4, LOW);
    digitalWrite(l5, LOW);
    tone(buzz, 400, 1000);
    time2
    noTone(buzz);
    c = 1;
  }

  if(distancia >23 && c == 1){
    digitalWrite(l1, HIGH);
    digitalWrite(l2, LOW);
    digitalWrite(l3, LOW);
    digitalWrite(l4, LOW);
    digitalWrite(l5, LOW);
      tone(buzz, 400, 1000);
    time2
    noTone(buzz);
    c = 2;
  }
  // put your main code here, to run repeatedly:

}
