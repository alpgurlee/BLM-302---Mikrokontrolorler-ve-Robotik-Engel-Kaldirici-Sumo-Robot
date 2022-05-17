
// Kullanılacak sensörlerin pin tanımlamaları 
#define SolRenkSensor A0
#define SagRenkSensor A1

#define SolMotorHiz 3
#define SolMotorYon 12

#define SagMotorHiz 11
#define SagMotorYon 13

#define SagUzaklikSensor A2
#define OrtaUzaklikSensor A3
#define SolUzaklikSensor A4

int sag_uzaklik;
int orta_uzaklik;
int sol_uzaklik;

int sol_renk;
int sag_renk;




void setup(){

  pinMode(SolRenkSensor,INPUT);
  pinMode(SagRenkSensor,INPUT);

  pinMode(SagUzaklikSensor,INPUT);
  pinMode(OrtaUzaklikSensor,INPUT);
  pinMode(SolUzaklikSensor,INPUT);

  pinMode(SolMotorHiz,OUTPUT);
  pinMode(SolMotorYon,OUTPUT);

  pinMode(SagMotorHiz,OUTPUT);
  pinMode(SagMotorYon,OUTPUT);

  Serial.begin(9600);
  
  
}

void loop(){

  sol_renk = analogRead(SolRenkSensor);
  sag_renk = analogRead(SagRenkSensor);

  sag_uzaklik = digitalRead(SagUzaklikSensor);
  orta_uzaklik = digitalRead(OrtaUzaklikSensor);
  sol_uzaklik = digitalRead(SolUzaklikSensor);

  
  if(sol_renk > 300 && sag_renk > 300){  // eğer iki sensör de siyah rengi görürse rakip robotu ara
  
    if(orta_uzaklik == 1){  // merkezde bulunanan sensör rakip robotu algılarsa robot tam karşında 
    
       // rakibi sahadan atmak için rakibe doğru ilerle
    analogWrite(SagMotorHiz,250);
    digitalWrite(SagMotorYon,HIGH);
  
    analogWrite(SolMotorHiz,250);
    digitalWrite(SolMotorYon,HIGH); 
    delay(400);
    }
    
    else if(sol_uzaklik == 1){    // sol sensör rakibi ++ merkez sensör rakibi algılayana kadar sağ motor ++
    
    analogWrite(SolMotorHiz,0);
    digitalWrite(SolMotorYon,HIGH);

    analogWrite(SagMotorHiz,100);
    digitalWrite(SagMotorYon,HIGH); 
 
    delay(1); 
    }
    
    else if(sag_uzaklik == 1){     // sağ sensör rakibi ++ merkez sensör rakibi algılayana kadar sol motoru ++
    
      analogWrite(SolMotorHiz,100);
      digitalWrite(SolMotorYon,HIGH);
    
      analogWrite(SagMotorHiz,0);
      digitalWrite(SagMotorYon,HIGH);
      delay(10);
    
    }
    
    else{// hiçbir sensör rakibi algılamazsa rakibi bulmak için kendi etrafında dön
    
     analogWrite(SagMotorHiz,150);
     digitalWrite(SagMotorYon,HIGH);
  
     analogWrite(SolMotorHiz,150);
     digitalWrite(SolMotorYon,LOW);
     delayMicroseconds(100);
    
    }
  }
  
  else{  // eğer sensörlerden biri ve ikisi beyaz rengi görürse sahaya geri dönmeye çalış


  // Geri gel
     analogWrite(SagMotorHiz,150);
     digitalWrite(SagMotorYon,LOW);
  
     analogWrite(SolMotorHiz,150);
     digitalWrite(SolMotorYon,LOW);
    delay (756); // Ne kadar geri getirileceği denenip bekeleme süresi uygun olacak şekilde tekrar düzenlenebilir.
    
    // Geri getirip etrafında tekrar döndürdürüyoruz nedeni ise rakip araması
     analogWrite(SagMotorHiz,150);
     digitalWrite(SagMotorYon,LOW);
  
     analogWrite(SolMotorHiz,150);
     digitalWrite(SolMotorYon,HIGH);
    
    delayMicroseconds(50);
    
   
  
    
  
  }


}
