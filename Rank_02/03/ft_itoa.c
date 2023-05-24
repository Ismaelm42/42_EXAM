// Assignment name  : ft_itoa
// Expected files   : ft_itoa.c
// Allowed functions: malloc
// --------------------------------------------------------------------------------

// Write a function that takes an int and converts it to a null-terminated string.
// The function returns the result in a char array that you must allocate.

// Your function must be declared as follows:

// char	*ft_itoa(int nbr);

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

static size_t	ft_int_len(int n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = (n * -1);
		i++;
	}
	while ((size_t)n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*str;
	long		x;
	size_t		len;

	x = (long)n;
	len = ft_int_len(n);
	str = malloc(sizeof (char) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	len = len - 1;
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		x = x * -1;
	}
	while (x > 0)
	{
		str[len] = (x % 10) + '0';
		x = x / 10;
		len--;
	}
	return ((char *)str);
}

int	main(void)
{
	int	nbr;

	nbr = 0;
	printf("%s\n", ft_itoa(nbr));
	return (0);
}
