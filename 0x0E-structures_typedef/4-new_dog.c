#include "dog.h"
#include <stdlib.h>
/**
 * _strdup - returns a pointer to a newly allocated space in memory, which
 * contains a copy of the string given as a parameter.
 * @str: string to copy
 *
 * Return: Pointer
 */
char *_strdup(char *str)
{
	int l, i;
	char *s;

	if (str == NULL)
		return (0);

	l = 0;
	while (*(str + l))
		l++;

	s = malloc(sizeof(char) * l + 1);

	if (s == 0)
		return (0);

	for (i = 0; i <= l; i++)
	{
		*(s + i) = *(str + i);
	}
	return (s);
}
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
	dog_t *new_dog;

	new_dog = malloc(sizeof(struct dog));

	if (new_dog == 0 || name == 0 || owner == 0)
		return (0);

	new_dog->name = _strdup(name);
	if (new_dog->name == 0)
	{
		free(new_dog);
		return (0);
	}
	new_dog->age = age;
	new_dog->owner = _strdup(owner);
	if (new_dog->owner == 0)
	{
		free(new_dog);
		free(new_dog->name);
		return (0);
	}
	return (new_dog);
}
