/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angrios <angrios@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:36:29 by angrios           #+#    #+#             */
/*   Updated: 2025/05/11 17:12:04 by angrios          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		str_len;
	char	*new_str;

	if (!s1 || !s2)
		return (NULL);
	str_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	new_str = malloc(str_len * sizeof(char));
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, s1, str_len);
	ft_strlcat(new_str, s2, str_len);
	return (new_str);
}
