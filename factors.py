#!/usr/bin/python3
import sys


def factorize(n):
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return i, n // i
    return n, 1


def main(file_path):
    with open(file_path, 'r') as file:
        numbers = file.readlines()

    for number in numbers:
        n = int(number.strip())
        p, q = factorize(n)
        print(f"{n}={p}*{q}")


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: factors <file>")
        sys.exit(1)

    file_path = sys.argv[1]
    main(file_path)
