#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	nbr_words (char *str)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (str[i] != '\0')
	{
		if ((str[i] != ' ' && str[i] != '\t') && (str[i + 1] == ' ' || str[i + 1] == '\t' || str[i + 1] == '\0'))
		{
			i++;
			counter++;
		}
		else
			i++;
	}
	return (counter);
}

int	ft_is_space(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0' && str[i] == '\t' && str[i] == ' ')
		return (1);
	else
		return (0);
}

char *ft_substr(char *str)
{
	char	*str_return;
	int		len;
	int		i;
	
	len = 0;
	i = 0;
	while (str[len] != '\0' && str[len] != '\t' && str[len] != ' ')
		len++;
	str_return = malloc(sizeof(char *) * len + 1);
	if (str_return == NULL)
		return (NULL);
	while (str[i] != '\0' && str[i] != '\t' && str[i] != ' ')
	{
		str_return[i] = str[i];
		i++;
	}
	str_return[i] = '\0';
	return (str_return);
}

char	**ft_split(char *str)
{
	char	**str_return;
	int		nbr_words_malloc;
	int		i;

	i = 0;
	nbr_words_malloc = nbr_words(str);
	str_return = malloc (sizeof (char **) * nbr_words_malloc + 1);
	if (str == NULL)
		return (NULL);
	while (i < nbr_words_malloc)
	{
		while (ft_is_space(str) == 1)
			str++;
		str_return[i] = ft_substr(str);
		while (ft_is_space(str) == 0)
			str++;
		i++;
	}
	str[i] = '\0';
	return (str_return);
}

int	main(void)
{	
	char str_prueba[] = "hola, buenos dias, que tal estas?";
	char **str_return;

	str_return = ft_split(str_prueba);
	printf("%s\n", str_return[0]);
	return (0);
}
