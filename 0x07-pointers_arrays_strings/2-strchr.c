/**
 * _strchr - locates a character in a string
 *
 * @s: is a pointer to our string array
 * @c: is a character to locate from input array
 *
 * Return: Always 0 (Shows success)
 */

char *_strchr(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return (s);
		s++;
	}
	/**
	 * if value of c is '\0', you should return
	 * the pointer to the '\0' of the string s
	 */

	if (*s == c)
		return (s);
	/*always return null if not found*/
	return ('\0');

}
