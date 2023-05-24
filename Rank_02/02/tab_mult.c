// Assignment name  : tab_mult
// Expected files   : tab_mult.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that displays a number's multiplication table.

// The parameter will always be a strictly positive number that fits in an int,
// and said number times 9 will also fit in an int.

// If there are no parameters, the program displays \n.

// Examples:

// $>./tab_mult 9
// 1 x 9 = 9
// 2 x 9 = 18
// 3 x 9 = 27
// 4 x 9 = 36
// 5 x 9 = 45
// 6 x 9 = 54
// 7 x 9 = 63
// 8 x 9 = 72
// 9 x 9 = 81
// $>./tab_mult 19
// 1 x 19 = 19
// 2 x 19 = 38
// 3 x 19 = 57
// 4 x 19 = 76
// 5 x 19 = 95
// 6 x 19 = 114
// 7 x 19 = 133
// 8 x 19 = 152
// 9 x 19 = 171
// $>
// $>./tab_mult | cat -e
// $
// $>

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
		sum = sum * 10 +  str[i] - '0';
		i++;
	}
	return (sum);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

void	ft_print_result(int nbr)
{
	char	c;

	if (nbr >= 10)
	{
		ft_print_result(nbr / 10);
		ft_print_result(nbr % 10);
	}
	if (nbr < 10)
	{
		c = nbr + '0';
		write (1, &c, 1);
	}

}

int	main(int argc, char ** argv)
{
	int		nbr;
	int		result;
	int		i;
	char	c;

	i = 1;
	if (argc == 2)
	{
		nbr = ft_atoi(argv[1]);
		while (i < 10)
		{
			c = i + '0';
			write(1, &c, 1);
			write(1, " x ", 3);
			write (1, argv[1], ft_strlen(argv[1]));
			write(1, " = ", 3);
			result = nbr * i;
			ft_print_result(result);
			write(1, "\n", 1);
			i++;
		}

	}
	else
		write (1, "\n", 1);	
	return (0);
}
