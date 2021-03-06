/*

This example can say a number from zero to 999999999, speaking not only the digit
but also the value (hundreds, thousands, millions). Thanks you Matt for making it.

The "100+ Word" Arduino Audio Shield! Speak Arduino, Speak!
by Patrick Thomas Mitchell
http://www.engineeringshock.com/100-word-arduino-audio-shield.html

Example by Matt Ganis (matt.ganis@gmail.com) or @mattganis on Twitter


Copyright (c) 2018 Matt Ganis

This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses>
*/

/*
 * Mar 19, 2018 - Added underscores to work with v2.1.0 of library
 * -LeRoy Miller
 * This will also work for the 100+ Word Shield using either chip
	Cleaned up code a little, corrected a issue that zero was being said if 
thousands or millions ended in zero.

 */

/* LBT Arduino UNO Hookup
 * LBT CS to Arduino PIN 10 
 * LBT SC to Arduino PIN 13 
 * LBT DI to Arduino PIN 11
 */

/*
 * The HAM chip is missing AM and PM, was setAMPM removed, and times are only
 * given in 24 hour/Military style
 */

#include "Word100Ham.h"; //Works with the 100+ Word Shield and Ham chip

#define CS_PIN 10 //CS pin of your device.

Word100ham Word100(CS_PIN); //use with 100+ Word Shield Ham chip

void setup() {
  
Serial.begin(9600);
Word100.begin();
delay(1000);

}

void loop() {
long num;

  num = 95347834; //Any number from 0 to 999999999  There is no error checking
  Word100.sayNumber(num);

delay(2000);

  Word100.setAMPM(false); //Military/24 HR times 
  Word100.sayHours(13);
  Word100.sayMinutes(37); 
    
delay(2000);
 
  Word100.sayHours(1);
  Word100.sayMinutes(37); 

   while (1) {}
  
}



 



