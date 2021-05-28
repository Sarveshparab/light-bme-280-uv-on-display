

#include <BH1750.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
#define SEALEVELPRESSURE_HPA (1013.25)

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


// Create the Lightsensor instance
BH1750 lightMeter(0x23);
Adafruit_BME280 bme;
const int UV=A0;

void setup() 
{
  Wire.begin(D1, D2);
  Serial.begin(115200);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever

  }
  
  if (!bme.begin(0x76)) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
    }
  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  

  // Clear the buffer
  display.clearDisplay();

(lightMeter.begin(BH1750::CONTINUOUS_HIGH_RES_MODE)); 


}
void light()
{display.clearDisplay();
 float lux = lightMeter.readLightLevel();
   display.setTextSize(2);             // Normal 1:1 pixel scale
   display.setTextColor(SSD1306_WHITE);        // Draw white text
   display.setCursor(0,0); // Start at top-left corner
   display.println(F("Light :"));
   display.println(lux);
   display.println(F("LUX"));
   display.display();
  
   delay(500);
}
void tempbme(){
  display.clearDisplay();
  Serial.print("Temperature");
  Serial.print(bme.readTemperature());
  Serial.println("*C");
  display.setTextSize(2);             // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);        // Draw white text
  display.setCursor(0,0); // Start at top-left corner
  display.println(F("Temp"));
  display.println(bme.readTemperature());
  display.print(F("*C"));
  display.display();
}
void pressurebme(){
  display.clearDisplay();
  Serial.print("Pressure");
  Serial.print(bme.readPressure() / 100.0F);
  Serial.println("hPa");
  display.setTextSize(2);             // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);        // Draw white text
  display.setCursor(0,0); // Start at top-left corner
  display.println(F("Pressure"));
  display.println(bme.readPressure() / 100.0F);
  display.print(F("hPa"));
  display.display();
  display.clearDisplay();
}
void altitude(){
  display.clearDisplay();
  Serial.print("Altitude");
  Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
  Serial.println("m");
  display.setTextSize(2);             // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);        // Draw white text
  display.setCursor(0,0); // Start at top-left corner
  display.println(F("Altitude"));
  display.println(bme.readAltitude(SEALEVELPRESSURE_HPA));
  display.println(F("m"));
  display.display();
  display.clearDisplay();
}
void humiditybme(){
  display.clearDisplay();
  Serial.print("Humidity");
  Serial.print(bme.readHumidity());
  Serial.println("%");
  display.setTextSize(2);             // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);        // Draw white text
  display.setCursor(0,0); // Start at top-left corner
  display.println(F("Humidity"));
  display.println(bme.readHumidity());
  display.print(F("%"));
  display.display();  
  display.clearDisplay();

  Serial.println();
  delay(3000);
  }

void UVlight(){
int valeur_UV=analogRead(UV);
Serial.print("analog val= ");
Serial.println(valeur_UV);
if(0<valeur_UV and valeur_UV<10)
{ 
  Serial.print("UV index= ");
  Serial.println(0);
  display.setTextSize(2);             // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);        // Draw white text
  display.setCursor(0,0); // Start at top-left corner
  display.println(F("UV index= "));
  display.println("0");
  display.display();  
  display.clearDisplay();
}
else if(10<valeur_UV and valeur_UV<46)
{
  Serial.print("UV index= ");
  Serial.println(1);
  display.setTextSize(2);             // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);        // Draw white text
  display.setCursor(0,0); // Start at top-left corner
  display.println(F("UV index= "));
  display.println("1");
  display.display();  
  display.clearDisplay();
}
else if(46<valeur_UV and valeur_UV<65)
{
  Serial.print("UV index= ");
  Serial.println(2);
  display.setTextSize(2);             // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);        // Draw white text
  display.setCursor(0,0); // Start at top-left corner
  display.println(F("UV index= "));
  display.println("2");
  display.display();  
  display.clearDisplay();  
}
else if(65<valeur_UV and valeur_UV<83)
{
  Serial.print("UV index= ");
  Serial.println(3);
  display.setTextSize(2);             // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);        // Draw white text
  display.setCursor(0,0); // Start at top-left corner
  display.println(F("UV index= "));
  display.println("3");
  display.display();  
  display.clearDisplay();  
}
else if(83<valeur_UV and valeur_UV<103)
{
  Serial.print("UV index= ");
  Serial.println(4);
  display.setTextSize(2);             // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);        // Draw white text
  display.setCursor(0,0); // Start at top-left corner
  display.println(F("UV index= "));
  display.println("4");
  display.display();  
  display.clearDisplay();  
}
else if(103<valeur_UV and valeur_UV<124)
{
  Serial.print("UV index= ");
  Serial.println(5);
  display.setTextSize(2);             // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);        // Draw white text
  display.setCursor(0,0); // Start at top-left corner
  display.println(F("UV index= "));
  display.println("5");
  display.display();  
  display.clearDisplay();
}
else if(124<valeur_UV and valeur_UV<142)
{
  Serial.print("UV index= ");
  Serial.println(6);
  display.setTextSize(2);             // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);        // Draw white text
  display.setCursor(0,0); // Start at top-left corner
  display.println(F("UV index= "));
  display.println("6");
  display.display();  
  display.clearDisplay();
}
else if(142<valeur_UV and valeur_UV<162)
{
  Serial.print("UV index= ");
  Serial.println(7);
  display.setTextSize(2);             // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);        // Draw white text
  display.setCursor(0,0); // Start at top-left corner
  display.println(F("UV index= "));
  display.println("7");
  display.display();  
  display.clearDisplay();
}
else if(162<valeur_UV and valeur_UV<180)
{
  Serial.print("UV index= ");
  Serial.println(8);
  display.setTextSize(2);             // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);        // Draw white text
  display.setCursor(0,0); // Start at top-left corner
  display.println(F("UV index= "));
  display.println("8");
  display.display();  
  display.clearDisplay();
}
else if(180<valeur_UV and valeur_UV<200)
{
  Serial.print("UV index= ");
  Serial.println(9);
  display.setTextSize(2);             // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);        // Draw white text
  display.setCursor(0,0); // Start at top-left corner
  display.println(F("UV index= "));
  display.println("9");
  display.display();  
  display.clearDisplay();
}
else if(200<valeur_UV and valeur_UV<221)
{
  Serial.print("UV index= ");
  Serial.println(10);
  display.setTextSize(2);             // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);        // Draw white text
  display.setCursor(0,0); // Start at top-left corner
  display.println(F("UV index= "));
  display.println("10");
  display.display();  
  display.clearDisplay();
}
else if(221<valeur_UV and valeur_UV<240)
{
  Serial.print("UV index= ");
  Serial.println("11");
  display.setTextSize(2);             // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);        // Draw white text
  display.setCursor(0,0); // Start at top-left corner
  display.println(F("UV index= "));
  display.println("11");
  display.display();  
  display.clearDisplay();
}
else if(valeur_UV>240)
{
  Serial.print("UV index= ");
  Serial.println("11+");
  display.setTextSize(2);             // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);        // Draw white text
  display.setCursor(0,0); // Start at top-left corner
  display.println(F("UV index= "));
  display.println("11+");
  display.display();  
  display.clearDisplay();  
}
delay(2000); 
}

void loop()
{
  light();
  delay(1000);
  tempbme();
  delay(1000);
  pressurebme();
  delay(1000);
  altitude();
  delay(1000);
  humiditybme();
  delay(1000); 
  UVlight();
  delay(1000); 
}
