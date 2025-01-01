// Revision Log
// 1.0 Initial Revision
// 2.0 Shipped September 2023
// 2.1 12/3/2023  - Fixed negative temperature logging bug
// 3.0 12/28/2023 - Add dynamic tare adjustment, additional logging and an event file
// 3.1 2/1/2024 - Added code to store a summary file 
// 3.2 3/1/2024 - Reduced scale sampling / averaging.  Shut off display after 1 minute
// 4.0 12/29/2024 - Rewrite to clean up logic and add Welfords algorithm
/*MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMKol0MMMMMWNNWW0ocokKkllO0odKMWNNWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNxcOWMMMMMMM
MMMMMMMMMMKol0MMMMMKxdk0XXklcokxllxxldXNkxXMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNxcOWMMMMMMM
MMMMMMMMMMKol0MMMMMWXkoclxOOdlcodlcolcdKOoOWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNxcOWMMMMMMM
MMMMMMMMMMKol0MMMMMWWWXOoccldolccc:cc:cokoo0WMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNxcOWMMMMMMM
MMMMMMMMMMKol0MMMMW0xxO00koc:ccc::::::::cccoKWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNxcOWMMMMMMM
MMMMMMMMMMKol0MMMMMNOocclodoc::::::::::::::cdXWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNxcOWMMMMMMM
MMMMMMMMMMKol0MMMMMMWNOdlc::::::::::::::::::cdXWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNxcOWMMMMMMM
MMMMMMMMMMKol0MMMMMMMWKxoc:::::::::::::::::::cdXMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNxcOWMMMMMMM
MMMMMMMMMMKol0MMMMMMMWKdc:::::::::::::::::::::cdKWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNxcOWMMMMMMM
MMMMMMMMMMKol0MMMMMMMMWXxc:::::::::::::::::::::cdKWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNxcOWMMMMMMM
MMMMMMMMMMKol0MMMMMMMMMKdc::::::::::::::::::::::co0WMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNxcOWMMMMMMM
MMMMMMMMMMKol0MMMMMMMMMWKdc::::::::::::::::::::::co0WMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNxcOWMMMMMMM
MMMMMMMMMMKol0MMMMMMMMMMNkc::::::::::::::::::::::::lONMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNxcOWMMMMMMM
MMMMMMMMMMKol0MMMMMMMMMMWXOoc:::::::::::::::::::::::lkNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNxcOWMMMMMMM
MMMMMMMMMMKol0MMMMMMMMMMMMNkc::::::::::::::::::::::::cxXWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNxcOWMMMMMMM
MMMMMMMMMMKol0MMMMMMMMMMMMWOl:::::::::::::::::::::::::co0WMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNxcOWMMMMMMM
MMMMMMMMMMKol0MMMMMMMMMMMMMNOl::::::::::::::::::::::::::lONMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNxcOWMMMMMMM
MMMMMMMMMMKol0MMMMMMMMMMMMMWKoc::::::::::::::::::::::::::lkNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNxcOWMMMMMMM
MMMMMMMMMMKol0MMMMMMMMMMMMMMWKdc::::::::::::::::::::::::::lONMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNxcOWMMMMMMM
MMMMMMMMMMKol0MMMMMMMMMMMMMMMWOl:::::::::::::::::::::::::::lONMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNxcOWMMMMMMM
MMMMMMMMMMKol0MMMMMMMMMMMMMMMMNOo:::::::::::::::::::::::::::lkNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNxcOWMMMMMMM
MMMMMMMMMMKol0MMMMMMMMMMMMMMMMMWOc:::::::::::::::::::::::::::cxXMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNxcOWMMMMMMM
MMMMMMMMMMKol0MMMMMMMMMMMMMMMMMMNOl:::::::::::::::::::::::::::co0WMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNxcOWMMMMMMM
MMMMMMMMMMKol0MMMMMMMMMMMMMMMMMMMW0l:::::::::::::::::::::::::::clkNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNxcOWMMMMMMM
MMMMMMMMMMKol0MMMMMMMMMMMMMMMMMMMMW0oc:::::::::::::::::::::::::::cd0WMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNxcOWMMMMMMM
MMMMMMMMMMKol0MMMMMMMMMMMMMMMMMMMMMWXkl::::::::::::::::::::::::::::lxXWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNxcOWMMMMMMM
MMMMMMMMMMKol0MMMMMMMMMMMMMMMMMMMMMMMW0oc:::::::::::::::::::::::::::clkXWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNxcOWMMMMMMM
MMMMMMMMMMKol0MMMMMMMMMMMMMMMMMMMMMMMMWXOoc:::::::::::::::::::::::::::cokXWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNxcOWMMMMMMM
MMMMMMMMMMKol0MMMMMMMMMMMMMMMMMMMMMMMMMMWNOdc:::::::::::::::::::::::::::clxOKNWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNxcOWMMMMMMM
MMMMMMMMMMKol0MMMMMMMMMMMMMMMMMMMMMMMMMMMMWNKkoc::::::::::::::::::::::::::ccldOKNWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNxcOWMMMMMMM
MMMMMMMMMMKol0MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWN0xoc::::::::::::::::::::::::::::coxkOOKXNWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNxcOWMMMMMMM
MMMMMMMMMMKol0MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWXOxoc:::::::::::::::::::::::::::::::cld0NMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNxcOWMMMMMMM
MMMMMMMMMMKol0MMMMMMMMMMMMMMMMMMWWWWMMMMMMMMMMWWWWNKkl:::::::::::::::::::::::::::::::clldKMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNxcOWMMMMMMM
MMMMMMMMMMKol0MMMMMMMMMMMMMMMMWKxxxxxkkOOOOkkxxdddolc:::::::::::::::::::::::::::::::cd0XXWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNxcOWMMMMMMM
MMMMMMMMMMKol0MMMMMMMMMMMMMMMMWKo::::::::::::::::::::::::::::::::::::::::::::::::::::cdOXWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNxcOWMMMMMMM
MMMMMMMMMMKol0MMMMMMMMMMMMMMMMMNkl:::::::::::::::::::::::::::::::::::::::::::::::::::::cldOXWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNxcOWMMMMMMM
MMMMMMMMMMKol0MMMMMMMMMMMMMMMMMMNOl:::::::::::::::::::::::::::::::::::::::::::::::::::::::cldOXWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNxcOWMMMMMMM
MMMMMMMMMMKol0MMMMMMMMMMMMMMMMMMMXd::::::::::::::::::::::::::::c::::::::::::::::::::::::::::::ldOKNWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNxcOWMMMMMMM
MMMMMMMMMMKol0MMMMMMMMMMMMMMMMMMMWXxc::::::::::::::::::::::::cokdc::::::::::::::::::::::::::::::cldOKNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNxcOWMMMMMMM
MMMMMMMMMMKol0MMMMMMMMMMMMMMMMMMMMMXdc::::::::::::::::::::::cdKWXxc:::::::::::::::::::::::::::::::::cdkKNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNxcOWMMMMMMM
MMMMMMMMMMKol0MMMMMMMMMMMMMMMMMMMMMWNOo:::::::::::::::::::::oKWMMNOl:::::::::::::::::::::::::::::::::::cokKNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNxcOWMMMMMMM
MMMMMMMMMMKol0MMMMMMMMMMMMMMMMMMMMMMMW0occ:::::::::::::::::o0WMMMMWKdc::::::::::::::::::::::::::::::::::::cokKWMMMMMMMMMMMMMMMMMMMMMMMMMMMNxcOWMMMMMMM
MMMMMMMMMMKol0MMMMMMMMMMMMMMMMMMMMMMMMWNKOoc::::::::::::::l0WMMMMMMMXklc::::::::::::::::::::::::::::::::::::cldOXWWMMMMMMMMMMMMMMMMMMMMMMMNxcOWMMMMMMM
MMMMMMMMMMKol0MMMMMMMMMMMMMMMMMMMMMMMMMMMWN0Oxlc:::::::::lOWMMMMMMMMMWKxlc:::::::::::::::::::::::::::::::::::::cldOXNWMMMMMMMMMMMMMMMMMMMMNxcOWMMMMMMM
MMMMMMMMMMKol0MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWX00Oxlcc::lOWMMMMMMMMMMMMWXOdlc:::::::::::::::::::::::::::::::::::::cldk0XWWMMMMMMMMMMMMMMMMNxcOWMMMMMMM
MMMMMMMMMMKoclc:::::::cxNMMMMMMMMMMMMMMMMMMMMMMMMMWXK0kkKWMMMMMMMMMMMMMMMWNX0xol::::::::::::::::::::::::::::::::::::::cldxOKXNWMMMMMMMMMMMNxcOWMMMMMMM
MMMMMMMMMMKo:::::::::::lONWWWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWNKkdoc:::::::::::::::::::::::::::::::::::::::coxOO0KNMMMMMMMNxcOWMMMMMMM
MMMMMMMMMMKo::::::::::::lkxdxO00OkxkO0XWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWN0kdoc:::::::::::::::::::::::::::::::::::cldxxxOKNWMMMMMNxcOWMMMMMMM
MMMMMMMMMMKo:::::::::::::c:::ccc:::::clOWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWN0Okdlccc:::::::::::::::::::::::::::ccclodkOO0XWMMMMNxcOWMMMMMMM
MMMMMMMMMMKo:::::::::::::::::::::::::::o0WMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWXXK0xlolc:::::::::::::::::::::cccoododxOKNWMMMMNxcOWMMMMMMM
MMMMMMMMMMKo::::::::::::::::::::::::::::oKWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWNNXkdddlcc:::::::::::cccccodlldkOOkkOXWMMMNxcOWMMMMMMM
MMMMMMMMMMKo::::::::::::::::::::::::::::cd0KXNNNWWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWWWWKkOOdlodlc:llccoxdclxOkdloOXWWWMMMMNxcOWMMMMMMM
MMMMMMMMMMKo::::::::::::::::::::::::::::::cclooodONMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNKXNXkdOKklcxKOdldKNKkdONMMMMMMNxcOWMMMMMMM
MMMMMMMMMMKo:::::::::::::::::::::::::::::::::::::ckNMMMMMMMMMMMMMMMMWNWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWWWMWXkokNN0dkXMWWNWMMMMMMNxcOWMMMMM*/

