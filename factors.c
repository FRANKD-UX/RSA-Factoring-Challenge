#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "main.h"

/**
 * find_factors - Finds two factors of a number n.
 * This function prints the factors in the format n = p * q
 * where p and q are factors of n.
 * @n: The number to factorize.
 *
 * Return: void
 */
void find_factors(unsigned long n)
{
	unsigned long i;

	/* Try to find two factors by iterating from 2 up to sqrt(n) */
	for (i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			/* We found two factors: i and n / i */
			printf("%lu=%lu*%lu\n", n, i, n / i);
			return;
		}
	}
	/* If no factors found, n is prime and can be factorized as 1*n */
	printf("%lu=%lu*1\n", n, n);
}

/**
 * main - Reads the input file and factorizes the numbers.
 * @argc: Argument count.
 * @argv: Argument vector (file path).
 *
 * Return: 0 on success, 1 on error.
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	unsigned long number;

	/* Check if the file argument is provided */
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		return (1);
	}

	/* Open the file for reading */
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		perror("Error opening file");
		return (1);
	}

	/* Read each line of the file, convert it to an integer, and factorize it */
	while (getline(&line, &len, file) != -1)
	{
		number = strtoul(line, NULL, 10);
		find_factors(number);
	}

	/* Cleanup */
	free(line);
	fclose(file);

	return (0);
}
