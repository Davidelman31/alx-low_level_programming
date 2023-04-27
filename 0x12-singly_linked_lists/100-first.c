#include<stdio.h>

/**
 * Anchor - prints You're beat! and yet, you must 
 * allow,\nI bore my house upon my back!\n before
 *  the main function is executed.
 */
void myStartupFun(void) __attribute__ ((constructor));

/**
 * Anchor - implementation of myStartupFun
 */
void anchor(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
