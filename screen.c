#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
#include <string.h>

#define sleep1 1500
#define screenDelay 10
#include "screenControl.h"

int main()
{
	screenSet();
	while(1)
	{
		screenPos(6);
		char*  text1="IEEE\n";	
		for(int i=0; i<strlen(text1)-1; i++)
		{
			screenWrite(text1[i]);
		}
		screenPos(67);

		text1="Concordia\n";	
		for(int i=0; i<strlen(text1)-1; i++)
		{
			screenWrite(text1[i]);
		}
		_delay_ms(sleep1);
		screenClear();
		screenPos(0);
	
		//Clear Screen

		screenPos(2);
		text1="Institute of\n";	
		for(int i=0; i<strlen(text1)-1; i++)
		{
			screenWrite(text1[i]);
		}
		_delay_ms(sleep1);
		screenClear();
		screenPos(0);

		//Clear Screen

		screenPos(1);
		text1="Electrical and\n";	
		for(int i=0; i<strlen(text1)-1; i++)
		{
			screenWrite(text1[i]);
		}
		screenPos(66);

		text1="Electronics\n";	
		for(int i=0; i<strlen(text1)-1; i++)
		{
			screenWrite(text1[i]);
		}
		_delay_ms(sleep1);
		screenClear();
		screenPos(0);

		//Clear Screen

		screenPos(4);
		text1="Engineers\n";	
		for(int i=0; i<strlen(text1)-1; i++)
		{
			screenWrite(text1[i]);
		}
		_delay_ms(sleep1);
		screenClear();
		screenPos(0);

		//Clear Screen

		text1="ieee.concordia.ca\n";	
		for(int i=0; i<strlen(text1)-1; i++)
		{
			screenWrite(text1[i]);
		}
		_delay_ms(sleep1);
		_delay_ms(sleep1);
		screenClear();
		screenPos(0);
	}


}
