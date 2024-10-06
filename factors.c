#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "main.h"

/**
 * gcd - Computes the greatest common divisor using Euclid's algorithm
 * @a: First number
 * @b: Second number
 * Return: The GCD of a and b
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
 * pollard_rho - Pollard's Rho algorithm for factorization
 * @n: The number to be factorized
 * Return: A non-trivial factor of n
 */
unsigned long pollard_rho(unsigned long n)
{
    unsigned long x, y, d, one = 1, two = 2;

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
    } while (d == 1);

    return d;  // Should not reach here
}

/**
 * factorize - Finds and prints the factorization of a number
 * @n: The number to be factorized
 */
void factorize(unsigned long n)
{
    unsigned long p, q;

    // Try Pollard's rho algorithm
    p = pollard_rho(n);
    if (p == n)  // If no factor found, n is prime
    {
        printf("%lu=%lu*1\n", n, n);
        return;
    }
    q = n / p;

    // Print the factorization
    printf("%lu=%lu*%lu\n", n, (p > q) ? p : q, (p > q) ? q : p);
}

/**
 * main - Entry point of the program
 * @argc: Number of command line arguments
 * @argv: Array of arguments
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
    unsigned long n;
    FILE *file;
    char buffer[1024];

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return (1);
    }

    // Open the file
    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return (1);
    }

    // Read numbers from the file
    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        n = strtoul(buffer, NULL, 10);
        factorize(n);
    }

    fclose(file);
    return (0);
}

