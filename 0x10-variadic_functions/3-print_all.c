#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * tchar - prints variadic argument char
 * @list: variadic list
 *
 * Return: No return
 */
void tchar(va_list list)
{
	printf("%c", va_arg(list, int));
}
/**
 * tint - prints variadic argument int
 * @list: variadic list
 *
 * Return: No return
 */
void tint(va_list list)
{
	printf("%i", va_arg(list, int));
}
/**
 * tfloat - prints variadic argument float
 * @list: variadic list
 *
 * Return: No return
 */
void tfloat(va_list list)
{
	printf("%f", va_arg(list, double));
}
/**
 * tstring - prints variadic argument string
 * @list: variadic list
 *
 * Return: No return
 */
void tstring(va_list list)
{
	char *tmp;

	tmp = va_arg(list, char *);
	if (tmp == 0)
		tmp = "(nil)";
	printf("%s", tmp);
}
/**
 * print_all - prints anything
 * @format: list of types of arguments passed to the function
 * @...: Arguments Variadic
 *
 * Return: No return
 */
void print_all(const char * const format, ...)
{
	ftype fa[] = {
		{"c", tchar},
		{"i", tint},
		{"f", tfloat},
		{"s", tstring}
	};

	int l1 = 0, l2 = 0;
	va_list list;
	char *comma = "";

	va_start(list, format);
	while (format && format[l1])
	{
		l2 = 0;
		while (l2 < 4)
		{
			if (format[l1] == fa[l2].tc[0])
			{
				printf("%s", comma);
				fa[l2].tf(list);
				comma = ", ";
			}
			l2++;
		}
		l1++;
	}
	printf("\n");
	va_end(list);
}
