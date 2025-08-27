/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angrios <angrios@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:43:55 by angrios           #+#    #+#             */
/*   Updated: 2025/08/27 12:06:07 by angrios          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_format_handler(char specifier, va_list args);

int	ft_printf(const char *format, ...)
{
	int		i;
	int		printed_chars;
	va_list	args;

	i = 0;
	printed_chars = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			printed_chars += ft_format_handler(format[i], args);
		}
		else
		{
			write(1, &format[i], 1);
			printed_chars++;
		}
		i++;
	}
	va_end(args);
	return (printed_chars);
}

static int	ft_format_handler(char specifier, va_list args)
{
	if (specifier == 'c')
	{
		ft_putchar_fd((char)va_arg(args, int), 1);
		return (1);
	}
	else if (specifier == 's')
		return (ft_str_handler(va_arg(args, char *)));
	else if (specifier == 'p')
		return (ft_ptr_handler(va_arg(args, void *)));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_int_handler(va_arg(args, int)));
	else if (specifier == 'u')
		return (ft_unsigned_handler(va_arg(args, unsigned int)));
	else if (specifier == 'x' || specifier == 'X')
		return (ft_hex_handler(va_arg(args, unsigned int), specifier));
	else if (specifier == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	return (0);
}
