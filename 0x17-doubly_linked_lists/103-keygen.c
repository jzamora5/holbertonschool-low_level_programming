#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - crackme5 keygen
 *
 * @ac: count of cmd line args
 * @av: cmd line args
 *
 * Return: 0 on Success
 */
int main(int ac, char **av)
{
	char pwd[7];
	char *s = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";
	int len = strlen(av[1]), i, f;

	(void) ac;
	pwd[6] = '\0';
	/* Function 1 */
	pwd[0] = s[(len ^ 59) & 63];
	/* Function 2 */
	for (i = 0, f = 0; i < len; i++)
		f += av[1][i];
	pwd[1] = s[(f ^ 79) & 63];
	/* Function 3 */
	for (i = 0, f = 1; i < len; i++)
		f *= av[1][i];
	pwd[2] = s[(f ^ 85) & 63];
	/* Function 4 */
	for (i = 0, f = av[1][0]; i < len; i++)
		if (av[1][i] > f)
			f = av[1][i];
	srand(f ^ 14);
	pwd[3] = s[rand() & 63];
	/* Function 5 */
	for (i = 0, f = 0; i < len; i++)
		f += av[1][i] * av[1][i];
	pwd[4] = s[(f ^ 239) & 63];
	/* Function 6 */
	for (i = 0, f = 0; i < av[1][0]; i++)
		f = rand();
	pwd[5] = s[(f ^ 229) & 63];
	for (i = 0; pwd[i]; i++)
		printf("%c", pwd[i]);
	return (0);
}