// THINGS TO REMEMBER
// KEEP THE dynamic memory above 520 bytes free or so to make sure we don't run out of memory for local functions - you will get strange behavior with sd.h library

#include <SD.h>       //SD Card library - SD by Arduinu,Sparkfun - 1.3.0
#include "HX711.h"    //HX711 library - HX711 Arduino library by Bogdan 0.7.5
//#include <Wire.h>     //I2C library - I don't think we need this
#include "EEPROM.h"   //library for built in nano eeprom
#include <SPI.h>      //used by SD Card interface - SPI library
#include "RTClib.h"   //real time clock library - RTClib by Adafruit 2.1.4
#include "DST_RTC.h"  //daylight savings time adjustment library - DST RTC by Andy Doro 1.1.1


// HX711 circuit wiring
HX711 scale;
const int LOADCELL_DOUT_PIN = 2;
const int LOADCELL_SCK_PIN = 3;
//## How to calibrate your load cell
//1. Call `set_scale()` with no parameter.
//2. Call `tare()` with no parameter.
//3. Place a known weight on the scale and call `get_units(10)`.
//4. Divide the result in step 3 to your known weight. You should
//   get about the parameter you need to pass to `set_scale()`.
//5. Adjust the parameter in step 4 until you get an accurate reading.
// Details on the ADC/Transducer
// 24 bit ADC that is formated 2's complement - +/-20mV range for +/-8,388,608 counts on the ADC
// 10 kg is about 1,150,000 counts with the specified design
// 6.5 kg is about 709,000 counts with the specified design
// 4.0 kg is about 440,000 counts with the specified design
// or 114,855 counts per kg with a 20kg sensor


