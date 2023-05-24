// Assignment name  : camel_to_snake
// Expected files   : camel_to_snake.c
// Allowed functions: malloc, free, realloc, write
// --------------------------------------------------------------------------------

// Write a program that takes a single string in lowerCamelCase format
// and converts it into a string in snake_case format.

// A lowerCamelCase string is a string where each word begins with a capital letter
// except for the first one.

// A snake_case string is a string where each word is in lower case, separated by
// an underscore "_".

// Examples:
// $>./camel_to_snake "hereIsACamelCaseWord"
// here_is_a_camel_case_word
// $>./camel_to_snake "helloWorld" | cat -e
// hello_world$
// $>./camel_to_snake | cat -e
// $

#include <stdio.h>
#include <string.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	char	a;

	i = 1;
	while (i <= argc - 1)
	{
		j = 0;
		while (argv[i][j] != 0)
		{
			a = argv[i][j];
			if (a >= 'A' && a <= 'Z')
			{
				a = a + 32;
				write(1, "_", 1);
			}
			write(1, &a, 1);
			j++;
		}
		write(1, " ", 1);
		i++;
	}
	write (1, "\n", 1);
	return (0);
}
