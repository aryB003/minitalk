/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abardhan <abardhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 11:07:33 by abardhan          #+#    #+#             */
/*   Updated: 2025/01/26 16:09:05 by abardhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d_temp;
	unsigned char	*s_temp;

	if (!dst && !src)
		return (NULL);
	i = 0;
	d_temp = (unsigned char *)dst;
	s_temp = (unsigned char *)src;
	while (i < n)
	{
		d_temp[i] = s_temp[i];
		i++;
	}
	return (dst);
}
