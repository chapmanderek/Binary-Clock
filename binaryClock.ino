/*binary Clock
Derek Chapman 9-21-13    rv 9-28-13   rv: 11-27-13
*/

#include <Time.h>
#include <Wire.h>
#include <DS1307RTC.h>

int RTCaddress = 0x68;
time_t t = 0;

//debugging schtuff
boolean timesyncoccured = false;  //to make sure that the rtc time sync actually happened at midnight
int currentminute = 0;  //only print to serial when the minute actually changes so as to not overload the textfile

//blocks used in showing time   (cannot use 2 or 3 on Arduino Micro, these are for SDA and SCL)  
//(also cannot use 0 or 1 when using Serial these are RX/TX)
int H1 = 12; int H2 = 13; int H4 = A0; int H8 = A1; int H10 = A2;
int M1 = 4; int M2 = 5; int M4 = 6; int M8 = 7;
int M10 = 8; int M20 = 9; int M40 = 10;

//blocks not showing time, will still have leds in them for displaying patterns
int HA = A3; int HB = A4; int HC = A5;
int MA = 11;

void setup() {
//  bootupwire();
//  Serial.begin(9600);
//  Serial.flush();
  
//  setMicrotoRTCtime();
  startleds();
  
  if(RTC.get() == 0)
    {
      for(int f = 0; f < 30; f++) //flash all the leds in case the RTC is no good
        {
          setallleds(0); delay(300);
          setallleds(1); delay(200);
          
        }
      //Serial.println("RTC Error!");
      delay(20000);
    }
    else
    {
      setMicrotoRTCtime();
      startupfunmain();
    }
}

void loop() 
{
  t = now();

  if(hour(t) >= 0 && hour(t) < 6)      //if its between 12am and 6 am turns off the leds
    {setallleds(0);}
   else{setleds(t);}
    
  if(hour(t) == 0 && minute(t) == 0 && second(t) <= 5) //sets the arduino system time to the rtc clock once a day at 12am
    {setMicrotoRTCtime();}
  
  delay(1000);
  
//  if(minute(t) != currentminute)        //for debugging
//    {sendMicroTimetoSerial(t); currentminute = minute(t);}  
}

void bootupwire()        //start and prime the RTC
{
  Wire.begin();
  Wire.beginTransmission(0x68); // address DS3231
  Wire.write(0x0E);             // select register
  Wire.write(0b00011100);       // write register bitmap, bit 7 is /EOSC
  Wire.endTransmission();
}

void setleds(time_t t)          //the clock section, sets all the leds according to the passed time
{
  int cminute = 0;
  int chour = 0;
  cminute = minute(t) % 10;            //set the ones place minutes
  if(cminute == 1 || cminute == 3 || cminute == 5 || cminute == 7 || cminute == 9)
     {digitalWrite(M1, HIGH);}
    else{digitalWrite(M1, LOW);}
   if(cminute == 2 || cminute == 3 || cminute == 6 || cminute == 7)
     {digitalWrite(M2, HIGH);}
    else{digitalWrite(M2, LOW);} 
  if(cminute == 4 || cminute == 5 || cminute == 6 || cminute == 7)
     {digitalWrite(M4, HIGH);}
    else{digitalWrite(M4, LOW);}
  if(cminute == 8 || cminute == 9)
     {digitalWrite(M8, HIGH);}
    else{digitalWrite(M8, LOW);}
  
  cminute = minute(t);        //set the tens place minutes
  if(cminute < 10)
    {digitalWrite(M10, LOW); digitalWrite(M20, LOW); digitalWrite(M40, LOW);}
  else if(cminute >= 10 && cminute <= 19)
        {digitalWrite(M10, HIGH); digitalWrite(M20, LOW); digitalWrite(M40, LOW);}
  else if(cminute >= 20 && cminute <= 29)
        {digitalWrite(M20, HIGH); digitalWrite(M10, LOW); digitalWrite(M40, LOW);}
  else if(cminute >= 30 && cminute <= 39)
        {digitalWrite(M20, HIGH); digitalWrite(M10, HIGH); digitalWrite(M40, LOW);}
  else if(cminute >= 40 && cminute <= 49)
        {digitalWrite(M40, HIGH); digitalWrite(M10, LOW); digitalWrite(M20, LOW);}
  else if(cminute >= 50 && cminute <= 59)
        {digitalWrite(M10, HIGH); digitalWrite(M40, HIGH); digitalWrite(M20, LOW);}
        
  //set hours
  chour = hourFormat12(t);
  if(chour == 1 || chour == 3 || chour == 5 || chour == 7 || chour == 9 || chour == 11)
     {digitalWrite(H1, HIGH);}
    else{digitalWrite(H1, LOW);}
   if(chour == 2 || chour == 3 || chour == 6 || chour == 7 || chour == 12)
     {digitalWrite(H2, HIGH);}
    else{digitalWrite(H2, LOW);} 
   if(chour == 4 || chour == 5 || chour == 6 || chour == 7)
     {digitalWrite(H4, HIGH);}
    else{digitalWrite(H4, LOW);}
   if(chour == 8 || chour == 9)
     {digitalWrite(H8, HIGH);}
    else{digitalWrite(H8, LOW);}
   if(chour == 10 || chour == 11 || chour == 12)
     {digitalWrite(H10, HIGH);}
    else{digitalWrite(H10, LOW);}    
}

void startleds()
{
  pinMode(H1, OUTPUT); pinMode(H2, OUTPUT); pinMode(H4, OUTPUT);
  pinMode(H8, OUTPUT); pinMode(H10, OUTPUT);
  
  pinMode(M1, OUTPUT); pinMode(M2, OUTPUT); pinMode(M4, OUTPUT);
  pinMode(M8, OUTPUT); pinMode(M10, OUTPUT); pinMode(M20, OUTPUT);
  pinMode(M40, OUTPUT);
  
  pinMode(MA, OUTPUT); pinMode(HA, OUTPUT); pinMode(HB, OUTPUT); pinMode(HC, OUTPUT);
}

void setallleds(int i)
{
 digitalWrite(H1, i);  digitalWrite(H2, i);  digitalWrite(H4, i); digitalWrite(H8, i);
 digitalWrite(H10, i);
 digitalWrite(M1, i);  digitalWrite(M2, i);  digitalWrite(M4, i); digitalWrite(M8, i); 
 digitalWrite(M10, i); digitalWrite(M20, i); digitalWrite(M40, i);
 
 digitalWrite(MA, i);  digitalWrite(HA, i);  digitalWrite(HB, i); digitalWrite(HC, i);
}

void startupfunmain()
{
  int delaybetween = 1000;
  
  startuptest(); delay(delaybetween);
  
  levelup();  delay(delaybetween);
  
  squarein();  delay(delaybetween);
  
  squareout();  delay(delaybetween);
  
  bugout(); delay(delaybetween);
}
  
