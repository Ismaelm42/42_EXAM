// Assignment name  : ft_strdup
// Expected files   : ft_strdup.c
// Allowed functions: malloc
// --------------------------------------------------------------------------------

// Reproduce the behavior of the function strdup (man strdup).

// Your function must be declared as follows:

// char    *ft_strdup(char *src);

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(char *src)
{
	int	i;

	i = 0;
	while (src[i] != 0)
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*str;
	int		i;

	str = malloc(sizeof(char *) * ft_strlen(src) + 1);
	i = 0;
	while (src[i] != 0)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

// int	main(void)
// {
// 	char	str[] = "hola buenos dias que tal";

// 	printf("%s", ft_strdup(str));
// 	return (0);
// }
