#include "dog.h"
#include <stdlib.h>
/**
 * init_dog - writes the character c to stdout
 * @d: Dog
 * @name: Dog name
 * @age: dog age
 * @owner: Dog owner
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d != 0)
	{
		d->name = name;
		d->age = age;
		d->owner = owner;
	}
}
