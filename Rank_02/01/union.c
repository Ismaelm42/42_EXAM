// Assignment name  : union
// Expected files   : union.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes two strings and displays, without doubles, the
// characters that appear in either one of the strings.

// The display will be in the order characters appear in the command line, and
// will be followed by a \n.

// If the number of arguments is not 2, the program displays \n.

// Example:

// $>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
// zpadintoqefwjy$
// $>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
// df6vewg4thras$
// $>./union "rien" "cette phrase ne cache rien" | cat -e
// rienct phas$
// $>./union | cat -e
// $
// $>
// $>./union "rien" | cat -e
// $
// $>

#include <stdio.h>
#include <string.h>
#include <unistd.h>

int	main(int argc, char	**argv)
{
	char	str[10000000];
	int		i;
	int		j;

	if (argc == 3)
	{
		i = 0;
		j = 0;
		while (argv[1][i] != 0)
		{
			str[i] = argv[1][i];
			i++;
		}
		while (argv[2][j] != 0)
		{
			str[i] = argv[2][j];
			i++;
			j++;
		}
		str[i] = 0;
		i = 0;
		while (str[i] != 0)
		{
			j = i - 1;
			while (j >= 0 && str[j] != str[i])
				j--;
			if (j == -1)
				write(1, &str[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

// int main(int argc, char **argv)
// {
// 	if (argc == 3)
// 	{
// 		int	ascii[255] = {0};
// 		int i;
// 		int j;
		
// 		i = 0;
// 		while (i < 3)
// 		{
// 			j = 0;
// 			while (argv[i][j])
// 			{
// 				if (ascii[(int)argv[i][j]] == 0)
// 				{
// 					ascii[(int)argv[i][j]] = 1;
// 					write(1, &argv[i][j], 1);
// 				}
// 				j += 1;
// 			}
// 			i++;
// 		}
// 	}
// 	write(1, "\n", 1);
// 	return (0);
// }
