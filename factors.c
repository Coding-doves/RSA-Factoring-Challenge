#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1024

int factorial(char *token);

/**
 * main - entry point
 * @argc: number of argument
 * @argv: argument
 * Return: 0
 */
int main(int argc, char **argv)
{
	FILE *f;
	char s[SIZE];

	if (argc != 2)
	{
		fprintf(stderr, "Usage: factors <file>\n");
		exit(EXIT_FAILURE);
	}

	f = fopen(argv[1], "r");
	if (f == NULL)
	{
		fprintf(stderr, "Error: Unable to open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(s, sizeof(s), f) != NULL)
	{
		factorial(s);
	}
	fclose(f);
	return (0);
}

/**
 * factorial - find factorial of n
 * @s: num to factor
 */
int factorial(char *s)
{
	u_int64_t n, q, p;

	n = atoi(s);

	for (q = 2; n % q != 0; q++)
		;
	p = n / q;

	printf("%lu=%lu*%lu\n", n, p, q);
	
	return (0);
}
