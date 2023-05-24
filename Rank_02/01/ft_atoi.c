// Assignment name  : ft_atoi
// Expected files   : ft_atoi.c
// Allowed functions: None
// --------------------------------------------------------------------------------

// Write a function that converts the string argument str to an integer (type int)
// and returns it.

// It works much like the standard atoi(const char *str) function, see the man.

// Your function must be declared as follows:

// int	ft_atoi(const char *str);

#include <stdio.h>
#include <string.h>
#include <unistd.h>

int	ft_atoi(const char *str)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 1;

	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		k = -k;
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		j = j * 10 + str[i] - '0';
		i++;
	}
	return (k * j);
}

// int	main(void)
// {
// 	char	*str;

// 	str = "  		  ----+++234587";
// 	printf("%d", ft_atoi(str));
// 	return(0);
// }
// // atoi no se asegura de no llegar al '\0'
