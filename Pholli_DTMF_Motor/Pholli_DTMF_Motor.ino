#define Q1 2
#define Q2 3
#define Q3 4
#define Q4 5
#define STQ 6
#define MOTOR 10
#define BTN 8

int DTMFdata;
unsigned long time;
bool pressed = false;
long start;
int mul;
long wait;

void setup() {
  Serial.begin(9600);

  //DTMF pin
  pinMode(Q1, INPUT);
  pinMode(Q2, INPUT);
  pinMode(Q3, INPUT);
  pinMode(Q4, INPUT);
  pinMode(STQ, INPUT_PULLUP);

  pinMode(MOTOR, OUTPUT);
  pinMode(BTN, INPUT_PULLUP);
} 

void loop() {
  DTMFdata = 0;
  if(digitalRead(STQ) == HIGH){
    if(digitalRead(Q1) == HIGH){
      DTMFdata = DTMFdata + 1;
    }
    if(digitalRead(Q2) == HIGH){
      DTMFdata = DTMFdata + 2;
    }
    if(digitalRead(Q3) == HIGH){
      DTMFdata = DTMFdata + 4;
    }
    if(digitalRead(Q4) == HIGH){
      DTMFdata = DTMFdata + 8;
    }
    mul = DTMFdata;
    wait = mul * 1000;
  }
  if(digitalRead(BTN) == LOW){
    Serial.println("LOW");
    pressed = true;
    start = millis();
  }
  
  digitalWrite(MOTOR, HIGH);
  
  if(pressed){
    if((millis() - start) < wait){
      digitalWrite(MOTOR, LOW);
      Serial.println("LOW");
    }else{
      pressed = false;
//      Serial.println("HIGH");
    }
  }
}
