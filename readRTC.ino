//reads time from the RTC and either sets arduino or prints to serial monitor

void setMicrotoRTCtime()   //reads rtc and sets the system time on the arduino
{
  Serial.println("A sync with the RTC has occured.");
  byte seconds, minutes, hours, dayofweek, date, month, year;
  
  Wire.beginTransmission(RTCaddress);  
  Wire.write(0);  //start at address # 0, seconds
  Wire.endTransmission();
  Wire.requestFrom(RTCaddress, 7);
  seconds = BCDtoDEC(Wire.read() & 0x7f);
  minutes = BCDtoDEC(Wire.read());
  hours = BCDtoDEC(Wire.read() & 0x3f);
  dayofweek = BCDtoDEC(Wire.read());
  date = BCDtoDEC(Wire.read());
  month = BCDtoDEC(Wire.read());
  year = BCDtoDEC(Wire.read());
  
  setTime(hours,minutes,seconds,date,month,year);
}

void sendMicroTimetoSerial(time_t t)  //reads rtc and prints to serial monitor
{
  int seconds, minutes, hours, dayofweek, date, cmonth, cyear;
  
  seconds = second(t);
  minutes = minute(t);
  hours = hour(t);
  date = day(t);
  cmonth = month(t);
  cyear = year(t);
  
  Serial.print("Current time according to Micro is: ");
  if(hours > 12)
    {hours = hours - 12;}
  Serial.print(hours, DEC);  Serial.print(":");  
  
  if(minutes < 10)
    {Serial.print("0");}
  Serial.print(minutes, DEC); Serial.print(":");  
  
  if(seconds < 10)
    {Serial.print("0");}
  Serial.println(seconds, DEC);
  
  Serial.print("Current date according to Micro is: ");
  Serial.print(cmonth, DEC);  Serial.print("/");  Serial.print(date, DEC); Serial.print("/"); Serial.println(cyear, DEC);
}

byte BCDtoDEC(byte value)
{
  return((value/16*10) + (value%16));
}

byte DECtoBCD(byte value)
{
  return((value/10*16) + (value%10));
}
