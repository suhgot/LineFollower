int l_motor = 7;        // Left motor pin
int r_motor = 8;        // Right motor pin
int L_Pin = A1;         // Left photocell pin
int R_Pin = A0;         // Right photocell pin

int ADval_L = 0;        // A/D value left
int ADval_R = 0;        // A/D value right
float Vin = 5.0;        // Reference voltage
float Vout_L = 0;       // Measured voltage left
float Vout_R = 0;       // Measured voltage right
float R2 = 10000.0;     // Fixed resistor value
float R1_L = 0;         // Resistance of left photoresistor
float R1_R = 0;         // Resistance of right photoresistor
float Threshold = 3.5;  // Voltage threshold
int stopDelay = 600;    // Stopping duration in ms
int runDelay = 65; // Running duration in ms

void setup() 
{
  Serial.begin(9600);
  pinMode(l_motor, OUTPUT); // sets left motor as output
  pinMode(r_motor, OUTPUT); // sets right motor as output
}

void loop() 
{
  // Read left photocell and print values
  ADval_L = analogRead(L_Pin);
  Vout_L = (ADval_L * Vin) / 1024.0;
  R1_L = (Vout_L != Vin) ? (-R2 * Vout_L) / (Vout_L - Vin) : 0;

  Serial.print("ADval_L: "); Serial.println(ADval_L);
  Serial.print("Vout_L: "); Serial.println(Vout_L);
  Serial.print("R1_L: "); Serial.println(R1_L);

  // Read right photocell and print values
  ADval_R = analogRead(R_Pin);
  Vout_R = (ADval_R * Vin) / 1024.0;
  R1_R = (Vout_R != Vin) ? (-R2 * Vout_R) / (Vout_R - Vin) : 0;

  Serial.print("ADval_R: "); Serial.println(ADval_R);
  Serial.print("Vout_R: "); Serial.println(Vout_R);
  Serial.print("R1_R: "); Serial.println(R1_R);

  // Motor control logic with pauses
  if (Vout_R < Threshold && Vout_L > Threshold) 
  {
    // Turn Right ifright detects dark and left detects light
    digitalWrite(l_motor, HIGH);
    digitalWrite(r_motor, LOW);
    delay(runDelay+60);
    digitalWrite(l_motor, LOW);
    digitalWrite(r_motor, LOW);
    delay(stopDelay);
  } 
  else if (Vout_R > Threshold && Vout_L < Threshold) 
  {
    // Turn Left if right detecs light and left detects dark
    digitalWrite(l_motor, LOW);
    digitalWrite(r_motor, HIGH);
    delay(runDelay+60);
    digitalWrite(l_motor, LOW);
    digitalWrite(r_motor, LOW);
    delay(stopDelay);
  } 
  else if (Vout_R < Threshold && Vout_L < Threshold)
  {
    // Stop if both photocells detect black line
    digitalWrite(l_motor, LOW);
    digitalWrite(r_motor, LOW);
    while(1);
  }
  else 
  {
    // Move forward if none of the previous conditions are met
    digitalWrite(l_motor, HIGH);
    digitalWrite(r_motor, HIGH);
    delay(runDelay);
    digitalWrite(l_motor, LOW);
    digitalWrite(r_motor, LOW);
    delay(stopDelay);
  }

  delay(200);  // Short pause before next loop
}
