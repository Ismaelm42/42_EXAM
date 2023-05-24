// Assignment name  : ft_list_size
// Expected files   : ft_list_size.c
// Allowed functions: 
// --------------------------------------------------------------------------------

// Write a function that returns the number of elements in the linked list that's
// passed to it.

// It must be declared as follows:

// int	ft_list_size(t_list *begin_list);

// You must use the following structure in your program ft_list_size.c :

// typedef struct    s_list
// {
//     struct s_list *next;
//     void          *data;
// }                 t_list;

#include <stdio.h>
#include <string.h>
#include <unistd.h>

typedef struct s_list
{
	struct s_list	*next;
	void			*data;
}					t_list;

int	ft_list_size(t_list *begin_list)
{
	t_list	*node;
	int		counter;

	if (begin_list == NULL)
		return (0);
	node = begin_list;
	counter = 1;
	while (node->next)
	{
		node = node->next;
		counter++;
	}
	return (counter);
}
