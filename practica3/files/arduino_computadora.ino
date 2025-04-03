void setup() {
  Serial.begin(2000000);
}

void loop() {
  if (Serial.available() > 0) { 
    char r = Serial.read();  
    Serial.println(r);  
  }
}