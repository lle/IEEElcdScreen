// Variable which replicate the address of the cursor position on the screen
volatile unsigned int charAddress = 0;

#ifndef screenDelay
	screenDelay = 100;
#endif

// Send command to screen using standard delay
void screenCommand(char i)
{
	// Set PORT
	PORTC &= ~_BV(PC0);	// RS = 0
	PORTC &= ~_BV(PC1);	// RW = 0
	PORTD = i;
	_delay_ms(screenDelay);

	// Enable 0>1>0
	PORTC |= _BV(PC2);
	_delay_ms(screenDelay);
	PORTC &= ~_BV(PC2);
	_delay_ms(screenDelay);
}

void screenPos(unsigned int position)
{
	// Set PORT
	PORTC &= ~_BV(PC0);	// RS = 0
	PORTC &= ~_BV(PC1);	// RW = 0
	PORTD = 0b10000000 | position;
	charAddress = position;
	_delay_ms(screenDelay);

	// Enable 0>1>0
	PORTC |= _BV(PC2);
	_delay_ms(screenDelay);
	PORTC &= ~_BV(PC2);
	_delay_ms(screenDelay);	
}


void screenWrite(char i)
{
	// Check if screen has reached address limit
	if(charAddress==0x10)
	{	
		charAddress = 0x40;
		screenPos(0x40);
	}
	else if(charAddress==0x50)
	{	
		charAddress = 0x00;
		screenPos(0x00);
	}

	// Set PORT
	PORTC |= _BV(PC0);	// RS = 1
	PORTC &= ~_BV(PC1);	// RW = 0
	PORTD = i;
	charAddress++;
	_delay_ms(screenDelay);

	// Enable 0>1>0
	PORTC |= _BV(PC2);
	_delay_ms(screenDelay);
	PORTC &= ~_BV(PC2);
	_delay_ms(screenDelay);	
}

void screenClear()
{
	screenCommand(0b00000001);
}

void screemReturn()
{
	screenCommand(13);
}

void screenSet()
{
	// Set PORT
	DDRD = 0xFF;
	DDRC = 0xFF;
	PORTD = 0x00;
	PORTC &= ~_BV(PC0);	// RS = 0
	PORTC &= ~_BV(PC1);	// RW = 0
	PORTC &= ~_BV(PC2);	//Enable = 0
	_delay_ms(20);

	// WakeUp 1,2 and 3
	screenCommand(0b00110000);
	_delay_ms(20);
	screenCommand(0b00110000);
	_delay_ms(20);
	screenCommand(0b00110000);
	_delay_ms(20);

	// Set
	screenCommand(0b00111111);
	screenCommand(0b00001100);
	screenClear();
}
