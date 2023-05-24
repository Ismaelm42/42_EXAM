// Assignment name  : rev_wstr
// Expected files   : rev_wstr.c
// Allowed functions: write, malloc, free
// --------------------------------------------------------------------------------

// Write a program that takes a string as a parameter, and prints its words in 
// reverse order.

// A "word" is a part of the string bounded by spaces and/or tabs, or the 
// begin/end of the string.

// If the number of parameters is different from 1, the program will display 
// '\n'.

// In the parameters that are going to be tested, there won't be any "additional" 
// spaces (meaning that there won't be additionnal spaces at the beginning or at 
// the end of the string, and words will always be separated by exactly one space).

// Examples:

// $> ./rev_wstr "You hate people! But I love gatherings. Isn't it ironic?" | cat -e
// ironic? it Isn't gatherings. love I But people! hate You$
// $>./rev_wstr "abcdefghijklm"
// abcdefghijklm
// $> ./rev_wstr "Wingardium Leviosa" | cat -e
// Leviosa Wingardium$
// $> ./rev_wstr | cat -e
// $
// $>

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

int	position_index(char *str, int i)
{
	while (str[i] != 32 && str[i] != '\t' && i >= 0)
		i--;
	i++;
	return (i);
}

void	print_words(char *str, int i)
{
	int	index;

	index = i;
	while (str[i] != 0 && str[i] != 32 && str[i] != '\t')
	{
		write (1, &str[i], 1);
		i++;
	}
	if (index != 0)
		write (1, " ", 1);
}

int	main(int argc, char **argv)
{
	char	*str;
	int		i;

	if (argc == 2)
	{
		str = argv[1];
		i = ft_strlen(str);
		while (i >= 0)
		{
			i = position_index(str, i);
			print_words(str, i);
			i = i - 2;
		}
	}
	write(1, "\n", 1);
	return (0);
}
