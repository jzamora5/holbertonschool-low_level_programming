#include "hash_tables.h"

/**
 * key_index - gives you the index of a key
 * @key: key
 * @size: size of the array of the hash table
 *
 * Return: index at which the key/value pair should be stored in
 * the array of the hash table
 *
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash;
	unsigned long int index;

	if (key == NULL || size == 0)
		return (0);

	hash = hash_djb2(key);
	index = hash % size;

	return (index);
}
