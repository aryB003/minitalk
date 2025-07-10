/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abardhan <abardhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:58:58 by abardhan          #+#    #+#             */
/*   Updated: 2025/01/25 21:21:12 by abardhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*temp;

	if (size && count > (SIZE_MAX / size))
		return (NULL);
	temp = malloc(count * size);
	if (!temp)
		return (NULL);
	ft_bzero(temp, count * size);
	return ((void *)temp);
}
