#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "main.h"

/**
 * gcd - Computes the greatest common divisor using the Euclidean algorithm.
 * @a: The first number.
 * @b: The second number.
 * Return: The GCD of a and b.
 */
unsigned long gcd(unsigned long a, unsigned long b)
{
    while (b != 0)
    {
        unsigned long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

/**
 * pollard_rho - Pollard's Rho algorithm for integer factorization.
 * @n: The number to be factored.
 * Return: A non-trivial factor of n.
 */
unsigned long pollard_rho(unsigned long n)
{
    unsigned long x, y, d;
    unsigned long one = 1, two = 2;

    if (n % two == 0)
        return two;

    // Initialize x and y
    x = rand() % (n - 1) + 1;  // Random starting point
    y = x;
    unsigned long c = rand() % (n - 1) + 1;  // Random constant

    do
    {
        x = (x * x + c) % n;  // x_{k+1} = (x_k^2 + c) mod n
        y = (y * y + c) % n;
        y = (y * y + c) % n;  // y_{k+1} = (y_k^2 + c) mod n
        d = gcd(n, labs(x - y));  // Compute gcd

        if (d > 1 && d < n)
            return d;  // Found a non-trivial factor

        // Randomly adjust constant `c` occasionally to improve chances
        if (rand() % 100 < 10) {  // 10% chance to change c
            c = rand() % (n - 1) + 1;
        }
    } while (d == 1);

    return d;  // Should not reach here
}

/**
 * factorize - Finds and prints the factorization of a number
 *             in the format n=p*q where p > q.
 * @n: The number to be factorized.
 */
void factorize(unsigned long n)
{
    unsigned long p, q;

    // Use Pollard's Rho algorithm to find a factor
    p = pollard_rho(n);
    if (p != n)  // If a non-trivial factor is found
    {
        q = n / p;
        printf("%lu=%lu*%lu\n", n, p, q);
    }
    else
    {
        // If no factors were found, n is prime
        printf("%lu=%lu*1\n", n, n);
    }
}

/**
 * main - Entry point for the program.
 */
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <number>\n", argv[0]);
        return 1;
    }

    unsigned long n = strtoul(argv[1], NULL, 10);
    factorize(n);
    return 0;
}

