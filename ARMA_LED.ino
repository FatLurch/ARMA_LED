/*
 * Created by Fat_Lurch - 2021-10-23
 * 
 * This sketch will turn the built-in LED on or off based on serial input. This is meant to serve as a simple example for ARMA COM for ARMA 3
 * 
 * Once this is uploaded to the Arduino, open the Serial Monitor by pressing ctrl+shift+M
 * 
 * In the Serial Monitor, Set the baud rate to 9600 and select "No line ending"
 * 
 * Now type "on" to turn the built-in LED on or type "off" to turn the built-in LED off
 * 
 */

String readString;
char buff[100];

void setup() 
{

  // Set encoder pins as inputs
  pinMode(LED_BUILTIN, OUTPUT);       //Most Arduinos should have an LED_BUILTIN. Tested with Uno
  digitalWrite(LED_BUILTIN, LOW);     //Turn the LED off by default

  // Setup Serial Monitor
  Serial.begin(9600);
}

void loop() 
{
  //========== Handle serial input ====================
  while (Serial.available()) 
    {
      char c = Serial.read();  //gets one byte from serial buffer
      readString += c; //makes the string readString
      delay(2);  //slow looping to allow buffer to fill with next character
    }

    if (readString.length() >0) 
    {
      readString.toLowerCase();   //Set the input to all lower case

      Serial.println(readString); //Echo the typed input back to the serial monitor

      if(readString == "on") 
      {
        digitalWrite(LED_BUILTIN, HIGH);  //Turn the LED on
      }

      if(readString == "off") 
      {
        digitalWrite(LED_BUILTIN, LOW);   //Turn the LED off
      }
            
    }  
    readString = "";      //Clear the readString variable so it doens't jsut constantly grow
}
