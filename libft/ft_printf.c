#include "libft.h"

int	ft_formats(va_list args, const char format)
{
	int	printables;

	printables = 0;
	if (format == 'c')
		printables += print_single_char(va_arg(args, int));
	else if (format == 's')
		printables += print_multiple_chars(va_arg(args, char *));
	else if (format == 'p')
		printables += print_pointer(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		printables += print_numbers(va_arg(args, int));
	else if (format == 'u')
		printables += print_unsigned_numbers(va_arg(args, unsigned int));
	else if (format == 'x')
		printables += print_hexa_min(va_arg(args, unsigned int));
	else if (format == 'X')
		printables += print_hexa_maj(va_arg(args, unsigned int));
	else if (format == '%')
		printables += print_single_char('%');
	return (printables);
}

int	ft_printf(const char *str, ...)
{
	int			i;
	int			printables;
	va_list		args;

	i = 0;
	printables = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			printables += ft_formats(args, str[i + 1]);
			i++;
		}
		else
			printables += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (printables);
}