//Globals for this project
unsigned long two_sec_timer, one_hour_timer, event_timer;
double current_reading, last_reading, two_sec_reading, averaged_reading, saved_tare, w_avg, w_max, w_min, w_stdev, w_m2;
int n; //number of samples used in welfords algorithm
bool birdpresent; //true = if scale senses value above weight_threshold
bool finalevent;  //store data 5 seconds after departure
int birdpresentcounter; // how long has he/she been present
int button_ctr = 0;  //counter for 4 second button press


// CONFIGURATIONS
const double weight_threshold = 0.5;  //theshold to trigger scale to bird presence in kg
const double cal_weight = 3.50;  //weight in kilograms of calibration standard -add 0.005 for truncation instead of rounding

//IO Pins
const int CALbuttonPin = 4; //input pin for the tare/cal button
const int CLKScaler = 0x02; //scaler is a power so 2 is 1/4th the 16Mhz frequency
const int CHGSTATPin = 5;
const int PGOODPin = 6;
const int BATTERYVOLTPin = A7;
const int DISPLAY_PWR = A1;

//74HC595 Shift register based display (STATIC DISPLAY without refresh or scan rate concerns)
static const uint8_t numbers[10] =               // 7 segment values for decimals 0..9
{
//TRUTH TABLE    |   0 = segment on
//ABCD EFGH      |   1 = segment off
B00000011,  //0  |        A
B10011111,  //1  |      -----
B00100101,  //2  |   F |     | B
B00001101,  //3  |     |  G  |                                       YEAr B3, 61, 11, F5  1f
B10011001,  //4  |      -----
B01001001,  //5  |   E |     | C
B01000001,  //6  |     |     |
B00011111,  //7  |      -----
B00000001,  //8  |        D
B00011001		//9  |
};
//Pin connected to ST_CP of 74HC595
int latchPin = 9;
//Pin connected to SH_CP of 74HC595
int clockPin = 7;
////Pin connected to DS of 74HC595
int dataPin = 8;


