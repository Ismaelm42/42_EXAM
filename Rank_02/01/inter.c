// Assignment name  : inter
// Expected files   : inter.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes two strings and displays, without doubles, the
// characters that appear in both strings, in the order they appear in the first
// one.

// The display will be followed by a \n.

// If the number of arguments is not 2, the program displays \n.

// Examples:

// $>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
// padinto$
// $>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
// df6ewg4$
// $>./inter "rien" "cette phrase ne cache rien" | cat -e
// rien$
// $>./inter | cat -e
// $

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	char	a;

	i = 0;
	if (argc == 3)
	{
		while (argv[1][i] != 0)
		{
			j = 0;
			while (argv[1][i] != argv[2][j] && argv[2][j] != 0)
				j++;
			if (argv[2][j] != 0)
			{
				a = argv[2][j];
				j = i - 1;
				while (a != argv[1][j] && j >= 0)
					j--;
				if (j == -1)
					write(1, &a, 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

// int	main(int ac, char **av)
// {
// 	int	i;
// 	int k;
// 	int l;
// 	char *s1;
// 	char *s2;

// 	i = 0;
// 	l = 0;
// 	if (ac == 3)
// 	{
// 		s1 = av[1];
// 		s2 = av[2];
// 		while (s1[i] != '\0')
// 		{
// 			k = 0;
// 			while (s2[k] != '\0')
// 			{
// 				if(s1[i] == s2[k])
// 				{ 
// 					l = 0;
// 					while (s1[l] != s1[i])
// 						l++;
// 					if (l == i)
// 					{
// 						l = 0;
// 						while (s2[l] != s2[k])
// 							l++;
// 						if (l == k)
// 							write(1, &s1[i], 1);
// 					}
// 				}
// 				k++;
// 			}
// 			i++;
// 		}
// 	}
// 	write(1, "\n", 1);
// }
