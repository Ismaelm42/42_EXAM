// Assignment name  : ft_rrange
// Expected files   : ft_rrange.c
// Allowed functions: malloc
// --------------------------------------------------------------------------------

// Write the following function:

// int     *ft_rrange(int start, int end);

// It must allocate (with malloc()) an array of integers, fill it with consecutive
// values that begin at end and end at start (Including start and end !), then
// return a pointer to the first value of the array.

// Examples:

// - With (1, 3) you will return an array containing 3, 2 and 1
// - With (-1, 2) you will return an array containing 2, 1, 0 and -1.
// - With (0, 0) you will return an array containing 0.
// - With (0, -3) you will return an array containing -3, -2, -1 and 0.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int	*ft_rrange(int start, int end)
{
	int	*rrange;
	int	i;
	int	diff;
	int	sign;

	i = 0;
	sign = 1;
	if (start > end)
	{
		diff = start - end;
		sign = -1;
	}
	diff = end - start;
	if (diff < 0)
		diff = -diff;
	diff++;
	rrange = malloc (sizeof(int *) * diff);
	while (i < diff)
	{
		if (i == 0)
			rrange[i] = end;
		else
			rrange[i] = (end - i) * sign;
		i++;
	}
	return (rrange);
}

int	main(void)
{
	int	*print_rrange;
	int	i;

	i = 0;
	print_rrange = ft_rrange(0, 0);
	while (i <= 6)
	{
		printf("%d ", print_rrange[i]);
		i++;
	}
	return (0);
}