//SD CARD CONFIGS
/*
  SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK  - pin 13
 ** CS   - pin 10
*/
static const int chipSelect = 10;
bool SDpresent;

//real time clock object creation
RTC_DS3231 rtc;
DST_RTC dst_rtc; // DST object
const char rulesDST[] = "US"; // US DST rules


//********************************************************************************
//****************MAIN LOOP OF THE APPLICATION ***********************************
//********************************************************************************
void loop() {
  // Check for button press - initiate calibration process if pressed and held
  CheckForCalButton();
  
  //Read the scale's transducer
  ReadSensor();
  
  //Process sensor measurement if bird present
  ProcessMeasurement();

  //Process 2 second operation
  TwoSecondOp();

  //Process 1 hour operation
  OneHourOp();

  //Update display
  UpdateDisplay();

  //loop rate
  delay(200/pow(2,CLKScaler));

}
//******************************************************************************
//*****************************END OF MAIN LOOP ********************************
//******************************************************************************

void ReadSensor()
{
  //Read the scale's transducer if it is ready
  if (scale.is_ready())   // check if HX711 is ready - DOUT == LOW
  {
    current_reading = scale.get_units(5);  //this call retrieves atare adjusted and scaled weight - average of 5 readings
    averaged_reading = 0.5 * current_reading + 0.5 * averaged_reading; 
  } else 
  {
    //Serial.println("HX711 not found.");
  }
}


void ProcessMeasurement()
{
  if(averaged_reading - two_sec_reading > weight_threshold) //weight above threshold?  //two_sec_reading stops updating if bird present
  {
    if(birdpresent == false)  //initial landing
    {
      birdpresent = true;
      event_timer = millis();  //reset event timer to now
      WriteSummaryFile(0,0,0,0, true);  // write opening line of landing 
      saved_tare = two_sec_reading;
      Write2Values(current_reading, saved_tare, "Trigger and prelanding");
      birdpresentcounter = 1;
      //reset max, min and avg for welfords algo
      w_max=w_min=w_avg=w_stdev=0;
    }
    if (millis() - event_timer > 15000/pow(2,CLKScaler)) // 15 seconds?
    {
      ProcessData(current_reading);
      birdpresentcounter++;
      event_timer = millis(); // reset timer for next event
      if(birdpresentcounter%2 == 0)  //log 15 seconds after landing and then every 30 seconds
      {
        Write2Values(current_reading, current_reading - saved_tare, "30 Sec");
      }
    }
  }else
  {
    if(birdpresent == true)
    {
      birdpresent = false;
      WriteSummaryFile(w_max, w_min, w_avg, w_stdev, false);  // write welford data and date/time as bird departs
      event_timer = millis();
      finalevent = false;
    }
    if((birdpresent == false) && (finalevent == false))
    {
      two_sec_timer = millis(); // keep resetting this until post weight is stored
      if(millis() - event_timer > 5000/pow(2,CLKScaler))
      {
        finalevent = true;
        Write2Values(current_reading, current_reading - saved_tare, "Post departure weight");
      }
    }
  }
}

void ProcessData(float datapoint)  //Welfords algorithm
{
  float delta, delta2, variance;
  if(w_avg == 0)
  {
    n = 0;
    w_max = w_min = datapoint;
  }
  n++;
  delta = datapoint - w_avg;
  w_avg += delta/n;
  delta2 = datapoint- w_avg;
  w_m2 += delta * delta2;
  variance = w_m2/(n-1);
  w_stdev = sqrt(variance);
  if(datapoint > w_max)
  {
    w_max = datapoint;
  }
  if(datapoint < w_min)
  {
    w_min = datapoint;
  }

}

void TwoSecondOp()  //only do this if no bird and 2 seconds has elapsed
{
  if(birdpresent == false && millis() - two_sec_timer > 2000/pow(2,CLKScaler))  // only do this if no bird present
  {
    two_sec_reading = last_reading;
    last_reading = current_reading;
    two_sec_timer = millis();  //reset timer
  }
}


void OneHourOp()
{
  if(birdpresent == false && millis() - one_hour_timer > 3600000/pow(2,CLKScaler))  //only do this if no bird and 1 hour elapsed
  {
      Write2Values(current_reading, averaged_reading, "Periodic");
      one_hour_timer = millis();  //reset timer
  }
}

void UpdateDisplay()
{
  if((birdpresent == true && birdpresentcounter < 6) || (birdpresent == false && millis() - event_timer < 10000/pow(2,CLKScaler)))
  {
    displayNumber2D(current_reading - saved_tare + 0.005); 
  }else
  {
    displayBlank();
  }
}



