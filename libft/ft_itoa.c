/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abardhan <abardhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:07:44 by abardhan          #+#    #+#             */
/*   Updated: 2025/01/26 21:10:29 by abardhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_size(int n)
{
	int	i;

	i = 0;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	sign(char *res, int n)
{
	if (n < 0)
		res[0] = '-';
}

static int	true_len(long int *nbr, int num_l)
{
	if (*nbr < 0)
	{
		*nbr = *nbr * (-1);
		num_l++;
	}
	return (num_l);
}

char	*ft_itoa(int n)
{
	size_t		num_l;
	char		*res;
	long int	nbr;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	num_l = num_size(n);
	nbr = n;
	num_l = true_len(&nbr, num_l);
	res = (char *)malloc(sizeof(char) * (num_l + 1));
	if (!res)
		return (NULL);
	res[num_l] = 0;
	while (num_l--)
	{
		res[num_l] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	sign(res, n);
	return (res);
}
