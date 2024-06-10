/*
 * main.c
 *
 *  Created on: Oct 5, 2023
 *      Author: Ahmed
 */

#include "keypad.h"
#include "lcd.h"
#include "std_types.h"
#include "linked_list.h"
#include "Functions.h"

void get_String(uint8* word);

void fillList(uint8 *str);



int main(void)
{
	uint8 word[16];
	LCD_init();


	while (1)
	{
		get_String(word);
		//LCD_displayString(word);
		fillList(word);
		calc1();
		calc2();
		while(KEYPAD_getPressedKey() != 13);
		LCD_clearScreen();


	}

}

void fillList(uint8 *str)
{
	uint8 i =0;
	uint32 sum=0;
	while(str[i] != '=')
	{

		if ((str[i]>=48) && (str[i]<=57))
		{
			sum = sum + (str[i] -48) ;
			if ((str[i+1]>=48) && (str[i+1]<=57))
			{
				sum *=10;
			}
			else
			{
				insertAtLast(sum);
				sum =0;
			}
		}
		else
		{
			sum += str[i];
			insertAtLast(sum);
			sum = 0;
		}
		i++;
	}
	//printList();
}

void get_String(uint8* word)
{
	uint8 button,i=0;

	do
	{
		button = KEYPAD_getPressedKey();


		if ((button == '+') || (button == '-') || (button == '*') || (button == '%') || (button == '='))
		{
			if (button != '=') LCD_displayCharacter(button);
			word[i] = button;
		}
		else
		{

			LCD_intgerToString(button);
			word[i] = button+48;
		}
		i++;

	}
	while(button != '=');
}
