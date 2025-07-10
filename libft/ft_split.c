/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abardhan <abardhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 21:13:24 by abardhan          #+#    #+#             */
/*   Updated: 2025/01/26 23:34:29 by abardhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	safe_malloc(char **res, int pos, size_t slen)
{
	int	i;

	i = 0;
	res[pos] = malloc(slen);
	if (res[pos] == NULL)
	{
		while (i < pos)
		{
			free(res[i]);
			i++;
		}
		free(res);
		return (1);
	}
	return (0);
}

int	fill_str(char **res, const char *s, char c)
{
	size_t	len;
	int		i;

	i = 0;
	while (*s)
	{
		len = 0;
		while (*s == c && *s)
			s++;
		while (*s != c && *s)
		{
			++len;
			++s;
		}
		if (len)
		{
			if (safe_malloc(res, i, len + 1))
				return (1);
			ft_strlcpy(res[i], s - len, len + 1);
		}
		i++;
	}
	return (0);
}

size_t	count_words(char const *s, char c)
{
	size_t	words;
	int		inner;

	words = 0;
	while (*s)
	{
		inner = 0;
		while (*s == c && *s)
			s++;
		while (*s != c && *s)
		{
			if (!inner)
			{
				words++;
				inner = 1;
			}
			s++;
		}
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	size_t	words;
	char	**res_sen;

	words = 0;
	words = count_words(s, c);
	res_sen = malloc((words + 1) * sizeof(char *));
	if (res_sen == NULL)
		return (NULL);
	res_sen[words] = NULL;
	if (fill_str(res_sen, s, c))
		return (NULL);
	return (res_sen);
}
