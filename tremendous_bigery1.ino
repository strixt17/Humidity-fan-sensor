// C++ code
//
int tempPin = A0; 
int tempInput; 
double temp; 
int motorPin = 3;
int redPin = 4;
int bluePin = 5;
int greenPin = 6;

void setup()
{  
  pinMode(motorPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);  
  Serial.begin(9600);
}

void loop()
{
	tempInput = analogRead(A0); 
	temp = (double)tempInput / 1024; 
	temp = (temp * 5 - 0.5) * 100; 
	Serial.print("Current Temperature: ");
	Serial.println(temp);
  	
  if (temp <= 0) {
  	digitalWrite(redPin, 0);
    digitalWrite(greenPin, 0);
    digitalWrite(bluePin, 252);
  }
  if (temp >= 0 && temp <= 45) {
  	digitalWrite(redPin, 0);
    digitalWrite(greenPin, 252);
    digitalWrite(bluePin, 0);
  }
  else {
  	digitalWrite(redPin, 252);
    digitalWrite(greenPin, 0);
    digitalWrite(bluePin, 0);
  }
}