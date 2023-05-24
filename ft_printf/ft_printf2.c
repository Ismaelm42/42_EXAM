
#include "ft_printf.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

void	ft_char(int *counter, int arg)
{
	write(1, &arg, 1);
	*counter += 1;
}

void	ft_string(int *counter, char *arg)
{
	write(1, arg, ft_strlen(arg));
	*counter += ft_strlen(arg);
}

void	ft_decimal(int *counter, int arg)
{
	char	c;

	if (arg < 0)
	{
		arg = -arg;
		write(1, "-", 1);
		*counter += 1;
	}
	if (arg > 9)
	{
		ft_decimal(counter, arg / 10);
		ft_decimal(counter, arg % 10);
	}
	else
	{
		c = arg + 48;
		write (1, &c, 1);
		*counter += 1;
	}
}

void	ft_unsigned(int *counter, unsigned int arg)
{
	char	c;

	if (arg > 9)
	{
		ft_decimal(counter, arg / 10);
		ft_decimal(counter, arg % 10);
	}
	else
	{
		c = arg + 48;
		write (1, &c, 1);
		*counter += 1;
	}
}
