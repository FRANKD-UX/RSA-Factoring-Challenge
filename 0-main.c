#include "main.h"

/**
 * main - Entry point for testing the factorization function.
 *
 * Return: Always 0.
 */
int main(void)
{
	factorize(4);
	factorize(12);
	factorize(34);
	factorize(128);
	factorize(1024);
	factorize(4958);
	factorize(1718944270642558716715UL);
	factorize(9);
	factorize(99);
	factorize(999);
	factorize(9999);
	factorize(9797973);
	factorize(49);
	factorize(239809320265259UL);

	return (0);
}

