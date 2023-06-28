#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1024

void factorial(char *token);

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

	(void)**argv;
	if (argc != 2)
	{
		fprintf(stderr, "Usage: factors <file>\n");
		exit(EXIT_FAILURE);
	}

	f = fopen(argv[1], "r");
	if (f == NULL)
	{
		fprintf(stderr, "Unable to open %s\n", argv[1]);
		 exit(EXIT_FAILURE);
	}

	while(fgets(s, sizeof(s), f) != NULL)
	{
		char *token;

		token = strtok(s, " \n");
		factorial(token);
	}
	fclose(f);
	return (0);
}

void factorial(char *token)
{
	u_int64_t n, q, p;

	n = atoi(token);
	printf("%lu\n", n);

	for (q = 2; n % q != 0; q++)
		;
	p = n / q;

	printf("%lu=%lu*%lu\n", n, p, q);
}
