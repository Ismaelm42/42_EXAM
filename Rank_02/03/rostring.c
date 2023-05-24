// Assignment name  : rostring
// Expected files   : rostring.c
// Allowed functions: write, malloc, free
// --------------------------------------------------------------------------------

// Write a program that takes a string and displays this string after rotating it
// one word to the left.
// Thus, the first word becomes the last, and others stay in the same order.
// A "word" is defined as a part of a string delimited either by spaces/tabs, or
// by the start/end of the string.
// Words will be separated by only one space in the output.
// If there's less than one argument, the program displays \n.
// Example:

// $>./rostring "abc   " | cat -e
// abc$
// $>
// $>./rostring "Que la      lumiere soit et la lumiere fut"
// la lumiere soit et la lumiere fut Que
// $>
// $>./rostring "     AkjhZ zLKIJz , 23y"
// zLKIJz , 23y AkjhZ
// $>
// $>./rostring "first" "2" "11000000"
// first
// $>
// $>./rostring | cat -e
// $
// $>

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

char	*ft_malloc(char *str)
{
	int		i;
	int		j;
	int		len;
	char	*word;

	i = 0;
	len = 0;
	while (str[i] == 32 || str[i] == '\t')
		i++;
	j = i;
	while (str[i] != 32 && str[i] != '\t' && str[i] != 0)
	{
		len++;
		i++;
	}
	word = malloc(sizeof(char) * len + 1);
	i = 0;
	while (str[j] != 32 && str[j] != '\t' && str[j] != 0)
	{
		word[i] = str[j];
		j++;
		i++;
	}
	word[i] = 0;
	return (word);
}

char	*ft_advance(char *str)
{
	while (*str == 32 || *str == '\t')
		str++;
	while (*str != 32 && *str != '\t' && *str != 0)
		str++;
	while (*str == 32 || *str == '\t')
		str++;
	return (str);
}

void	print_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		while (str[i] != 32 && str[i] != '\t' && str[i] != 0)
		{
			write(1, &str[i], 1);
			i++;
		}
		while ((str[i] == 32 || str[i] == '\t') && str[i] != 0)
			i++;
		write(1, " ", 1);
	}
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		write (1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	char	*str;
	char	*word;

	if (argc >= 2)
	{
		word = ft_malloc(argv[1]);
		str = ft_advance(argv[1]);
		print_str(str);
		ft_putstr(word);
		free(word);
	}
	write(1, "\n", 1);
	return (0);
}