//********************************************************************************
//****************SETUP CODE - CALLED FIRST BEFORE LOOP **************************
//********************************************************************************
void setup() {
  //initialize clock slower to save power
  CLKPR = 0x80;
  CLKPR = CLKScaler;  //Set clock prescaler
  //initialize IO pins
    //Display IO
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(DISPLAY_PWR, OUTPUT);
     //Charger IO
  pinMode(PGOODPin, INPUT);
  pinMode(CHGSTATPin, INPUT);
     //Button IO     
  pinMode(CALbuttonPin, INPUT_PULLUP);

  //Serial.begin(38400);  //setup serial debug port

  //initialize variables
  int setupbuttonstate = 0;
  current_reading = last_reading = two_sec_reading = 0;  // start off with all trackers at zero
  float  startup_cal_value; 
  saved_tare = 0;
  birdpresent = false;  //preset to no bird present
  finalevent = true;  // present to having processed final event


  //Display revision
  digitalWrite(DISPLAY_PWR, LOW); //Turn on display
  DisplayItOnLED(0x91, 0x9f, 0XEf, 0x99);  // "HI_4"  last digit is the revision
  delay(1000/pow(2,CLKScaler));  //let it show on the display
  
  
  //Lithium Ion Polymer Battery - 3.7V 10050mAh
  //Display battery level - Power supply is set to 4.9 volts so 1024 = 4.9. Battery 100% = 4.1V, Battery 1% =2.8V
  double battLevel = ((analogRead(BATTERYVOLTPin) * 4.90/1024 - 2.8) * 0.77);
  if (battLevel > 1)
  { battLevel = 1;}
  if (battLevel < 0.01)
  { battLevel =0.01;}
  displayNumber2D(battLevel);

  //check if Real time clock connected and talking
  if (! rtc.begin()) 
  {
   // Serial.println("Couldn't find RTC");
    DisplayItOnLED(0xD5, 0xC5, 0x73, 0XE1);  // "nort"
    delay(5000/pow(2,CLKScaler));  //let it show on the display
  }

  //check if power on with tare/cal button held - enter time/date setting
  setupbuttonstate = digitalRead(CALbuttonPin);
  if (setupbuttonstate == LOW)
  {
    delay(1000/pow(2,CLKScaler));    
    if (setupbuttonstate == LOW)
    {
      delay(1000/pow(2,CLKScaler));    
      if (setupbuttonstate == LOW)
      {
        SetDateAndTime();
      }
    }
  }


  //Serial.println("Initializing the HX711 sensor");
  // Initialize library with data output pin, clock input pin and gain factor.
  // Channel selection is made by passing the appropriate gain:
  // - With a gain factor of 64 or 128, channel A is selected
  // - With a gain factor of 32, channel B is selected
  // By omitting the gain factor parameter, the library
  // default "128" (Channel A) is used here.
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  //Serial.println("Before setting up the scale:");
  //Serial.print("read: \t\t");
  //Serial.println(scale.read());      // print a raw reading from the ADC
  scale.read();
  //Serial.print("read average: \t\t");
  //Serial.println(scale.read_average(20));   // print the average of 20 readings from the ADC
  scale.read_average(20);
  //Serial.print("get value: \t\t");
  //Serial.println(scale.get_value(5));   // print the average of 5 readings from the ADC minus the tare weight (not set yet)
  scale.get_value(5);
  //Serial.print("get units: \t\t");
  //Serial.println(scale.get_units(5), 1);  // print the average of 5 readings from the ADC minus tare weight (not set) divided
  scale.get_units(5);

  //read external eeprom - 0x55 present if the EEPROM has been iniatilized and a cal value stored
  uint8_t eeprom_valid = EEPROM.read(0);
  if(eeprom_valid == 0x55)  //configured previously if =0x55
  {
    EEPROM.get(1, startup_cal_value);
    //Serial.print("Read cal value from EEPROM: ");
    //Serial.println(startup_cal_value, 8);
  }else
  {
    startup_cal_value = -980; //default value to use based on 8 scales and 3.5 Kg
  }

  //Setup scale cal factor
  scale.set_scale(startup_cal_value);   //Use EEPROM value if found, otherwise use default value with variable definition
  delay(1000/pow(2,CLKScaler));

  //Perform scale tare operation after each power cycle
  InitialTare();
  delay(1000/pow(2,CLKScaler));
 

  //Initialize the SD Card - see if the card is present and can be initialized:
  //Serial.print("Initializing SD card...");
  SDpresent = true;
  if (!SD.begin(chipSelect)) {
    //Serial.println("Card failed, or not present");
    SDpresent = false;
    DisplayItOnLED(0xD5, 0xC5, 0x49, 0X85);  // "noSd"
    delay(5000/pow(2,CLKScaler));
  }
  //Serial.println("card initialized.");

  //setup the RTC 
  /*if (rtc.lostPower()) {
    Serial.println("RTC lost power, let's set the time!");
    // When time needs to be set on a new device, or after a power loss, the
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }
*/
  if (rtc.lostPower()) {
    //Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(__DATE__, __TIME__));
    //rtc.adjust(DateTime(2023, 1, 2, 13, 15, 0)); //set for SLC time
    // DST? If we're in it, let's subtract an hour from the RTC time to keep our DST calculation correct. This gives us
    // Standard Time which our DST check will add an hour back to if we're in DST.
    DateTime standardTime = rtc.now();
    if (dst_rtc.checkDST(standardTime) == true) { // check whether we're in DST right now. If we are, subtract an hour.
      standardTime = standardTime.unixtime() - 3600;
    }
    rtc.adjust(standardTime);
  }

  //read, format and display time at power on
  DateTime standardTime = rtc.now();
  DateTime theTime = dst_rtc.calculateTime(standardTime); // takes into account DST
  double timetemp = theTime.hour();
  timetemp += (double)theTime.minute()/100.0;
  displayNumber2D(timetemp);
  delay(1000/pow(2,CLKScaler));

  //Store header at power on
  WriteSDFile(false, "Date,Time,Int Temp,Battery,Raw Reading,Weight(Kg),Notes");  
  char str[70];
  strcpy(str, "0,0,Powered on using calibration: ");
  dtostrf(startup_cal_value, 7, 2, &str[strlen(str)]);
  strcpy(&str[strlen(str)], " offset: ");
  ltoa(scale.get_offset(), &str[strlen(str)], 10);
  WriteSDFile(true, str);
  WriteSummaryFile(0,0,0,0, false);  // insert blank line to indicate power on
  //initialize timers
  two_sec_timer = one_hour_timer = millis();
}


