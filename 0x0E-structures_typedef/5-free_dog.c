#include "dog.h"
#include <stdlib.h>
/**
 * free_dog - frees memory of structure dogs
 * @d: pointer of structure
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
void free_dog(dog_t *d)
{
	if (d->name != 0)
		free(d->name);
	if (d->owner != 0)
		free(d->owner);
	if (d != 0)
		free(d);
}
