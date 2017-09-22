/* ADXL335 3-axis Accelerometer (GY-61) [S057] : http://rdiot.tistory.com/177 [RDIoT Demo] */

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
 
LiquidCrystal_I2C lcd(0x27,20,4);  // LCD2004
const int xpin = A0;                  // x-axis of the accelerometer
const int ypin = A1;                  // y-axis
const int zpin = A2;                  // z-axis (only on 3-axis models)
 
void setup()
{
  lcd.init();  // initialize the lcd 
  lcd.backlight();
  lcd.print("start LCD2004");
 
  analogReference(EXTERNAL);
  pinMode(xpin, INPUT);
  pinMode(ypin, INPUT);
  pinMode(zpin, INPUT);
 
  delay(1000);
 
  lcd.clear();
}
 
void loop()
{
 
  lcd.setCursor(0,0);
  lcd.print("S057:ADXL335 3axisA");
 
  int x = analogRead(xpin);
    delay(1);
  int y = analogRead(ypin);
    delay(1);
  int z = analogRead(zpin);
  //zero_G is the reading we expect from the sensor when it detects
  //no acceleration.  Subtract this value from the sensor reading to
  //get a shifted sensor reading.
  float zero_G = 512.0;
  
  //scale is the number of units we expect the sensor reading to
  //change when the acceleration along an axis changes by 1G.
  //Divide the shifted sensor reading by scale to get acceleration in Gs.
  float scale = 102.3;
 
  float xp = ((float)x - zero_G)/scale;
  float yp = ((float)y - zero_G)/scale;
  float zp = ((float)z - zero_G)/scale;
 
  lcd.setCursor(0,1);
  lcd.print("ax="+ (String)x +" x=" + (String)xp);
 
  lcd.setCursor(0,2);
  lcd.print("ay="+ (String)y +" y=" + (String)yp);
 
  lcd.setCursor(0,3);
  lcd.print("az="+ (String)z +" z=" + (String)zp);
 
  delay(500); 
}
