// Assignment name  : reverse_bits
// Expected files   : reverse_bits.c
// Allowed functions:
// --------------------------------------------------------------------------------

// Write a function that takes a byte, reverses it, bit by bit (like the
// example) and returns the result.

// Your function must be declared as follows:

// unsigned char	reverse_bits(unsigned char octet);

// Example:

//   1 byte
// _____________
//  0010  0110
// 	 ||
// 	 \/
//  0110  0100

#include <stdio.h>
#include <string.h>
#include <unistd.h>

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	octet_return;
	int				i;

	octet_return = 0;
	i = 0;
	while (i < 8)
	{
		octet_return = octet_return * 2 + (octet % 2);
		octet = octet / 2;
		i++;
	}
	return (octet_return);
}

int	main(void)
{
	unsigned char	c = 6;
	printf("%u", reverse_bits(c));	
	return (0);
}
