
// Kullanılacak sensörlerin pin tanımlamaları 
#define SolRenkSensor A0
#define SagRenkSensor A1

#define SolMotorHiz 3
#define SolMotorYon 12

#define SagMotorHiz 11
#define SagMotorYon 13

int sol_renk;
int sag_renk;



// zemin bitleri değiştirelebilir
void setup(){

  pinMode(SolRenkSensor,INPUT);
  pinMode(SagRenkSensor,INPUT);

  pinMode(SolMotorHiz,OUTPUT);
  pinMode(SolMotorYon,OUTPUT);

  pinMode(SagMotorHiz,OUTPUT);
  pinMode(SagMotorYon,OUTPUT);

  Serial.begin(9600);
  
  
}

void loop(){

    sol_renk = analogRead(SolRenkSensor);
    sag_renk = analogRead(SagRenkSensor);
  
    if(analogRead(sol_renk) >= 220  && analogRead(sag_renk  )>= 220 ){ // İki sensörde beyaz renki zemin okuyor ileri yönde ++
  
          analogWrite(SolMotorHiz,150);
          digitalWrite(SolMotorYon,HIGH);
          analogWrite(SagMotorHiz,150);
          digitalWrite(SagMotorYon,HIGH); 
  
      }
    else if(analogRead(sol_renk)<=220  && analogRead(sag_renk  )>= 220 ){// Sol sensör Siyay renki çizgiyi okursa eğer saga dön
  
          analogWrite(SolMotorHiz,100);
          digitalWrite(SolMotorYon,HIGH);
          analogWrite(SagMotorHiz,0);
          digitalWrite(SagMotorYon,HIGH); 
      }
    else if(analogRead(sol_renk)>= 220&& analogRead(sag_renk  )<=220 ){// Sag sensör Siyah renki çizgiyi okursa eğer sola dön

          analogWrite(SolMotorHiz,0);
          digitalWrite(SolMotorYon,HIGH);
          analogWrite(SagMotorHiz,100);
          digitalWrite(SagMotorYon,HIGH);       
      } 
  
    
  
}
