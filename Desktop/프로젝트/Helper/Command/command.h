#ifndef __COMMAND_H__
#define __COMMAND_H__

#include <Arduino.h>

int count = 0;
int total = 0;

void command(char ch)
{

	switch (ch)
	{
	case 'I':
		Serial.println("Welcome to the Restaurant");
		break;
	case 'O':
		Serial.println("See you again");
		break;
	case 'P':
		count++;
		break;
	case 'E':
		Serial.print("Entry People : ");
		Serial.println(count);
		total += count;
		count = 0;
		break;
	case 'T':
		Serial.print("The total number : ");
		Serial.println(total);
		break;
	case 'N':
		total = 0;
		Serial.println("The total number is initialize ");
		break;
	}
}

#endif