//all of the various light block related programs

void startuptest()             //turns each of the pins on one at a time to ensure theyre all working goes up each row starting on left side
{
  int hldelay = 100;
  
  digitalWrite(M1, HIGH); delay(hldelay); digitalWrite(M1, LOW); delay(hldelay);
  digitalWrite(M2, HIGH); delay(hldelay); digitalWrite(M2, LOW); delay(hldelay);
  digitalWrite(M4, HIGH); delay(hldelay); digitalWrite(M4, LOW); delay(hldelay);
  digitalWrite(M8, HIGH); delay(hldelay); digitalWrite(M8, LOW); delay(hldelay);
  digitalWrite(M10, HIGH); delay(hldelay); digitalWrite(M10, LOW); delay(hldelay);
  digitalWrite(M20, HIGH); delay(hldelay); digitalWrite(M20, LOW); delay(hldelay);
  digitalWrite(M40, HIGH); delay(hldelay); digitalWrite(M40, LOW); delay(hldelay);
  digitalWrite(MA, HIGH); delay(hldelay); digitalWrite(MA, LOW); delay(hldelay);
  
  digitalWrite(H1, HIGH); delay(hldelay); digitalWrite(H1, LOW); delay(hldelay);  
  digitalWrite(H2, HIGH); delay(hldelay); digitalWrite(H2, LOW); delay(hldelay);
  digitalWrite(H4, HIGH); delay(hldelay); digitalWrite(H4, LOW); delay(hldelay);
  digitalWrite(H8, HIGH); delay(hldelay); digitalWrite(H8, LOW); delay(hldelay);
  digitalWrite(H10, HIGH); delay(hldelay); digitalWrite(H10, LOW); delay(hldelay);
  digitalWrite(HA, HIGH); delay(hldelay); digitalWrite(HA, LOW); delay(hldelay);
  digitalWrite(HB, HIGH); delay(hldelay); digitalWrite(HB, LOW); delay(hldelay);
  digitalWrite(HC, HIGH); delay(hldelay); digitalWrite(HC, LOW); delay(hldelay);
}

void levelup()
{
  int delaytime = 250;
  
  //turn on row one
  digitalWrite(M1, HIGH);  digitalWrite(M10, HIGH);  digitalWrite(H1, HIGH);  digitalWrite(H10, HIGH);  
  delay(delaytime);
  
  //turn on row two
  digitalWrite(M2, HIGH);  digitalWrite(M20, HIGH);  digitalWrite(H2, HIGH);  digitalWrite(HA, HIGH);    
  delay(delaytime);
  
  //turn on row three
  digitalWrite(M4, HIGH);  digitalWrite(M40, HIGH);  digitalWrite(H4, HIGH);  digitalWrite(HB, HIGH);    
  delay(delaytime);
  
  //turn on row four
  digitalWrite(M8, HIGH);  digitalWrite(MA, HIGH);  digitalWrite(H8, HIGH);  digitalWrite(HC, HIGH);    
  delay(delaytime *4);
  
  //turn them back off row by row
  digitalWrite(M8, LOW);  digitalWrite(MA, LOW);  digitalWrite(H8, LOW);  digitalWrite(HC, LOW);
  delay(delaytime);
  digitalWrite(M4, LOW);  digitalWrite(M40, LOW);  digitalWrite(H4, LOW);  digitalWrite(HB, LOW);
  delay(delaytime);
  digitalWrite(M2, LOW);  digitalWrite(M20, LOW);  digitalWrite(H2, LOW);  digitalWrite(HA, LOW); 
  delay(delaytime);
  digitalWrite(M1, LOW);  digitalWrite(M10, LOW);  digitalWrite(H1, LOW);  digitalWrite(H10, LOW); 
}

void squarein()
{
  int delaytime = 1000;
  
  //square one - 1
  digitalWrite(M1, HIGH);   
  delay(delaytime);
  
  //square two - 3
  digitalWrite(M2, HIGH);  digitalWrite(M20, HIGH);  digitalWrite(M10, HIGH);   
  delay(delaytime);
  
  //square three - 5
  digitalWrite(M4, HIGH);  digitalWrite(M40, HIGH);  digitalWrite(H4, HIGH); digitalWrite(H2, HIGH);  digitalWrite(H1, HIGH);     
  delay(delaytime);
  
  //square four - 7
  digitalWrite(M8, HIGH);  digitalWrite(MA, HIGH);  digitalWrite(H8, HIGH); digitalWrite(HC, HIGH);  
  digitalWrite(HB, HIGH);  digitalWrite(HA, HIGH); digitalWrite(H10, HIGH);  
  delay(delaytime);
}

void squareout()
{
  int delaytime = 1000;
  
  //square one - 1
  digitalWrite(M8, LOW);   
  delay(delaytime);
  
  //square two - 3
  digitalWrite(MA, LOW);  digitalWrite(M40, LOW);  digitalWrite(M4, LOW);   
  delay(delaytime);
  
  //square three - 5
  digitalWrite(H8, LOW);  digitalWrite(H4, LOW);  digitalWrite(H2, LOW); digitalWrite(M20, LOW);  digitalWrite(M2, LOW);     
  delay(delaytime);
  
  //square four - 7
  digitalWrite(HC, LOW);  digitalWrite(HB, LOW);  digitalWrite(HA, LOW); digitalWrite(H10, LOW);  
  digitalWrite(H1, LOW);  digitalWrite(M10, LOW); digitalWrite(M1, LOW);
}


void bugout()
{
  int randomnumber = 0;
  int hldelay = 200;
  int countdown = 20;
  
  setallleds(1);
  
  while(countdown > 0)
  {
    randomnumber = random(16);
    
    if(randomnumber < 14 && randomnumber > 3)
        {
        digitalWrite(randomnumber, LOW);
        delay(hldelay);
        countdown = countdown - 1;
        }
      else if(randomnumber ==  14)
        {
        digitalWrite(A0, LOW);
        delay(hldelay);
        countdown = countdown - 1;
        }
      else if(randomnumber ==  15)
        {
        digitalWrite(A1, LOW);
        delay(hldelay);
        countdown = countdown - 1;
        }
      else if(randomnumber ==  0)
        {
        digitalWrite(A2, LOW);
        delay(hldelay);
        countdown = countdown - 1;
        }
      else if(randomnumber ==  1)
        {
        digitalWrite(A3, LOW);
        delay(hldelay);
        countdown = countdown - 1;
        }      
      else if(randomnumber ==  2)
        {
        digitalWrite(A4, LOW);
        delay(hldelay);
        countdown = countdown - 1;
        }
      else if(randomnumber ==  3)
        {
        digitalWrite(A5, LOW);
        delay(hldelay);
        countdown = countdown - 1;
        }
    }
    
    setallleds(0);
}

