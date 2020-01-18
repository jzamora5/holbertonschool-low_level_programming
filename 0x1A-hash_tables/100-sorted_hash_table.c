#include "hash_tables.h"

/**
 * shash_table_create - creates a shash table
 * @size: size of the array
 *
 * Return: a pointer to the newly created hash table
 * NULL if something went wrong
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *shash_table;

	shash_table = malloc(sizeof(shash_table_t));
	if (!shash_table)
		return (NULL);

	shash_table->size = size;
	shash_table->array = calloc(size, sizeof(shash_node_t *));
	if (!(shash_table->array))
	{
		free(shash_table);
		return (NULL);
	}

	shash_table->shead = NULL;
	shash_table->stail = NULL;

	return (shash_table);
}

/**
 * add_sorted_ht_key - adds node in sorted linked ht list
 * @ht: hast table
 * @shnode: node to add based on key (ASCII value)
 *
 * Return: a pointer to the newly created hash table
 * NULL if something went wrong
 */
void add_sorted_ht_key(shash_table_t *ht, shash_node_t *shnode)
{
	shash_node_t *tmp = ht->shead, *tmp2;

	if (!ht->shead || strcmp(shnode->key, ht->shead->key) <= 0)
	{
		shnode->snext = ht->shead;
		if (ht->shead)
			ht->shead->sprev = shnode;
		if (!(ht->stail))
			ht->stail = shnode;
		ht->shead = shnode;
		return;
	}

	tmp2 = tmp->snext;
	while (tmp && tmp2 && strcmp(shnode->key, tmp2->key) > 0)
		tmp = tmp->snext, tmp2 = tmp->snext;

	tmp->snext = shnode;
	shnode->snext = tmp2;
	shnode->sprev = tmp;
	if (tmp2)
		tmp2->sprev = shnode;
	else
		ht->stail = shnode;

}
/**
 * shash_table_set - adds an element to the shash table
 * @ht: hash table
 * @key: key for hash table
 * @value: value for key
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *shnode = NULL, *collnode = NULL;
	unsigned long int index;
	char *valuedup = NULL, *keydup = NULL;

	if (!ht || !(ht->array) || !key || !key[0] || !value)
		return (0);

	index = key_index((unsigned char *)key, ht->size);
	shnode = ht->array[index];
	valuedup = strdup(value);
	if (!valuedup)
		return (0);
	while (shnode != NULL)
	{
		if (!strcmp(shnode->key, key))
		{
			free(shnode->value);
			shnode->value = valuedup;
			return (1);
		}
		shnode = shnode->next;
	}

	shnode = ht->array[index];
	collnode = malloc(sizeof(shash_node_t));
	if (collnode == NULL)
		return (free(valuedup), 0);
	keydup = strdup(key);
	if (!keydup)
		return (free(valuedup), free(collnode), 0);

	collnode->key = keydup;
	collnode->value = valuedup;
	collnode->next = shnode;
	collnode->sprev = NULL, collnode->snext = NULL;
	ht->array[index] = collnode;
	add_sorted_ht_key(ht, collnode);

	return (1);
}
/**
 * shash_table_get - retrieves an element from the shash table
 * @ht: hash table
 * @key: key for hash table
 *
 * Return: Pointer to element or NULL if failed
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *shnode = NULL;
	unsigned long int index;

	if (!ht || !(ht->array) || !key || !key[0])
		return (NULL);

	index = key_index((unsigned char *)key, ht->size);
	shnode = ht->array[index];

	while (shnode != NULL)
	{
		if (!strcmp(shnode->key, key))
			return (shnode->value);

		shnode = shnode->next;
	}

	return (NULL);
}
/**
 * shash_table_print - prints the hash table using the sorted linked list
 * @ht: hash table
 *
 * Return: No Return
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *hkey;
	int comma = 0;

	if (!ht || !(ht->array) || !(ht->shead))
		return;

	hkey = ht->shead;
	printf("{");
	while (hkey)
	{
		if (comma)
			printf(", ");
		printf("'%s': '%s'", hkey->key, hkey->value);
		comma = 1;
		hkey = hkey->snext;
	}
	printf("}\n");

}
/**
 * shash_table_print_rev - prints the hash table using the sorted linked list
 * but in reverse
 * @ht: hash table
 *
 * Return: No Return
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *hkey;
	int comma = 0;

	if (!ht || !(ht->array) || !(ht->stail))
		return;

	hkey = ht->stail;
	printf("{");
	while (hkey)
	{
		if (comma)
			printf(", ");
		printf("'%s': '%s'", hkey->key, hkey->value);
		comma = 1;
		hkey = hkey->sprev;
	}
	printf("}\n");

}
/**
 * shash_table_delete - frees a shash table
 * @ht: hash table
 *
 * Return: No Return
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *shnode, *tmp;
	unsigned long int i;

	if (!ht || !(ht->array))
		return;

	for (i = 0; i < ht->size; i++)
	{
		shnode = ht->array[i];
		while (shnode)
		{
			tmp = shnode->next;
			free(shnode->key);
			free(shnode->value);
			free(shnode);
			shnode = tmp;
		}
	}
	free(ht->array);
	free(ht);
}
