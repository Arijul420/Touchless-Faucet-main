#include<LiquidCrystal.h>#include<Servo.h>LiquidCrystallcd(13,12,11,10,9,8);LiquidCrystallcd2(30,29,28,27,26,25);#definetrig7#defineecho6#definetrig222#defineecho223Servoservo;intpos=0;constintsensor=3;constintRelay=5;intstate;intvalue;longduration;intdistance;longduration2;intwaterdistance;intcount=0;intledpin=2;intled1=51;intled2=52;intled3=53;constintbuzzer=24;voidsetup(){lcd.begin(16,2);lcd.setCursor(0,0);lcd.print("Washyourhands");lcd.setCursor(0,1);lcd.print("beforeyouenter");lcd2.begin(16,2);lcd2.setCursor(0,0);lcd2.print("No.ofpeopleentered");lcd2.setCursor(0,1);lcd2.print("0");servo.attach(4);pinMode(trig,OUTPUT);pinMode(echo,INPUT);pinMode(trig2,OUTPUT);pinMode(echo2,INPUT);pinMode(sensor,INPUT);pinMode(Relay,OUTPUT);pinMode(ledpin,OUTPUT);pinMode(led1,OUTPUT);pinMode(led2,OUTPUT);pinMode(led3,OUTPUT);pinMode(buzzer,OUTPUT);}voidloop(){digitalWrite(trig,LOW);delayMicroseconds(5);digitalWrite(trig,HIGH);delayMicroseconds(10);digitalWrite(trig,LOW);duration=pulseIn(echo,HIGH);distance=(duration/2)*(331.3/10000);value=digitalRead(sensor);digitalWrite(trig2,LOW);delayMicroseconds(5);digitalWrite(trig2,HIGH);delayMicroseconds(10);digitalWrite(trig2,LOW);duration2=pulseIn(echo2,HIGH);waterdistance=(duration2/2)*(331.3/10000);if(waterdistance>30){if(waterdistance>30&&waterdistance<=100){digitalWrite(led1,LOW);digitalWrite(led2,LOW);digitalWrite(led3,HIGH);}if(waterdistance>100&&waterdistance<=200){digitalWrite(led1,LOW);digitalWrite(led2,HIGH);digitalWrite(led3,HIGH);}if(waterdistance>=200){digitalWrite(led1,HIGH);digitalWrite(led2,HIGH);digitalWrite(led3,HIGH);}if(distance>1&&distance<15){lcd.clear();lcd.setCursor(1,0);lcd.print("Handsdetected");lcd.setCursor(0,1);lcd.print("Washhands-20s");digitalWrite(Relay,HIGH);digitalWrite(ledpin,HIGH);state=1;delay(1000);lcd.clear();lcd.print("Youaresafenow");noTone(buzzer);}else{digitalWrite(Relay,LOW);digitalWrite(ledpin,LOW);tone(buzzer,1000);}}else{digitalWrite(Relay,LOW);digitalWrite(ledpin,LOW);state=0;lcd.clear();digitalWrite(led1,LOW);digitalWrite(led2,LOW);digitalWrite(led3,LOW);lcd.print("SanitizerFinshed");}if((state==1)&&(value==LOW)){lcd.clear();lcd.setCursor(1,0);lcd.print("Youmaygoin");lcd.setCursor(1,1);lcd.print("10secondsleft");for(pos=0;pos<=90;pos=pos+1){servo.write(pos);delay(20);}delay(10000);for(pos=90;pos>=0;pos=pos-1){servo.write(pos);delay(20);}count++;lcd2.clear();lcd2.setCursor(1,0);lcd2.print("No.ofpeople:");lcd2.setCursor(1,1);lcd2.print(count);lcd.clear();lcd.print("Washyourhands");lcd.setCursor(0,1);lcd.print("beforeyouenter");state=0;noTone(buzzer);}elseif((state==0)&&(value==LOW)){lcd.clear();lcd.print("Washyourhands");lcd.setCursor(0,1);lcd.print("tograntaccess");tone(buzzer,1000);}}