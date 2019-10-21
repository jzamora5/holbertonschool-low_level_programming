#ifndef STRUCTS
#define STRUCTS
/**
 * struct dog - description for a pet
 * @name: pet name
 * @age: pet age
 * @owner: owner
 *
 * Description: Longer description
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};
#endif
#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H
int _putchar(char c);
void init_dog(struct dog *d, char *name, float age, char *owner);
#endif
