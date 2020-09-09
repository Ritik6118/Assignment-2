#include <IRremote.h>
#define Button_0 0xFD30CF
#define Button_1 0xFD08F7
#define Button_2 0xFD8877
#define Button_3 0xFD48B7
#define Button_4 0xFD28D7
#define Button_5 0xFDA857
#define Button_6 0xFD6897
#define Button_7 0xFD18E7
#define Button_8 0xFD9867
#define Button_9 0xFD58A7
int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
 
  Serial.println("Enabling IRin");
  irrecv.enableIRIn();
  Serial.println("Enabled IRin");
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume();
    pinMode(2,OUTPUT);
    pinMode(3,OUTPUT);
    pinMode(4,OUTPUT);
    pinMode(5,OUTPUT);
  }
  delay(100);
  switch(results.value)
  {
    case Button_1: digitalWrite(2,HIGH);
      delay(50);
      digitalWrite(2,LOW); break;
    case Button_2: digitalWrite(3,HIGH);
      delay(50);
      digitalWrite(3,LOW); break;
    case Button_3: digitalWrite(4,HIGH);
      delay(50);
      digitalWrite(4,LOW); break;
    case Button_4: digitalWrite(2,LOW); break;
    case Button_5: digitalWrite(3,LOW); break;
    case Button_6: digitalWrite(4,LOW); break;
    case Button_7: digitalWrite(2,HIGH);
                   delay(50);
                   digitalWrite(2,LOW);
                   digitalWrite(3,HIGH);
                   delay(50);
                   digitalWrite(3,LOW);
                   digitalWrite(4,HIGH);
                   delay(50);
                   digitalWrite(4,LOW);
    break;
    case Button_8: digitalWrite(2,LOW);
                   digitalWrite(3,LOW);
                   digitalWrite(4,LOW); 
    break;
    case Button_0: digitalWrite(5,LOW);      
    break;
    case Button_9: digitalWrite(5,HIGH);
    break;
  }
}
