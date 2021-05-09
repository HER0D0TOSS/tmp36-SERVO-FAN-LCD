#include <Servo.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(4,5,6,7,8,9);

int dht_pin =A0;
int motor_pin = A1;
int ldr_pin = A2;
Servo servo_pin;

float LDR;
int sensor;
double sicaklik;
float deger;

void setup() {
  
  pinMode(dht_pin,INPUT);
  pinMode(ldr_pin,INPUT);
  pinMode(motor_pin,OUTPUT);
  
  lcd.begin(16, 2);
  Serial.begin(9600);
  servo_pin.attach(10);
}
void loop() {
  lcd.clear();
  sensor =analogRead(dht_pin);
  
  LDR = analogRead(ldr_pin);
  
  sicaklik = (double)sensor/ 1024;       
  sicaklik = sicaklik * 5;                 
  sicaklik = sicaklik - 0.5;               
  sicaklik = sicaklik * 100;
  
  if(sicaklik<25)
  {
    Fan_dur();
  	
   
    lcd.setCursor(0, 0);
    lcd.print("Fan: Deaktif ");
    
    lcd.setCursor(2, 1);
  	lcd.setCursor(0, 1);
  	lcd.print("Sicaklik: ");
  	lcd.print(sicaklik);
  	lcd.print("c");
  	
  }
  else if(sicaklik>=25)
  {
    Fan_calis();
    
 
    lcd.setCursor(0, 0);
    lcd.print("Fan: Aktif ");
    
    lcd.setCursor(2, 1);
  	lcd.setCursor(0, 1);
  	lcd.print("Sicaklik: ");
  	lcd.print(sicaklik);
  	lcd.print("c");
  
  }
  
  if (LDR <100){
      Servo_aktif();
  }
  else if (LDR>100){
      Servo_deaktif();
  }
  
  delay(1000);
}
void Fan_calis(){
  analogWrite(motor_pin, 1023);
}
void Fan_dur(){
    analogWrite(motor_pin, 0);
}
  
  
void Servo_aktif(){
	servo_pin.write(0);
}


void Servo_deaktif(){
    for(int i=0;i<=180;i++)
    {     
      servo_pin.write(i);
    }
}