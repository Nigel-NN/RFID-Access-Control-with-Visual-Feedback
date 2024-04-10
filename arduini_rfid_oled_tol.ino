#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define RST_PIN 9
#define SS_PIN 10
#define GREEN_LED 7// Define the pin for the green LED
#define RED_LED 2   // Define the pin for the red LED

byte readCard[4];
String My_ID = "(D0B77E89)";
String ID = "";

MFRC522 mfrc522(SS_PIN, RST_PIN);
Adafruit_SSD1306 display = Adafruit_SSD1306(128, 64, &Wire, -1);

void setup()
{
  SPI.begin();
  mfrc522.PCD_Init();
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  pinMode(GREEN_LED, OUTPUT); // Set the green LED pin as output
  pinMode(RED_LED, OUTPUT);   // Set the red LED pin as output

  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.setTextSize(1);
  display.print("Scan Your Card...");
  display.display();
}

void loop()
{
  while (getID())
  {
    display.clearDisplay();
    display.setCursor(0, 0);
    display.setTextSize(1);

    if (ID == My_ID)
    {
      display.print("ACCESS GRANTED!");
      digitalWrite(GREEN_LED, HIGH); // Turn on the green LED
      delay(2000);                   // Keep the LED on for 2 seconds
      digitalWrite(GREEN_LED, LOW);  // Turn off the green LED
    }
    else
    {
      display.print("ACCESS DENIED!");
      digitalWrite(RED_LED, HIGH); // Turn on the red LED
      delay(2000);                 // Keep the LED on for 2 seconds
      digitalWrite(RED_LED, LOW);  // Turn off the red LED
    }

    display.display();
    display.setCursor(0, 20);
    display.print(" ID : ");
    display.print(ID);
    display.display();

    delay(2000);

    display.clearDisplay();
    display.print(" Access Control ");
    display.setCursor(0, 20);
    display.print("Scan Your Card...");
    display.display();
  }
}

boolean getID()
{
  if (!mfrc522.PICC_IsNewCardPresent())
  {
    return false;
  }
  if (!mfrc522.PICC_ReadCardSerial())
  {
    return false;
  }
  ID = "";
  for (uint8_t i = 0; i < 4; i++)
  {
    //readCard[i] = mfrc522.uid.uidByte[i];
    ID.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  ID.toUpperCase();
  mfrc522.PICC_HaltA();
  return true;
}
