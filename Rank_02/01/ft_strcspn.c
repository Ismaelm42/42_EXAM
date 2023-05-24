// Assignment name	: ft_strcspn
// Expected files	: ft_strcspn.c
// Allowed functions: None
// ---------------------------------------------------------------

// Reproduce exactly the behavior of the function strcspn
// (man strcspn).

// The function should be prototyped as follows:

// size_t	ft_strcspn(const char *s, const char *reject);

#include <stdio.h>
#include <string.h>
#include <unistd.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s[i] != 0)
	{
		j = 0;
		while (s[i] != reject[j] && reject[j] != 0)
			j++;
		if (s[i] == reject[j])
			return (i);
		else
			i++;
	}
	return (i);
}

int	main(void)
{
	char	str1[] = "holgiugtfrydfiuhjihuywgfuyaaaaaa";
	char	str2[] = "-";

	printf("Function:%ld\n", ft_strcspn(str1, str2));
	printf("Original:%ld\n", strcspn(str1, str2));
	return (0);
}
