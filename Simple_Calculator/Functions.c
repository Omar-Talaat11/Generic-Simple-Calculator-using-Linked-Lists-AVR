/*
 * Functions.c
 *
 *  Created on: Oct 5, 2023
 *      Author: Ahmed
 */



int add(int a,int b){
	return a+b;
}

int sub(int a,int b){
	return a-b;
}

int mul(int a, int b){
	return a*b;
}

int division(int a,int b){
	return a/b;
}

int operation(int (*ptr_func)(int,int),int a,int b)
{
	return (*ptr_func)(a,b);
}
