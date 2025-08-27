/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angrios <angrios@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:56:02 by angrios           #+#    #+#             */
/*   Updated: 2025/05/14 19:05:03 by angrios          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_counter(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static int	ft_fill_split(char **splitted, const char *s, char c)
{
	int	i;
	int	start;
	int	end;

	i = 0;
	start = 0;
	end = 0;
	while (s[end])
	{
		while (s[end] && s[end] == c)
			end++;
		start = end;
		while (s[end] && s[end] != c)
			end++;
		if (end > start)
		{
			splitted[i] = malloc((end - start + 1) * sizeof(char));
			if (!splitted[i])
				return (0);
			ft_strlcpy(splitted[i], &s[start], (end - start) + 1);
			i++;
		}
	}
	splitted[i] = NULL;
	return (1);
}

char	**ft_split(const char *s, char c)
{
	char	**splitted;
	int		word_count;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	word_count = ft_word_counter(s, c);
	splitted = malloc((word_count + 1) * sizeof(char *));
	if (!splitted)
		return (NULL);
	if (!ft_fill_split(splitted, s, c))
	{
		while (i < word_count)
			free(splitted[i++]);
		free(splitted);
		return (NULL);
	}
	return (splitted);
}
