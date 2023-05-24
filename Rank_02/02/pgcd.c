// Assignment name  : pgcd
// Expected files   : pgcd.c
// Allowed functions: printf, atoi, malloc, free
// --------------------------------------------------------------------------------

// Write a program that takes two strings representing two strictly positive
// integers that fit in an int.

// Display their highest common denominator followed by a newline (It's always a
// strictly positive integer).

// If the number of parameters is not 2, display a newline.

// Examples:

// $> ./pgcd 42 10 | cat -e
// 2$
// $> ./pgcd 42 12 | cat -e
// 6$
// $> ./pgcd 14 77 | cat -e
// 7$
// $> ./pgcd 17 3 | cat -e 
// 1$
// $> ./pgcd | cat -e
// $

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int		i;
	int		nbr1;
	int		nbr2;

	if (argc == 3)
	{
		nbr1 = atoi(argv[1]);
		nbr2 = atoi(argv[2]);
		i = nbr1 - 1;
		if (nbr1 == 0 || nbr2 == 0)
			printf("0");
		else
		{
			while (i > 0)
			{
				if (nbr1 % i == 0 && nbr2 % i == 0)
				{
					printf("%d", i);
					i = 0;
				}
				else
					i--;
			}
		}
	}
	printf("\n");
}
