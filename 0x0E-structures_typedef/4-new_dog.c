#include "dog.h"
#include <stdlib.h>
/**
 * new_dog - creates a new dog
 * @name: name of dog
 * @age: age of dog
 * @owner: owner of dog
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	int ln = 0, lo = 0, i, j;
	char *namec, *ownerc;
	dog_t *new_dog;

	new_dog = malloc(sizeof(struct dog));

	while (name[ln] != 0)
		ln++;
	while (owner[lo] != 0)
		lo++;
	namec = malloc(ln + 1);
	ownerc = malloc(lo + 1);
	if (new_dog == 0 || namec == 0 || ownerc == 0)
		return (0);
	for (i = 0; i <= ln; i++)
		namec[i] = name[i];
	for (j = 0; j <= lo; j++)
		ownerc[j] = owner[j];
	new_dog->name = name;
	new_dog->age = age;
	new_dog->owner = owner;
	return (new_dog);
}
