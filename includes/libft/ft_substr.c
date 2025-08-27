/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angrios <angrios@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 15:20:55 by angrios           #+#    #+#             */
/*   Updated: 2025/05/11 16:24:26 by angrios          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*sub_str;
	unsigned int	s_len;

	if (s == NULL)
		return (NULL);
	s_len = (unsigned int)ft_strlen(s);
	if (start > s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	sub_str = malloc((len + 1) * sizeof(char));
	if (!sub_str)
		return (NULL);
	ft_strlcpy(sub_str, &s[start], len + 1);
	return (sub_str);
}
