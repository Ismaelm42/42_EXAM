// Assignment name  : add_prime_sum
// Expected files   : add_prime_sum.c
// Allowed functions: write, exit
// --------------------------------------------------------------------------------

// Write a program that takes a positive integer as argument and displays the sum
// of all prime numbers inferior or equal to it followed by a newline.

// If the number of arguments is not 1, or the argument is not a positive number,
// just display 0 followed by a newline.

// Yes, the examples are right.

// Examples:

// $>./add_prime_sum 5
// 10
// $>./add_prime_sum 7 | cat -e
// 17$
// $>./add_prime_sum | cat -e
// 0$
// $>

#include <stdio.h>
#include <string.h>
#include <unistd.h>

int	ft_atoi(const char	*str)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	if (str[i] == '-')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		k = k * 10 + str[i] - '0';
		i++;
	}
	return (k);
}

void	ft_putnbr(int sum)
{
	char	c;

	if (sum > 9)
	{
		ft_putnbr(sum / 10);
		ft_putnbr(sum % 10);
	}
	if (sum <= 9)
	{
		c = (sum % 10) + '0';
		write(1, &c, 1);
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	counter;
	int	nbr;
	int	sum;

	counter = 3;
	sum = 2;
	if (argc == 2)
	{
		nbr = ft_atoi(argv[1]);
		if (nbr <= 1)
			write(1, "0", 1);
		else
		{
			while (counter <= nbr)
			{
				i = 2;
				while (counter % i != 0 && i < counter)
					i++;
				if (counter == i)
					sum = sum + counter;
				counter++;
			}
			ft_putnbr(sum);
		}
	}
	write(1, "\n", 1);
	return (0);
}
