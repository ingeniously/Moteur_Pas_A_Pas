int IN1 = 8; // pin digital 8 relié à IN1
int IN2 = 9; // pin digital 9 à IN2
int IN3 = 10; // pin digital 10 à IN3
int IN4 = 11; // pin digital 11 à IN4
int temps = 20; // temps entre les pas, minimun 20 ms.

int b=0;
int l=0;
int d=0;
int k=0;
void setup(){
  Serial.begin(9600);
  // tous les pins se configurent comme sorties
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
   
}

void  pas_complet_monophase(){
  while (l==1)
  {
  Serial.println(" pas_complet_monophase");
  // Array bidimensionnel avec la séquence des pas
int Full_Step_1 [4][4] = {
  {1, 0, 0, 0},
  {0, 1, 0, 0},
  {0, 0, 1, 0},
  {0, 0, 0, 1}
  };
  // 512*4 = 2048 pas

       for (int i = 0; i < 512; i++){
    for (int s = 0; s < 4; s++){
      // valeurs que nous allons appliquer
      digitalWrite(IN1, Full_Step_1[s][0]);
      digitalWrite(IN2, Full_Step_1[s][1]);
      digitalWrite(IN3, Full_Step_1[s][2]);
      digitalWrite(IN4, Full_Step_1[s][3]);
      delay(temps);
    }                       
   
    }
    
  // pause de 5 secondes
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delay(1000);
  
       for (int i = 0; i < 512; i++){
    for (int s = 3; s >=0; s--){
      // valeurs que nous allons appliquer
      digitalWrite(IN1, Full_Step_1[s][0]);
      digitalWrite(IN2, Full_Step_1[s][1]);
      digitalWrite(IN3, Full_Step_1[s][2]);
      digitalWrite(IN4, Full_Step_1[s][3]);
      delay(temps);
                               }
    }
  
 
}
}

void  pas_complet_biphase(){
  Serial.println("pas_complet_biphase");
  while(b==1)
  {
  // Array bidimensionnel avec la séquence des pas
int Full_Step_2 [4][4] = {
  {1, 1, 0, 0},
  {0, 1, 1, 0},
  {0, 0, 1, 1},
  {1, 0, 0, 1}
  };
  // 512*4 = 2048 pas

    
       for (int i = 0; i < 512; i++){
    for (int s = 0; s < 4; s++){
      // valeurs que nous allons appliquer
      digitalWrite(IN1, Full_Step_2[s][0]);
      digitalWrite(IN2, Full_Step_2[s][1]);
      digitalWrite(IN3, Full_Step_2[s][2]);
      digitalWrite(IN4, Full_Step_2[s][3]);
      delay(temps);
    }
    }

      // pause de 5 secondes
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delay(1000);
   
       for (int i = 0; i < 512; i++){
    for (int s = 3; s >=0; s--){
      // valeurs que nous allons appliquer
      digitalWrite(IN1, Full_Step_2[s][0]);
      digitalWrite(IN2, Full_Step_2[s][1]);
      digitalWrite(IN3, Full_Step_2[s][2]);
      digitalWrite(IN4, Full_Step_2[s][3]);
      delay(temps);
                               }
    } 
  
 
}

}

void Demi_pas(){
  while(d==1)
  {
   Serial.println("Demi_pas");
int Half_step [8][4] ={
  {1, 0, 0, 0},
  {1, 1, 0, 0},
  {0, 1, 0, 0},
  {0, 1, 1, 0},
  {0, 0, 1, 0},
  {0, 0, 1, 1},
  {0, 0, 0, 1},
  {1, 0, 0, 1}
};
  // 512*8 = 4096 pas

  
     for (int i = 0; i < 512; i++){
    // boucle repasse le array ligne à ligne
    for (int s = 0; s < 8; s++){
      // valeurs qu'on va appliquer 
      digitalWrite(IN1, Half_step[s][0]);
      digitalWrite(IN2, Half_step[s][1]);
      digitalWrite(IN3, Half_step[s][2]);
      digitalWrite(IN4, Half_step[s][3]);
      delay(temps);
    }
  }
   digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delay(1000);

       for (int i = 0; i < 512; i++){
    for (int s = 7; s >=0; s--){
      // valeurs que nous allons appliquer
      digitalWrite(IN1, Half_step[s][0]);
      digitalWrite(IN2, Half_step[s][1]);
      digitalWrite(IN3, Half_step[s][2]);
      digitalWrite(IN4, Half_step[s][3]);
      delay(temps);
                               }
    }
  
  // pause de 5 secondes
  
}
}



void loop()
{

  while(Serial.available()!=0)
  {
    char a=Serial.read();
  if(a=='1')
  {
    l=1;
    pas_complet_monophase();
  
  }

  if(a=='2')
  {
    b=1;
    pas_complet_biphase();
     
  }
    if(a=='3')
  {
     d=1;
   Demi_pas();
  
  }
  }

  
}
