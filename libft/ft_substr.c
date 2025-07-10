/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abardhan <abardhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 21:22:53 by abardhan          #+#    #+#             */
/*   Updated: 2025/01/26 11:16:22 by abardhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len || len == 0 || !*s)
		return (ft_strdup(""));
	if (len > s_len - start)
		sub_s = malloc(sizeof(char) * ((s_len - start) + 1));
	else
		sub_s = malloc(sizeof(char) * (len + 1));
	if (sub_s == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[start])
	{
		sub_s[i] = s[start];
		start++;
		i++;
	}
	sub_s[i] = '\0';
	return (sub_s);
}
