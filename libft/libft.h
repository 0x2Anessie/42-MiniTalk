#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
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

int		ft_atoi(const char *nptr);

void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);

size_t	ft_strlen(const char *s);

#endif
