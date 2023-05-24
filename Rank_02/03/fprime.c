// Assignment name  : fprime
// Expected files   : fprime.c
// Allowed functions: printf, atoi
// --------------------------------------------------------------------------------

// Write a program that takes a positive int and displays its prime factors on the
// standard output, followed by a newline.

// Factors must be displayed in ascending order and separated by '*', so that
// the expression in the output gives the right result.

// If the number of parameters is not 1, simply display a newline.

// The input, when there is one, will be valid.

// Examples:

// $> ./fprime 225225 | cat -e
// 3*3*5*5*7*11*13$
// $> ./fprime 8333325 | cat -e
// 3*3*5*5*7*11*13*37$
// $> ./fprime 9539 | cat -e
// 9539$
// $> ./fprime 804577 | cat -e
// 804577$
// $> ./fprime 42 | cat -e
// 2*3*7$
// $> ./fprime 1 | cat -e
// 1$
// $> ./fprime | cat -e
// $
// $> ./fprime 42 21 | cat -e
// $

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

void	ft_putnbr(int nbr)
{
	char	c;

	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	if (nbr <= 9)
	{
		c = nbr + '0';
		write (1, &c, 1);
	}
}

int	main(int argc, char **argv)
{
	int	nbr;
	int	div;

	if (argc == 2)
	{
		nbr = atoi(argv[1]);
		div = 2;
		while (div <= nbr)
		{
			if (nbr % div == 0)
			{
				ft_putnbr(div);
				if (nbr / div != 1)
					write(1, "*", 1);
				nbr = nbr / div;
			}
			else
				div = div + 1;
		}
	}
	write(1, "\n", 1);
	return (0);
}