void CheckForCalButton(void)
{
  if (digitalRead(CALbuttonPin) == LOW)
  {
    button_ctr++;    
    if(button_ctr > 3)  //3 loops through main with the button pressed will fire the calibration routine
    {
      button_ctr = 0;      
      PushbuttonCalibration();
    }
  }else
  {
    button_ctr = 0;
  }

}

void Write2Values(double raw, double adjusted, String stufftowrite)
{  
    String localString;
    localString = String(raw, 2);
    localString.concat(",");
    localString.concat(String(adjusted, 2));
    localString.concat(",");
    localString.concat(stufftowrite);
    WriteSDFile(true, localString);
}



// Write log file data - make sure there are 512bytes or more for local variables
void WriteSDFile(bool dataprefix, String stufftowrite)
{
  DateTime standardtime = rtc.now();
  DateTime theTime = dst_rtc.calculateTime(standardtime); // takes into account DST      
  // if the file is available, write to it:
  File dataFile = SD.open ("datalog.csv", FILE_WRITE);
  if (dataFile)
  {
    char c[10]; 
    if (dataprefix == true)
    {
      sprintf(c, "%02d", theTime.month());    // build integer string using C integer formatters  (m is length, and not used in this code)
      dataFile.print(c);
      dataFile.print('/');
      sprintf(c, "%02d", theTime.day()); 
      dataFile.print(c);
      dataFile.print('/');
      dataFile.print(theTime.year(), DEC);
      dataFile.print(",");
      sprintf(c, "%02d", theTime.hour()); 
      dataFile.print(c);
      dataFile.print(':');
      sprintf(c, "%02d", theTime.minute()); 
      dataFile.print(c);
      dataFile.print(':');
      sprintf(c, "%02d", theTime.second()); 
      dataFile.print(c);
      dataFile.print(",");
      double temp_temp = rtc.getTemperature();
      if (temp_temp > 127)
      {
        temp_temp = temp_temp -256;
      }
      dataFile.print(temp_temp);
      dataFile.print(",");
      dataFile.print(analogRead(BATTERYVOLTPin) * 4.90/1024);
      //dataFile.print(",");
      //dataFile.print(digitalRead(PGOODPin)==LOW);
      //dataFile.print(",");
      //dataFile.print(digitalRead(CHGSTATPin)==LOW);
      dataFile.print(",");
    }
    dataFile.println(stufftowrite);
    dataFile.close();    
  
  }
}

