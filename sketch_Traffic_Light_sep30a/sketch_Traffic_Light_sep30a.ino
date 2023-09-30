int seven_seg_digits[10][8] = {  { 0,0,0,0,0,0,0,1 },  // = 0 -->(A,B,dp,C,D,E,F,G)
                                 { 1,0,0,0,1,1,1,1 },  // = 1
                                 { 0,0,0,1,0,0,1,0 },  // = 2
                                 { 0,0,0,0,0,1,1,0 },  // = 3
                                 { 1,0,0,0,1,1,0,0 },  // = 4
                                 { 0,1,0,0,0,1,0,0 },  // = 5
                                 { 0,1,0,0,0,0,0,0 },  // = 6
                                 { 0,0,0,0,1,1,1,1 },  // = 7
                                 { 0,0,0,0,0,0,0,0 },  // = 8
                                 { 0,0,0,0,0,1,0,0 }   // = 9
                                 };
int segCount=8,pin,Num,seg;




int red = 13;
int yellow = 12;
int green = 11;

void setup(){
    // put your setup code here, to run once:
  pinMode(2, OUTPUT); //A
  pinMode(3, OUTPUT); //B
  pinMode(4, OUTPUT); //dp
  pinMode(5, OUTPUT); //C
  pinMode(6, OUTPUT); //D
  pinMode(7, OUTPUT); //E
  pinMode(8, OUTPUT); //F
  pinMode(9, OUTPUT); //G
  
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green,  OUTPUT);
  
}
void loop(){

  digitalWrite(red, HIGH);
 // put your main code here, to run repeatedly:
  for(Num=0;Num<10;Num++){
  sevenSegWrite(Num);
  delay(1000);
  }
  digitalWrite(red,  LOW);


   //digitalWrite(yellow, HIGH);
 // put your main code here, to run repeatedly:
  for(Num=0;Num<4;Num++){  
  sevenSegWrite(Num);
  digitalWrite(yellow, HIGH);
  delay(500);
  digitalWrite(yellow, LOW);
  delay(500);
  }


   digitalWrite(green, HIGH);
 // put your main code here, to run repeatedly:
  for(Num=0;Num<10;Num++){
  sevenSegWrite(Num);
  delay(1000);
  }
  digitalWrite(green,  LOW);


for(Num=0;Num<4;Num++){  
  sevenSegWrite(Num);
  digitalWrite(yellow, HIGH);
  delay(500);
  digitalWrite(yellow, LOW);
  delay(500);
  
  }
  //digitalWrite(yellow,  LOW);
  

}



void sevenSegWrite(unsigned int digit) {
    for(pin=2,seg=0;pin<10,seg<segCount;pin++,seg++)
    {
      digitalWrite(pin,seven_seg_digits[digit][seg]);
    }


}
