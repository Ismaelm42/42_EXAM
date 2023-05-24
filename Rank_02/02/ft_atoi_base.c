// Assignment name  : ft_atoi_base
// Expected files   : ft_atoi_base.c
// Allowed functions: None
// --------------------------------------------------------------------------------

// Write a function that converts the string argument str (base N <= 16)
// to an integer (base 10) and returns it.

// The characters recognized in the input are: 0123456789abcdef
// Those are, of course, to be trimmed according to the requested base. For
// example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

// Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

// Minus signs ('-') are interpreted only if they are the first character of the
// string.

// Your function must be declared as follows:

// int	ft_atoi_base(const char *str, int str_base);

#include <stdio.h>
#include <string.h>
#include <unistd.h>

int	ft_value(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'A' && c <= 'Z')
		return (c - '0' + 10);
	if (c >= 'a' && c <= 'z')
		return (c - '0' + 10);
	return (0);
}

int	ft_valid(char c, int str_base)
{
	char	base_upper[] = "0123456789ABCDEF";
	char	base_lower[] = "0123456789abcdef";

	while (str_base >= 0)
	{
		if (base_upper[str_base] == c || base_lower[str_base] == c)
			return (1);
		str_base--;
	}
	return (0);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	i;
	int	sum;
	int	sign;

	i = 0;
	sum = 0;
	sign = 1;
	while (*str <= 32)
		str++;
	if (*str == '-')
	{
		sign = sign * -1;
		str++;
	}
	if (*str == '-' || *str == '+')
		return (0);
	while (ft_valid(str[i], str_base) != 0)
	{
		sum = sum * str_base + ft_value(str[i]);
		i++;
	}
	return (sign * sum);
}

int	main(void)
{
	char	str[] = "010101";
	int		str_base =  2;

	printf("%d\n", ft_atoi_base(str, str_base));
	return (0);
}