void WriteSummaryFile(double max, double min, double weight, double stdev, bool landing)
{
  DateTime standardtime = rtc.now();
  DateTime theTime = dst_rtc.calculateTime(standardtime); // takes into account DST      
  // if the file is available, write to it:
  File dataFile = SD.open ("summary.csv", FILE_WRITE);
  if (dataFile)
  {
    char c[10]; 
    sprintf(c, "%02d", theTime.month());    // build integer string using C integer formatters  (m is length, and not used in this code)
    dataFile.print(c);
    dataFile.print('/');
    sprintf(c, "%02d", theTime.day()); 
    dataFile.print(c);
    dataFile.print('/');
    dataFile.print(theTime.year(), DEC);
    dataFile.print(",");
    sprintf(c, "%02d", theTime.hour()); 
    dataFile.print(c);
    dataFile.print(':');
    sprintf(c, "%02d", theTime.minute()); 
    dataFile.print(c);
    dataFile.print(':');
    sprintf(c, "%02d", theTime.second()); 
    dataFile.print(c);
    dataFile.print(",");
    if (landing == false)  //only write weight on departure
    {
      dataFile.println(weight); 
    }
    dataFile.close();    
  
  }
}


bool InitialTare(void)
{
  DisplayItOnLED(0xE1, 0x11, 0x73, 0X61);  //"tARE"
  delay(1000/pow(2,CLKScaler));
  scale.tare();
  current_reading = last_reading = two_sec_reading = 0;  // start off with all drift trackers at zero
  return(true);

}

//Initiated by holding CAL button for 3 seconds
bool PushbuttonCalibration(void)
{
  int buttonstate = 0;
  float w_counts, cal_value;
  scale.set_scale();
  InitialTare();
  delay(1000/pow(2,CLKScaler));
  //tell user to hang weight (CAL message)
//  matrix.println("CAL");
//  matrix.writeDisplay();
  DisplayItOnLED(0x63, 0x11, 0xE3, 0xFF);  //Display CAL

  //wait for button press to acknowledge weight is placed
  while(buttonstate == LOW)
  {
    buttonstate = digitalRead(CALbuttonPin);
  }
  //wait for button release
  while(buttonstate == HIGH)
  {
    buttonstate = digitalRead(CALbuttonPin);
  }

  w_counts = scale.get_units(10);
  cal_value = w_counts/cal_weight;
  //cal_value = cal_value/100; //do this to give us an int we can display with 2 digits
  scale.set_scale(cal_value);
  // tell the user it is calibrated
  //matrix.println("CALD");
  //matrix.writeDisplay();
  DisplayItOnLED(0x63, 0x11, 0xE3, 0x85);  //Display CALd

  //Serial.println("Writing calibration factor to address 0x01");
  //Serial.println(cal_value);
  //store value to External EEProm
  //uint8_t buffer[4];  // floats are 4 bytes!
  //memcpy(buffer, (void *)&cal_value, 4);
  //EEPROM.write(0x01, buffer, 4);
  //store value to INternal EEPROM
  EEPROM.put(1, cal_value);  
  
  delay(1000/pow(2,CLKScaler));
  //i2ceeprom.write(0x0, 0x55);  //write byte to indicate EEProm has valid calibration data
  EEPROM.write(0,0x55); //Write byte to indicate EEPROM has valid calibration data for use at power up
  delay(2000/pow(2,CLKScaler));


  char str[70];
  strcpy(str, "Calibration completed. New value: ");
  dtostrf(cal_value, 8, 2, &str[strlen(str)]);
  strcpy(&str[strlen(str)], " offset: ");
  ltoa(scale.get_offset(), &str[strlen(str)], 10);
  WriteSDFile(true, str);

  return true;
}


//SHIFT REGISTER BASED DISPLAY (no scanning or refresh rate - sucking a lot of power though)

void DisplayItOnLED(int digit1, int digit2, int digit3, int digit4)
{
 // send out data
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, digit4);
  shiftOut(dataPin, clockPin, LSBFIRST, digit3);
  shiftOut(dataPin, clockPin, LSBFIRST, digit2);
  shiftOut(dataPin, clockPin, LSBFIRST, digit1);
  digitalWrite(latchPin, HIGH); 
}

void displayError(void)
{
  DisplayItOnLED(0xFD, 0xFD, 0xFD, 0XFD);  // four dashes
}


void displayBlank(void)
{
  DisplayItOnLED(0xFF, 0xFF, 0xFF, 0XFF);  //blank screen
}

