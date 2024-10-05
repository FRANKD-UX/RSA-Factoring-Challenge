#include <stdio.h>
#include <stdlib.h>

/**
 * is_prime - checks if a number is prime
 * @n: the number to check
 * Return: 1 if prime, 0 otherwise
 */
int is_prime(long n)
{
	long i;

	if (n < 2)
		return (0);
	for (i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
			return (0);
	}
	return (1);
}

/**
 * factorize - finds the prime factors of a number n
 * @n: the number to factorize
 */
void factorize(long n)
{
	long p, q;

	for (p = 2; p * p <= n; p++)
	{
		if (n % p == 0)
		{
			q = n / p;
			if (is_prime(p) && is_prime(q))
			{
				printf("%ld=%ld*%ld\n", n, q, p);
				return;
			}
		}
	}
}

/**
 * main - reads input from a file and factors the number
 * @argc: the number of arguments
 * @argv: the argument vector
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char *argv[])
{
	FILE *fp;
	long n;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		return (1);
	}

	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		perror("Error opening file");
		return (1);
	}

	if (fscanf(fp, "%ld", &n) != 1)
	{
		fprintf(stderr, "Error reading number\n");
		fclose(fp);
		return (1);
	}
	fclose(fp);

	factorize(n);

	return (0);
}

