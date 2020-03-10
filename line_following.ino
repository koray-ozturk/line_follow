
const int in1 = 7;
const int in2 = 6;   
const int in3 = 5;
const int in4 = 4;
const int ena = 10;
const int enb = 11;

const int pinIRd = 8;
const int pinIRa = A1;
const int pinLED = 13;
int IRvalueA = 0;
int IRvalueD = 0;


const int pinIRd2 = 12;
const int pinIRa2 = A0;

int IRvalueA2 = 0;
int IRvalueD2 = 0;

void setup(){

pinMode(in1, OUTPUT);  //Tüm pinlerden güç çıkışı olacağı için OUTPUT olarak ayarladık.
pinMode(in2, OUTPUT);  
pinMode(in3, OUTPUT);
pinMode(in4, OUTPUT);
pinMode(ena, OUTPUT);
pinMode(enb, OUTPUT);
pinMode(pinIRd,INPUT);
pinMode(pinIRa,INPUT);
pinMode(pinIRd2,INPUT);
pinMode(pinIRa2,INPUT);
pinMode(pinLED,OUTPUT);

Serial.begin(9600); /* Seri haberlesme baslatildi */
}
void loop()
{
analogWrite(ena,75);
analogWrite(enb,75);
IRvalueA2 = analogRead(pinIRa2);
IRvalueD2 = digitalRead(pinIRd2);
IRvalueA = analogRead(pinIRa);
IRvalueD = digitalRead(pinIRd);
//////////ileri
  if(IRvalueA>100&&IRvalueD==1&&IRvalueA2>100&&IRvalueD2==1){

     digitalWrite(in1, HIGH);
     digitalWrite(in2,  LOW);  
     digitalWrite(in3, HIGH);
     digitalWrite(in4,  LOW);
    }
//////////////sol
  if(IRvalueA<100&&IRvalueD==0&&IRvalueA2>100&&IRvalueD2==1){

     digitalWrite(in1, LOW);
     digitalWrite(in2,  HIGH);  
     digitalWrite(in3, HIGH);
     digitalWrite(in4,  LOW);
    }
//////sağ
if(IRvalueA>100&&IRvalueD==1&&IRvalueA2<100&&IRvalueD2==0){
     digitalWrite(in1, HIGH);
     digitalWrite(in2,  LOW);  
     digitalWrite(in3, LOW);
     digitalWrite(in4,  HIGH);
    }
   
}
