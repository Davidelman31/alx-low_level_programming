/**
 * _strspn - will be a function that gets the length of a prexif substring.
 *
 * @s: is a pointer to string input
 * @accept: substring prefix input to look for
 *
 * Return: Always 0
 */
unsigned int _strspn(char *s, char *accept)
{
	int i, j, f;

	i = 0;
	while (s[i] != '\0')
	{
		j = 0;
		f = 1; /*status of flag*/
		while (accept[j] != '\0')
		{
			if (s[i] == accept[j])
			{
				f = 0; /*shows success*/
				break;
			}
			j++;
		}
		if (f == 1)
			break;
		i++;
	}

	return (i);
}
