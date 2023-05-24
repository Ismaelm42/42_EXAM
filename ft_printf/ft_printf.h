
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_strlen(char *str);
void	ft_char(int *counter, int arg);
void	ft_string(int *counter, char *arg);
void	ft_decimal(int *counter, int arg);
void	ft_unsigned(int *counter, unsigned int arg);
void	ft_hexa(const char *str, int *counter, unsigned int arg);
void	ft_write(int *counter, const char *str);
void	ft_pointer(int *counter, unsigned long int arg);
int		ft_length(const char *str, va_list arg);
int		ft_printf(const char *str, ...);

#endif
