#include <stdlib.h>
#include "dog.h"

/**
* init_dog -  initialize a variable of type struct dog.
* @d: Pointer to the structure to initialize.
* @name: The name of the dog.
* @age: The age of the dog.
* @owner: The owner of the dog.
*
* Return: None (void).
*/
void init_dog(struct dog *d, char *name, float age, char *owner)
{
if (d == NULL)
return;

d->name = name;
d->age = age;
d->owner = owner;
}
