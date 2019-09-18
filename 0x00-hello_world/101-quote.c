#include <stdio.h>
#include <unistd.h>
/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char* s="write and that piece of art is useful\" - Dora Korpar, 2015-10-19\n";
	write(2,s,65);
	return (1);
}
