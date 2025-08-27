/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angrios <angrios@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:52:06 by angrios           #+#    #+#             */
/*   Updated: 2025/05/15 15:18:14 by angrios          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The  bzero()  function erases the data in the n bytes of the memory 
starting at the location pointed to by s, by writing zeros 
(bytes containing '\0') to that area.
*/
void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr_s;

	i = 0;
	ptr_s = (unsigned char *)s;
	while (i < n)
	{
		ptr_s[i] = 0;
		i++;
	}
}
