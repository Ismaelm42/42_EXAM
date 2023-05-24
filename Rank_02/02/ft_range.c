// Assignment name  : ft_range
// Expected files   : ft_range.c
// Allowed functions: malloc
// --------------------------------------------------------------------------------

// Write the following function:

// int     *ft_range(int start, int end);

// It must allocate (with malloc()) an array of integers, fill it with consecutive
// values that begin at start and end at end (Including start and end !), then
// return a pointer to the first value of the array.

// Examples:

// - With (1, 3) you will return an array containing 1, 2 and 3.
// - With (-1, 2) you will return an array containing -1, 0, 1 and 2.
// - With (0, 0) you will return an array containing 0.
// - With (0, -3) you will return an array containing 0, -1, -2 and -3.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int	*ft_range(int start, int end)
{
	int	*range;
	int	diff;
	int	sign;
	int	i;

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
	range = malloc(sizeof(int *) * diff);
	i = 0;
	while (i < diff)
	{
		if (i == 0)
			range[i] = start;
		else
			range[i] = start + (i * sign);
		i++;
	}
	return (range);
}

int	main(void)
{
	int	*print_range;
	int	i;

	i = 0;
	print_range = ft_range(-4, 1);
	while (i <= 5)
	{
		printf("%d", print_range[i]);
		if (i < 5)
			printf(", ");
		i++;
	}
	return (0);
}
