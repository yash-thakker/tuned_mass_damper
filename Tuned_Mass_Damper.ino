#include <SparkFun_ADXL345.h>
ADXL345 adxl = ADXL345();  //I2C Communication
// Variable Declaration
int AccelMinX = 0;
int AccelMaxX = 0;
int AccelMinY = 0;
int AccelMaxY = 0;
int AccelMinZ = 0;
int AccelMaxZ = 0;


int accX = 0;
int accY = 0;
int accZ = 0;


int pitch = 0;
int roll = 0;


// Defined Variables
#define offsetX 0  // OFFSET values
#define offsetY 0
#define offsetZ 0


#define gainX 0  // GAIN factors
#define gainY 0
#define gainZ 0


void setup() {
  Serial.begin(9600);  // Start the serial terminal
  Serial.println("SparkFun ADXL345 Accelerometer Breakout Calibration");
  Serial.println();


  adxl.powerOn();  // Power on the ADXL345


  adxl.setRangeSetting(2);  // Give the range settings - Accepted values are 2g, 4g, 8g or 16g
}


void loop() {
  Serial.println("Send any character to display values.");
  while (!Serial.available()) {}  // Waiting for character to be sent to Serial
  Serial.println();


  // Get the Accelerometer Readings
  int x, y, z;                 // int variables hold results
  adxl.readAccel(&x, &y, &z);  // Read the accelerometer values and store them in variables declared above x,y,z


  if (x < AccelMinX) AccelMinX = x;
  if (x > AccelMaxX) AccelMaxX = x;


  if (y < AccelMinY) AccelMinY = y;
  if (y > AccelMaxY) AccelMaxY = y;


  if (z < AccelMinZ) AccelMinZ = z;
  if (z > AccelMaxZ) AccelMaxZ = z;


  Serial.print("Accel Minimums: ");
  Serial.print(AccelMinX);
  Serial.print("  ");
  Serial.print(AccelMinY);
  Serial.print("  ");
  Serial.print(AccelMinZ);
  Serial.println();
  Serial.print("Accel Maximums: ");
  Serial.print(AccelMaxX);
  Serial.print("  ");
  Serial.print(AccelMaxY);
  Serial.print("  ");
  Serial.print(AccelMaxZ);
  Serial.println();
  Serial.println();


  // offsetAxis = 0.5 * (Acel(Max) + Accel(Min))
  // gainAxis = 0.5 * ((Acel(Max) - Accel(Min))/1g)


 
  // accX = (x - offsetX)/gainX;
  // accY = (y - offsetY)/gainY;
  // accZ = (z - offsetZ)/gainZ;


  // Serial.print("New Calibrated Values: "); Serial.print(accX); Serial.print("  "); Serial.print(accY); Serial.print("  "); Serial.print(accZ);
  // Serial.println();


  while (Serial.available()) {
    Serial.read();  // Clear buffer
  }
}
