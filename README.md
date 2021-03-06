# Make a Digital Timer!
 
## Overview
For this assignment, you are going to 

A) [Solder your LCD panel](#part-a-solder-your-lcd-panel)

B) [Write text to an LCD Panel](#part-b-writing-to-the-lcd) 

c) [Using a time-based digital sensor!](#part-c-using-a-time-based-digital-sensor)

D) [Make your Arduino sing!](#part-d-make-your-arduino-sing)

E) [Make your own timer](#part-e-make-your-own-timer) 
 
## In The Report
Include your responses to the bold questions on your own fork of [this lab report template](https://github.com/FAR-Lab/IDD-Fa18-Lab2). Include snippets of code that explain what you did. Deliverables are due next Tuesday. Post your lab reports as README.md pages on your GitHub, and post a link to that on your main class hub page.

## Part A. Solder your LCD panel

**Take a picture of your soldered panel and add it here!**

![alt text](https://github.com/contactkoh/IDD-Fa18-Lab2/blob/master/solder.jpg)

## Part B. Writing to the LCD
 
 
**a. What voltage level do you need to power your display?**
   5 V (Power supply for logic operating, p.5 of the LCM module specification. VDD on LED)
   
**b. What voltage level do you need to power the display backlight?**
   3 V  (LED Backlight operating voltage, p.5 of the LCM module specification. A on LED) 
   
**c. What was one mistake you made when wiring up the display? How did you fix it?**
   Almost forgot to connect the separate backlight Led power. There were too many wires I was using so it was hard to keep track of which one goes to which. Eventually, I found out that I needed to make a separate power for the Backlight for 3V which resolved the issue.  
   Also, I almost didn't know that the LCD module specification cautioned to use 3 V for LED Backlight. (Athe specification p.5 seemed to have some conflicting info which I must be careful about). Eventually, I was able to read more info on specification (warning about not to use the 5V for backlight led) and was able to resolve it. 
   
**d. What line of code do you need to change to make it flash your name instead of "Hello World"?**
      lcd.print("hello, world!");  change it to -->   lcd.print("Hello, Hongyun!"); 
      I didn't need to change the columns and rows numbers as my name didn't go past the current lines.
      
![alt text](https://github.com/contactkoh/IDD-Fa18-Lab2/blob/master/lcd_name.jpg)
      
**e. Include a copy of your Lowly Multimeter code in your lab write-up.**
 See attached. [LCD_display] (https://github.com/contactkoh/IDD-Fa18-Lab2/blob/master/LCD_display.ino) lcd_display file.
(Reference:  Arduino LiquidCrystal, Analog, LED Libraries)

![alt text](https://github.com/contactkoh/IDD-Fa18-Lab2/blob/master/multimeter.jpg)


## Part C. Using a time-based digital sensor

**Upload a video of your working rotary encoder here.**

[Rotary Encoder working] (https://youtu.be/nsMVNokiOHY) Rotary Encoder working


## Part D. Make your Arduino sing!

**a. How would you change the code to make the song play twice as fast?**

Each note lasts for the duration time. So I changed " int pauseBetweenNotes = noteDuration * 1.30;"  to 
    "int pauseBetweenNotes = noteDuration * 0.65; " because 1.3 / 2 = 0.65 and each note is now played during half the time, making the song play twice as fast. 

 
**b. What song is playing?**
Some tune that is different and more like a music. Unfortunately, I am do not know the song name but it sounded like this(pardon the low volumn)  [song test] (https://youtu.be/ckeXKtqxC6w) song test



## Part E. Make your own timer

**a. Make a short video showing how your timer works, and what happens when time is up!**
[Timer with Blink] https://youtu.be/2PlKkVtlFQE  Timer with Blink

Press and hold the button for x seconds and then lift finger off. The count down runs for x seconds and Blue LED blinks twice. 
(Code is uploaded. LCD_display_Timer.ino)
The exact timing and while loops implementation could use some more improvement later. 

**b. Post a link to the completed lab report your class hub GitHub repo.**
Link has been posted. 
