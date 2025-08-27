/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handlers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angrios <angrios@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 21:25:23 by angrios           #+#    #+#             */
/*   Updated: 2025/08/27 12:05:52 by angrios          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_int_handler(int num)
{
	long	nb;
	int		count;

	nb = num;
	count = 0;
	if (nb < 0)
	{
		ft_putchar_fd('-', 1);
		count++;
		count += ft_unsigned_handler((unsigned int)(-num));
	}
	else
		count += ft_unsigned_handler((unsigned int)num);
	return (count);
}

int	ft_unsigned_handler(unsigned int num)
{
	int	count;

	count = 0;
	if (num >= 10)
		count += ft_unsigned_handler(num / 10);
	ft_putchar_fd((num % 10) + '0', 1);
	count++;
	return (count);
}

int	ft_hex_handler(unsigned int num, char specifier)
{
	int	is_uppercase;

	is_uppercase = (specifier == 'X');
	return (ft_print_hex(num, is_uppercase));
}

int	ft_str_handler(char *str)
{
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	ft_ptr_handler(void *ptr)
{
	int	count;

	if (ptr == NULL)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	count = 0;
	ft_putstr_fd("0x", 1);
	count += 2;
	count += ft_print_hex((unsigned long)ptr, 0);
	return (count);
}
