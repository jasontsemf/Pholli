#define Q1 2
#define Q2 3
#define Q3 4
#define Q4 5
#define STQ 16

byte DTMFdata;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Q1, INPUT);
  pinMode(Q2, INPUT);
  pinMode(Q3, INPUT);
  pinMode(Q4, INPUT);
  pinMode(STQ, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
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
    Serial.println(DTMFdata);
  }
}
