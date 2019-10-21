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
	struct dog *dog_t;

	dog_t = malloc(sizeof(struct dog));
	if (dog_t == 0)
		return (0);
	dog_t->name = name;
	dog_t->age = age;
	dog_t->owner = owner;
	return (dog_t);

}
