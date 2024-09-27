#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * factorize - Factorize a number into a product of two smaller numbers
 * @n: The number to factorize
 *
 * Description: This function takes a natural number and outputs the product
 * of two smaller numbers (p and q) such that n = p * q.
 */
void factorize(unsigned long n)
{
	unsigned long p, q;

	for (p = 2; p <= n / 2; p++)
	{
		if (n % p == 0)
		{
			q = n / p;
			printf("%lu=%lu*%lu\n", n, q, p);
			return;
		}
	}
	printf("%lu=%lu*1\n", n, n);
}

/**
 * main - Entry point of the program
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Description: The main function reads a file containing natural numbers and
 * factorizes each number using the factorize function.
 *
 * Return: 0 on success, or 1 if an error occurs
 */
int main(int argc, char *argv[])
{
	FILE *file;
	unsigned long num;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		return (1);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Could not open file %s\n", argv[1]);
		return (1);
	}

	while (fscanf(file, "%lu", &num) != EOF)
	{
		factorize(num);
	}

	fclose(file);
	return (0);
}

