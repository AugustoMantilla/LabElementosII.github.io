int led=13;
int boton=10;
bool status_boton=0;
void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);  
  pinMode(boton, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  status_boton=digitalRead(boton);
  digitalWrite(led,status_boton);
}