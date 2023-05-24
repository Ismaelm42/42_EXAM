// Assignment name  : print_hex
// Expected files   : print_hex.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes a positive (or zero) number expressed in base 10,
// and displays it in base 16 (lowercase letters) followed by a newline.

// If the number of parameters is not 1, the program displays a newline.

// Examples:

// $> ./print_hex "10" | cat -e
// a$
// $> ./print_hex "255" | cat -e
// ff$
// $> ./print_hex "5156454" | cat -e
// 4eae66$
// $> ./print_hex | cat -e
// $

#include <stdio.h>
#include <string.h>
#include <unistd.h>

int	ft_atoi(char *str)
{
	int	i;
	int	sum;

	i = 0;
	sum = 0;
	while (str[i] != 0)
	{
		sum = sum * 10 + str[i] - '0';
		i++;
	}
	return (sum);
}

void	ft_hexa(int nbr)
{
	char	hexa[16] = "0123456789abcdef";

	if (nbr >= 16)
	{
		ft_hexa(nbr / 16);
		ft_hexa(nbr % 16);
	}
	if (nbr < 16)
		write(1, &hexa[nbr], 1);
}

int	main(int argc, char **argv)
{
	int	nbr;

	if (argc == 2)
	{
		nbr = ft_atoi(argv[1]);
		ft_hexa(nbr);
	}
	write (1, "\n", 1);
	return (0);
}
