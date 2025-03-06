int led=3;
int boton=4;
bool status_boton=LOW;
void setup() {
  // put your setup code here, to run once:
pinMode(led, OUTPUT);  
pinMode(boton, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  status_boton=digitalRead(boton);
  if (status_boton==HIGH){
    digitalWrite(led, HIGH);
  }
  else{
    digitalWrite(led,LOW);

 }
}