//convert a number to a stream to shift out to the seven segment display
bool displayNumber2D(double number)
{
  int temp, digit1, digit2, digit3, digit4; //displayed left to right in that order
  int tempsum;
  int intnumber;
  //Serial.println(number);
  intnumber = number * 100; //get rid of decimal places and work in that arena
  if(abs(intnumber) < 9999)   
  {
    if(abs(intnumber) < 1000)
    {
      temp = 0;  //1st digit is zero (also known as blank)
      if(intnumber == abs(intnumber))
      {
        digit1 = 255; //blank display
      }else
      {
        if(intnumber < -1000) //not enough digits on the display
        {
          //Serial.println("number too negative");

          displayError();
          return(false);
        }
        digit1 = B11111101;  //show negative symbol
        intnumber = abs(intnumber);  //show negative and treat like positive
      }
    }else
    {
      temp = intnumber/1000;
      digit1 = numbers[temp];
    }

    tempsum = temp * 1000;
    temp = intnumber - tempsum;
    temp = temp /100;
    digit2 = numbers[temp] & 0XFE; //and on the decimal point
    tempsum = tempsum + temp*100;

    temp = intnumber - tempsum;
    temp = temp/10;
    digit3 = numbers[temp];
    tempsum = tempsum + temp * 10;
    
    temp = intnumber - tempsum; 
    digit4 = numbers[temp];

    DisplayItOnLED(digit1, digit2, digit3, digit4);
    return(true);


  }else
  {
    //Serial.println("number too large");

    displayError();
    return(false);
  }
}


void SetDateAndTime(void)
{
    int month, day, year, minute, hour;
    DisplayItOnLED(0x49, 0xE1, 0x83, 0X31);  // "StUP"
    delay(5000/pow(2,CLKScaler));
    while(digitalRead(CALbuttonPin) == LOW){}  //Wait for button release

    DateTime standardtime = rtc.now();
    DateTime theTime = dst_rtc.calculateTime(standardtime); // takes into account DST      
    month = theTime.month();
    day = theTime.day(); 
    year = theTime.year() - 2000;
    hour = theTime.hour(); 
    minute = theTime.minute(); 

    //Get hour = d1,c5, c7, f5 
    DisplayItOnLED(0xD1, 0xC5, 0xC7, 0xF5);
    delay(2500/pow(2,CLKScaler));
    hour = GetValueFromUser(hour, 0,23);
    //Get min =  

    DisplayItOnLED(0x13, 0x13, 0xF7, 0xD5);
    while(digitalRead(CALbuttonPin) == LOW){}  //Wait for button release from previous
    delay(2500/pow(2,CLKScaler));
    minute = GetValueFromUser(minute, 0,59);
    
    // Get month = 
    DisplayItOnLED(0x13, 0x13, 0xC5, 0xD5);
    while(digitalRead(CALbuttonPin) == LOW){}  //Wait for button release
    delay(2500/pow(2,CLKScaler));
    month = GetValueFromUser(month, 1,12);
    
    //Get day = ff, 85, 11, B1
    DisplayItOnLED(0xFF, 0x85, 0x11, 0xB1);
    while(digitalRead(CALbuttonPin) == LOW){}  //Wait for button release
    delay(2500/pow(2,CLKScaler));
    day = GetValueFromUser(day, 1,31);

    //Get year = YEAr B1, 61, 11, F5
    DisplayItOnLED(0xB1, 0x61, 0x11, 0xF5);
    while(digitalRead(CALbuttonPin) == LOW){}  //Wait for button release
    delay(2500/pow(2,CLKScaler));
    year = GetValueFromUser(year, 23,43) + 2000;

   if (dst_rtc.checkDST(standardtime) == true) { // check whether we're in DST right now. If we are, subtract an hour since the adjust for DST will add an hour if we are in DST
      if(hour > 0)
      {
        hour--; //This won't work well if set between midnight and 1AM - don't do that
      }else
      {
        hour = 23;
      }
    }

    rtc.adjust(DateTime(year, month, day, hour, minute, 30)); 
}


int GetValueFromUser(int varval, int lowerbound, int upperbound)
{
    unsigned long currentMillis = millis();
    unsigned long btnholdtimer;
    int loopcounter = 0;

    while(millis() - currentMillis < 70000/pow(2,CLKScaler))  //give on minute per value
    {
      displayNumber2D(varval);
      btnholdtimer = millis();
      while(digitalRead(CALbuttonPin) == LOW)
      {
         delay(100/pow(2,CLKScaler)); //little bit of debounce
         loopcounter = 1;
         if(millis() - btnholdtimer > 3000/pow(2,CLKScaler))
         {
           return varval;
         }
      }
      if(loopcounter > 0)
      {
        loopcounter = 0;
        varval++;
        if (varval > upperbound)
        {
          varval = lowerbound;
        }
      }


    }


}















