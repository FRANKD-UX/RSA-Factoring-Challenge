#include <stdio.h>
#include <math.h>
#include "main.h"

/**
 * factorize - Finds and prints the factorization of a number
 *             in the format n=p*q where p > q.
 * @n: The number to be factorized.
 */
void factorize(unsigned long n)
{
	unsigned long p, q;
	unsigned long i;

	/* Loop through numbers from 2 to sqrt(n) */
	for (i = 2; i * i <= n; i++)
	{
		/* If i is a factor of n */
		if (n % i == 0)
		{
			q = i;
			p = n / i;

			/* Ensure the larger factor is printed first */
			if (p < q)
			{
				unsigned long temp = p;

				p = q;
				q = temp;
			}

			/* Print the factorization */
			printf("%lu=%lu*%lu\n", n, p, q);
			return;
		}
	}

	/* If no factors were found, n is prime */
	printf("%lu=%lu*1\n", n, n);
}

