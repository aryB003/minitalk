/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abardhan <abardhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:52:57 by abardhan          #+#    #+#             */
/*   Updated: 2025/01/27 21:43:48 by abardhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long	result;
	long	sign;
	int		i;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	sign = ((str[i] == '-') * -2) + 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((result > LONG_MAX / 10) || (result == LONG_MAX / 10 && sign == 1
				&& str[i] >= '7'))
			return (-1);
		else if ((result > LONG_MAX / 10) || \
			(result == LONG_MAX / 10 && sign == -1 && str[i] >= '8'))
			return (0);
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return ((int)result * sign);
}
