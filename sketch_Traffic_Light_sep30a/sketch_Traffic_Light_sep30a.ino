int red     = 13;       //RED Light Port
int yellow  = 12;       //Yellow Light Port
int green   = 11;       //Green Light Port

  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green,  OUTPUT);  

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

int seven_seg_digits[10][8] = {  { 0,0,0,0,0,0,0,1 },  // = 0 -->Seg(A,B,dp,C,D,E,F,G)output level
                                 { 1,0,0,0,1,1,1,1 },  // = 1 -->Seg(A,B,dp,C,D,E,F,G)output level
                                 { 0,0,0,1,0,0,1,0 },  // = 2 -->Seg(A,B,dp,C,D,E,F,G)output level
                                 { 0,0,0,0,0,1,1,0 },  // = 3 -->Seg(A,B,dp,C,D,E,F,G)output level
                                 { 1,0,0,0,1,1,0,0 },  // = 4 -->Seg(A,B,dp,C,D,E,F,G)output level
                                 { 0,1,0,0,0,1,0,0 },  // = 5 -->Seg(A,B,dp,C,D,E,F,G)output level
                                 { 0,1,0,0,0,0,0,0 },  // = 6 -->Seg(A,B,dp,C,D,E,F,G)output level
                                 { 0,0,0,0,1,1,1,1 },  // = 7 -->Seg(A,B,dp,C,D,E,F,G)output level
                                 { 0,0,0,0,0,0,0,0 },  // = 8 -->Seg(A,B,dp,C,D,E,F,G)output level
                                 { 0,0,0,0,0,1,0,0 }   // = 9 -->Seg(A,B,dp,C,D,E,F,G)output level
                                 };
int segCount=8,pin,Num,seg;

}

void loop(){
  // put your main code here, to run repeatedly:

  digitalWrite(red, HIGH);    //RED Light On for 10 sec 
  for(Num=0;Num<10;Num++){
  sevenSegWrite(Num);
  delay(1000);
  }
  digitalWrite(red,  LOW);


  for(Num=0;Num<4;Num++){     // Yellow Light On for 4 secs(500ms On, 500ms Off)
  sevenSegWrite(Num);
  digitalWrite(yellow, HIGH);
  delay(500);
  digitalWrite(yellow, LOW);
  delay(500);
  }


  digitalWrite(green, HIGH);    //Green Light On for 10 sec
  for(Num=0;Num<10;Num++){
  sevenSegWrite(Num);
  delay(1000);
  }
  digitalWrite(green,  LOW);


  for(Num=0;Num<4;Num++){     // Yellow Light On for 4 secs(500ms On, 500ms Off)
  sevenSegWrite(Num);
  digitalWrite(yellow, HIGH);
  delay(500);
  digitalWrite(yellow, LOW);
  delay(500);
  
  }
}


void sevenSegWrite(unsigned int digit) {
    for(pin=2,seg=0;pin<10,seg<segCount;pin++,seg++)
    {
      digitalWrite(pin,seven_seg_digits[digit][seg]);
    }
}
