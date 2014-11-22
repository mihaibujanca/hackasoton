int dir = 12;
int pwm = 3;
int brake = 9;
int dir2 = 13;
int pwm2 = 11;
int brake2 = 8;
int speed = 0;
int speed2 = 0;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pins as output.
  pinMode(dir, OUTPUT);
  pinMode(pwm, OUTPUT);
  pinMode(brake, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(pwm2, OUTPUT);
  pinMode(brake2, OUTPUT);
  digitalWrite(brake, LOW); 
  digitalWrite(brake2, LOW); 
  Serial.begin(9600);
  speed = 0;
  speed2 = 0;
  digitalWrite(dir, HIGH); 
  digitalWrite(dir2, HIGH);  
  analogWrite(pwm,0);
  analogWrite(pwm2,0);
}
// the loop routine runs over and over again forever:
void loop() {
  
  if(Serial.available())
  {
    speed = Serial.parseInt();
    speed2 = Serial.parseInt();
    if((speed>=0 && speed<=255) && (speed2>=0 && speed2<=255))
    {
      motorForward(speed, speed2);
      delay(0);
    }
  }
}

void motorForward(int PWM_val, int PWM_val2)  {
 analogWrite(pwm, PWM_val);
 digitalWrite(dir, LOW);
 digitalWrite(brake, LOW);
 analogWrite(pwm2, PWM_val2);
 digitalWrite(dir2, LOW);
 digitalWrite(brake2, LOW);
}


