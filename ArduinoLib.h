/*
Arduino like library
Chetan Bhargava
*/

#define OUTPUT 1
#define INPUT 0

#define HIGH 1
#define LOW 0
#define OUTPUT 1
#define INPUT 0
#define HIGH  1
#define LOW  0
#define LSBFIRST 0
#define MSBFIRST 1


//Prototypes
void digitalWrite(int, int);
void pinMode(int, int);
void shiftOut(int, int, int, int);
int digitalRead(int);

/////////////  Tested works
// Tested on target - Works
void pinMode(int pin, int value)  		{
    switch (value) {
	  case 0: P1DIR &= pin;
	  case 1: P1DIR |= pin;	
    }
}

void digitalWrite(int pin, int value)	{
    if (value==HIGH)
        P1OUT |= (pin);
    else if (value==LOW)
        P1OUT &= ~(pin);
}

///////////// Under Test
void shiftOut(int dataPin, int clockPin, int bitOrder, int val) {
    int i;
    for (i = 0; i < 8; i++)  {
        if (bitOrder == LSBFIRST)
            digitalWrite(dataPin, !!(val & (1 << i)));
        else
            digitalWrite(dataPin, !!(val & (1 << (7 - i))));

        digitalWrite(clockPin, HIGH);
        digitalWrite(clockPin, LOW);
    }
}

int shiftIn(int dataPin, int clockPin, int bitOrder) {
    int value = 0;
    int i;

    for (i = 0; i < 8; ++i) {
        digitalWrite(clockPin, HIGH);
            if (bitOrder == LSBFIRST)
                value |= digitalRead(dataPin) << i;
            else
                value |= digitalRead(dataPin) << (7 - i);
        digitalWrite(clockPin, LOW);
    }
    return value;
}


int digitalRead(int pin)
{
        /*
        int timer = digitalPinToTimer(pin);
        int bit = digitalPinToBitMask(pin);
        int port = digitalPinToPort(pin);

        if (port == NOT_A_PIN) return LOW;

        // If the pin that support PWM output, we need to turn it off
        // before getting a digital reading.
        if (timer != NOT_ON_TIMER) turnOffPWM(timer);

        if (*portInputRegister(port) & bit) return HIGH;
        */
        return LOW;
}
