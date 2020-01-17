#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
    hash_table_t *ht;
    int size = 1024;
    char *key;

    ht = hash_table_create(size);
    hash_table_print(ht);
    hash_table_set(ht, "c", "fun");
    hash_table_set(ht, "python", "awesome");
    hash_table_set(ht, "Jennie", "and Jay love asm");
    hash_table_set(ht, "N", "queens");
    hash_table_set(ht, "Asterix", "Obelix");
    hash_table_set(ht, "Betty", "Holberton");
    hash_table_set(ht, "98", "Battery Street");


    key = "hetairas";
    hash_table_set(ht, key, "Het");
    printf("%lu Id\n", key_index((unsigned char *)key, size));

    key = "mentioner";
    hash_table_set(ht, key, "Met");
    printf("%lu Id\n", key_index((unsigned char *)key, size));


    key = "depravement";
    hash_table_set(ht, key, "depra");
    printf("%lu Id\n", key_index((unsigned char *)key, size));

    key = "serafins";
    hash_table_set(ht, key, "sera");
    printf("%lu Id\n", key_index((unsigned char *)key, size));


    hash_table_print(ht);

    return (EXIT_SUCCESS);
}
