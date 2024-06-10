/*
 ============================================================================
 Name        : Exercise2_Insert_Node_At_Last.c
 Author      : Mohamed Tarek
 Date        : 17/7/2017
 Description : Example to demonstrate how to insert a node in Linked List from the last.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "lcd.h"
#include "linked_list.h"
#include <util/delay.h>

struct node {
	int data;
	struct node *next;
	struct node *prev;

};

struct node *head = NULL;
struct node *current = NULL;
struct node *prevs = NULL;

//Create Linked List
void insertAtLast(int data)
{
	// Allocate memory for new node
	struct node *link = (struct node*) malloc(sizeof(struct node));

	// insert the data to the new node and make the next point to null
	link->data = data;
	link->next = NULL;

	// If head is empty, create new list
	if(head==NULL)
	{
		head = link;
		return;
	}

	current = head;

	// loop until reach the last node in the old list
	while(current->next != NULL)
	{
		current = current->next;
	}

	// Make the last node in the old list point to new node
	link->prev = current;
	current->next = link;
}


void printList(void)
{
	struct node *ptr = head;
	int my_Data;

	LCD_displayStringRowColumn(1,0," ");
	//start looping from the head until the last node
	while(ptr != NULL)
	{
		my_Data = ptr->data;
		if ((my_Data=='+') || (my_Data=='-') || (my_Data=='%') || (my_Data=='*')){
			LCD_displayCharacter(my_Data);
		}
		else
		{
			LCD_intgerToString(my_Data);
		}
		LCD_displayCharacter('$');
		ptr = ptr->next;
	}

}


void removeNodeFromTheList(int data)
{
	int pos = 0;
	struct node * delete_node = NULL;

	//check if the linked list is empty
	if(head==NULL)
	{
		return;
	}

	//check the first node in the linked list
	if(head->data == data)
	{
		delete_node = head;
		// move head to next node
		head = head->next;
		free(delete_node);
		return;
	}

	//check the rest of nodes in the linked list
	pos++;
	current = head->next;
	prevs = head;
	while(current != NULL)
	{
		if(current->data == data)
		{
			//element found
			delete_node = current;
			prevs->next = current->next;
			current->next->prev = prevs;
			free(delete_node);
			return;
		}
		prevs = current;
		current = current->next;
		pos++;
	}


}

void calc1 (void)
{

	struct node *ptr = head;
	int result;
	//LCD_displayStringRowColumn(1,0,"");

	//start looping from the head until the last node
	while(ptr->next != NULL)
	{
		if ((ptr->data == '%') || (ptr->data == '*'))
		{
			if (ptr->data == '%')
			{
				result = operation(division,ptr->prev->data,ptr->next->data);

			}
			else if (ptr->data == '*')
			{
				result = operation(mul,ptr->next->data,ptr->prev->data);

			}
			//LCD_intgerToString(ptr->prev->data);
			//LCD_displayCharacter('#');

			ptr->prev->data=result;
			removeNodeFromTheList(ptr->next->data);
			ptr = ptr->prev;
			removeNodeFromTheList(ptr->next->data);
		}

		if (ptr->next != NULL ){
			ptr = ptr->next;
		}
	}


}

void calc2 (void)
{

	struct node *ptr = head;
	int result;

	//start looping from the head until the last node
	while(ptr->next != NULL)
	{
		if ((ptr->data == '+') || (ptr->data == '-'))
		{
			if (ptr->data == '+')
			{
				result = operation(add,ptr->next->data,ptr->prev->data);
			}
			else if (ptr->data == '-')
			{
				result = operation(sub,ptr->prev->data,ptr->next->data);
			}

			ptr->prev->data=result;
			removeNodeFromTheList(ptr->next->data);
			ptr = ptr->prev;
			removeNodeFromTheList(ptr->next->data);
		}
		if (ptr->next != NULL ){
			ptr = ptr->next;
		}

	}
	LCD_displayStringRowColumn(1,0,"");
	LCD_displayString("Result= ");
	LCD_intgerToString(head->data);
	_delay_ms(50);
	removeNodeFromTheList(head->data);
	//printList();
}