// Assignment name  : print_bits
// Expected files   : print_bits.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a function that takes a byte, and prints it in binary WITHOUT A NEWLINE
// AT THE END.

// Your function must be declared as follows:

// void print_bits(unsigned char octet);

// Example, if you pass 2 to print_bits, it will print "00000010"

#include <stdio.h>
#include <string.h>
#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int	div;

	div = 128;
	while (div > 0)
	{
		if (div <= octet)
		{
			write(1, "1", 1);
			octet = (octet % div);
		}
		else
			write(1, "0", 1);
		div = div / 2;
	}
}

int	main(void)
{
	unsigned char	c = 54;

	print_bits(c);
	return (0);
}
