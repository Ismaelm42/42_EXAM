// Assignment name  : is_power_of_2
// Expected files   : is_power_of_2.c
// Allowed functions: None
// --------------------------------------------------------------------------------

// Write a function that determines if a given number is a power of 2.

// This function returns 1 if the given number is a power of 2, otherwise it returns 0.

// Your function must be declared as follows:

// int	    is_power_of_2(unsigned int n);

#include <stdio.h>
#include <string.h>
#include <unistd.h>

int	is_power_of_2(unsigned int n)
{
	unsigned int	i;

	i = 2;
	while (i <= n)
	{
		if (n == i)
			return (1);
		else
			i = i * 2;
	}
	return (0);
}

