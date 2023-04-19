#include "main.h"
		
/**
 * _isalpha - function checking for alphabetic character.
 * @c: the char to check.
 * Return: 1 if c is a letter, otherwise 0.
 */
int _isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
