/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angrios <angrios@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 14:10:49 by angrios           #+#    #+#             */
/*   Updated: 2025/05/11 14:33:10 by angrios          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	int		len;

	len = ft_strlen(s) + 1;
	str = malloc(len);
	if (!str)
		return (NULL);
	ft_memcpy(str, s, len);
	return (str);
}
