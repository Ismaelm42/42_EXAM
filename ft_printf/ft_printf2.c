/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoro-sa <imoro-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:17:27 by imoro-sa          #+#    #+#             */
/*   Updated: 2023/05/25 13:17:28 by imoro-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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
	if (arg == NULL)
	{
		write(1, "(null)", 6);
		*counter += 6;
	}
	else
	{
		write(1, arg, ft_strlen(arg));
		*counter += ft_strlen(arg);
	}
}

void	ft_decimal(int *counter, int arg)
{
	char	c;
	long	nbr;

	nbr = arg;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
		*counter += 1;
	}
	if (nbr > 9)
	{
		ft_decimal(counter, nbr / 10);
		ft_decimal(counter, nbr % 10);
	}
	else
	{
		c = nbr + '0';
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
