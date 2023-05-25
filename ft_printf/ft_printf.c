/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoro-sa <imoro-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:17:35 by imoro-sa          #+#    #+#             */
/*   Updated: 2023/05/25 13:17:36 by imoro-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

void	ft_hexa(const char *str, int *counter, unsigned int arg)
{
	char			hexa[] = "0123456789abcdef";
	char			c;

	if (arg > 15)
	{
		ft_hexa(str, counter, arg / 16);
		ft_hexa(str, counter, arg % 16);
	}
	else
	{
		c = hexa[arg];
		if (*str == 'X' && (c >= 'a' && c <= 'f'))
			c -= 32;
		write (1, &c, 1);
		*counter += 1;
	}
}

void	ft_write(int *counter, const char *str)
{
	write(1, str, 1);
	*counter += 1;
}

void	ft_pointer(int *counter, unsigned long int arg)
{
	char	hexa[] = "0123456789abcdef";
	char	c;

	if (arg > 15)
	{
		ft_pointer(counter, arg / 16);
		ft_pointer(counter, arg % 16);
	}
	else
	{
		c = hexa[arg];
		write (1, &c, 1);
		*counter += 1;
	}
}

int	ft_length(const char *str, va_list arg)
{
	int	counter;

	counter = 0;
	while (*str != 0)
	{
		if (*str == '%')
		{
			str++;
			if (*str == 'c')
				ft_char(&counter, va_arg(arg, int));
			else if (*str == 'd' || *str == 'i')
				ft_decimal(&counter, va_arg(arg, int));
			else if (*str == 'x' || *str == 'X')
				ft_hexa(str, &counter, va_arg(arg, unsigned int));
			else if (*str == 'p')
			{
				write (1, "0x", 2);
				counter += 2;
				ft_pointer(&counter, va_arg(arg, unsigned long int));
			}
			else if (*str == 's')
				ft_string(&counter, va_arg(arg, char *));
			else if (*str == 'u')
				ft_unsigned(&counter, va_arg(arg, unsigned int));
			else
				ft_write(&counter, str);
			str++;
		}
		else
		{
			ft_write(&counter, str);
			str++;
		}
	}
	return (counter);
}

int	ft_printf(const char *str, ...)
{
	int		length;
	va_list	arg;

	va_start(arg, str);
	length = ft_length(str, arg);
	va_end(arg);
	return (length);
}

// int	main(void)
// {
// 	//char	str[] = "";

// 	//printf("printf length = %d\n", printf(" %d %d %d %d %d %d %d", 2147483647, -2147483648, 2147483647, -2147483648, 4294967295, 0, -42));
// 	//printf("\n\n");
// 	//printf("ft_printf length = %d\n", ft_printf(" %d %d %d %d %d %d %d", 2147483647, -2147483648, 2147483647, -2147483648, 4294967295, 0, -42));
// 	//printf("%c", '0');
// 	ft_printf("%c", '0');
// 	return (0);
// }
