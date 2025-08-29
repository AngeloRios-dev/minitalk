/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angrios <angrios@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 18:22:48 by angrios           #+#    #+#             */
/*   Updated: 2025/05/01 18:40:05 by angrios          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	chr;

	i = 0;
	chr = (char)c;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == chr)
			return ((char *)&s[i]);
		i--;
	}
	if (chr == '\0')
		return ((char *)&s[i]);
	return (0);
}
