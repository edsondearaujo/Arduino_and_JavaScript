const int sensorPin = A0; 
float sensorValue;
float voltageOut;
float temperatureF; // Temperatura em Fahrenheit
float temperatureC; // Em Celsius
#define LED_RED 13
#define LED_GREEN 12


void setup() {
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);  
}


void loop() {
  sensorValue = analogRead(sensorPin);
  voltageOut = (sensorValue * 500) / 1024,0; //milivolts
  
  //calcula temperatura
  temperatureC = voltageOut / 10;
  temperatureF = (temperatureC * 1.8) + 32;
    
  if(temperatureC >= 25.78){
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_RED, HIGH);
    }else{
      digitalWrite(LED_GREEN, HIGH);
      digitalWrite(LED_RED, LOW);
      }
  
  Serial.print("Temperatura(ºC): ");
  Serial.print(temperatureC);
  
  Serial.print("  Temperatura(ºF): ");
  Serial.print(temperatureF);
  
  Serial.print("  Voltagem(mV): ");
  Serial.println(voltageOut);
  delay(1000);
}