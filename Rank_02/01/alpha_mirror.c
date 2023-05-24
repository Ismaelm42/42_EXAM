// Assignment name  : alpha_mirror
// Expected files   : alpha_mirror.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program called alpha_mirror that takes a string and displays this string
// after replacing each alphabetical character by the opposite alphabetical
// character, followed by a newline.

// 'a' becomes 'z', 'Z' becomes 'A'
// 'd' becomes 'w', 'M' becomes 'N'

// and so on.

// Case is not changed.

// If the number of arguments is not 1, display only a newline.

// Examples:

// $>./alpha_mirror "abc"
// zyx
// $>./alpha_mirror "My horse is Amazing." | cat -e
// Nb slihv rh Znzarmt.$
// $>./alpha_mirror | cat -e
// $
// $>

#include <stdio.h>
#include <string.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int		i;
	char	a;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i] != '\0')
		{
			a = argv[1][i];
			if (a >= 'a' && a <= 'z')
				a = 219 - a;
			else if (a >= 'A' && a <= 'Z')
				a = 155 - a;
			write (1, &a, 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
