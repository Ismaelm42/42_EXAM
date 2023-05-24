// Assignment name  : ft_swap
// Expected files   : ft_swap.c
// Allowed functions: 
// --------------------------------------------------------------------------------

// Write a function that swaps the contents of two integers the adresses of which
// are passed as parameters.

// Your function must be declared as follows:

// void	ft_swap(int *a, int *b);

#include <stdio.h>
#include <string.h>
#include <unistd.h>

void	ft_swap(int *a, int *b)
{
	int	*c;
	int	value_c;

	value_c = 0;
	c = &value_c;
	*c = *a;
	*a = *b;
	*b = *c;
}

int	main(void)
{
	int	*a;
	int	*b;
	int	value_a;
	int	value_b;

	value_a = 3;
	value_b = 9;
	a = &value_a;
	b = &value_b;
	ft_swap(a, b);
	printf("%d\n%d", *a, *b);
	return (0);
}
