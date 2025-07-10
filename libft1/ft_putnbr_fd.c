/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abardhan <abardhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:47:45 by abardhan          #+#    #+#             */
/*   Updated: 2025/01/26 16:58:18 by abardhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int			i;
	long int	nbs;
	char		c[11];

	nbs = n;
	i = 0;
	if (nbs < 0)
	{
		write(fd, "-", 1);
		nbs *= -1;
	}
	while (nbs > 9)
	{
		c[i] = nbs % 10 + '0';
		nbs = nbs / 10;
		i++;
	}
	if (nbs <= 9)
		c[i] = nbs + '0';
	while (i >= 0)
	{
		write(fd, &c[i], 1);
		i--;
	}
}
