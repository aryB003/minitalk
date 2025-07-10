/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abardhan <abardhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 12:45:19 by abardhan          #+#    #+#             */
/*   Updated: 2025/01/27 22:48:48 by abardhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d_temp;
	unsigned char	*s_temp;

	if (!dst && !src)
		return (NULL);
	d_temp = (unsigned char *)dst;
	s_temp = (unsigned char *)src;
	if (d_temp > s_temp)
	{
		while (len--)
		{
			d_temp[len] = s_temp[len];
		}
	}
	else
		ft_memcpy(d_temp, s_temp, len);
	return (dst);
}
