#include<stdio.h>

/**
 * Anchor - prints You're beat! and yet, you must
 * allow,\nI bore my house upon my back!\n before
 *  the main function is executed.
 */
void anchor(void) __attribute__ ((constructor));

/**
 * anchor - implementation of anchor
 * execution of a function
*/
void anchor(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
