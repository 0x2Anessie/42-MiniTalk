#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

int	ft_formats(va_list args, const char format);
int	ft_printf(const char *str, ...);

int	print_single_char(int c);
int	print_multiple_chars(char *str);
int	print_pointer(unsigned long long pointer);
int	print_numbers(int nb);

int	print_unsigned_numbers(unsigned int nb);
int	print_hexa_min(unsigned long long nb);
int	print_hexa_maj(unsigned int nb);
int	print_percent(void);

#	endif