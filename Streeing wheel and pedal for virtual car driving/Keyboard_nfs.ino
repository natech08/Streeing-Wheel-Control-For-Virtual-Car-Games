/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
   
 Modified by Utsav Moradiya 
 contributed by Ankit Nagda
  
*/
#define Acc 2
#define Brake 3
#define Str_l 4
#define Str_r 5
#define lap 6
#define gear 7
#define nitro 8



#define w 27//up 
#define b 6//space  
#define a 4//left 
#define d 8//right 
#define g 11//g 
#define s 23//down 
#define x 28//alt 


#define t 600






/* Arduino USB Keyboard HID demo
   Volume+/Volume-/Mute keys
*/

uint8_t buf[8] = { 0 };   /* Keyboard report buffer */



void releaseKey()
{
  buf[0] = 0;
  buf[2] = 0;
  Serial.write(buf, 8); // Release key
}

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  digitalWrite(2, 1);
  digitalWrite(3, 1);
  digitalWrite(4, 1);
  digitalWrite(5, 1);
  digitalWrite(6, 1);
  digitalWrite(7, 1);
  digitalWrite(8, 1);
  delay(200);
}

// the loop function runs over and over again forever
void loop() {
  if (digitalRead(Acc) == LOW)
  { if (digitalRead(Str_l) == LOW)
    { if (digitalRead(nitro) == LOW)
      { buf[2] = x;   // Mute key
        Serial.write(buf, 8);
        buf[2] = w ;   // up button
        Serial.write(buf, 8);
        buf[2] = a;   // Mute key
        Serial.write(buf, 8); // Send keypress
      }
      else if (digitalRead(nitro) == HIGH)
      { buf[2] = w ;   // up button
        Serial.write(buf, 8);
        buf[2] = a;   // Mute key
        Serial.write(buf, 8); // Send keypress
      }
    }
    if (digitalRead(Str_r) == LOW)
    { if (digitalRead(nitro) == LOW)
      { buf[2] = x;   // Mute key
        Serial.write(buf, 8);
        buf[2] = w ;   // up button
        Serial.write(buf, 8);
        buf[2] = d;   // Mute key
        Serial.write(buf, 8); // Send keypress
      }
      else if (digitalRead(nitro) == HIGH)
      { buf[2] = w ;   // up button
        Serial.write(buf, 8);
        buf[2] = d;   // Mute key
        Serial.write(buf, 8); // Send keypress
      }
    }
    if (digitalRead(nitro) == LOW)
    { buf[2] = x;   // Mute key
      Serial.write(buf, 8);
      buf[2] = w;   // up button
      Serial.write(buf, 8);
    }
    else
    { buf[2] = w ;   // up button
      Serial.write(buf, 8);
    }
    delay(t);
  }



  if (digitalRead(Brake) == HIGH)
  { if (digitalRead(Str_l) == LOW)
    { if (digitalRead(nitro) == LOW)
      { buf[2] = x;   // Mute key
        Serial.write(buf, 8);
        buf[2] = s ;   // up button
        Serial.write(buf, 8);
        buf[2] = a;   // Mute key
        Serial.write(buf, 8); // Send keypress
      }
      else if (digitalRead(nitro) == HIGH)
      { buf[2] = s;   // up button
        Serial.write(buf, 8);
        buf[2] = a;   // Mute key
        Serial.write(buf, 8); // Send keypress
      }
    }
    if (digitalRead(Str_r) == LOW)
    { if (digitalRead(nitro) == LOW)
      { buf[2] = x;   // Mute key
        Serial.write(buf, 8);
        buf[2] = s ;   // up button
        Serial.write(buf, 8);
        buf[2] = d;   // Mute key
        Serial.write(buf, 8); // Send keypress
      }
      else if (digitalRead(nitro) == HIGH)
      { buf[2] = s;   // up button
        Serial.write(buf, 8);
        buf[2] = d;   // Mute key
        Serial.write(buf, 8); // Send keypress
      }
    }
    if (digitalRead(nitro) == LOW)
    { buf[2] = x;   // Mute key
      Serial.write(buf, 8);
      buf[2] = s;   // up button
      Serial.write(buf, 8);
    }
    else
    { buf[2] = s ;   // up button
      Serial.write(buf, 8);
    }
    delay(t);
  }








  else
  {
    releaseKey();
  }



}
