#include "dog.h"
#include <stdio.h>
/**
 * print_dog - prints a struct dog
 * @d: Pointer to struct
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
void print_dog(struct dog *d)
{
	if (d != 0)
	{
		if ((*d).name != 0)
			printf("Name: %s\n", (*d).name);
		else
			printf("Name: (nil)\n");
		if ((*d).age != 0)
			printf("Name: %f\n", (*d).age);
		else
			printf("Name: (nil)\n");
		if ((*d).owner != 0)
			printf("Name: %s\n", (*d).owner);
		else
			printf("Name: (nil)\n");
	}
}
