/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryan <aryan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:45:38 by aryan             #+#    #+#             */
/*   Updated: 2025/07/10 14:55:32 by aryan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int ft_printchar(int c)
{
    return( write(1, &c, 1));
}

int ft_printstr(char* str)
{
    int	i;

	i = 0;
	if (str == NULL)
	{
		ft_printstr("(null)");
		return (6);
	}
	while (*str != '\0')
	{
		ft_printchar((int)*str);
		str++;
		i++;
	}
	return (i);
}

int ft_printint(int n)
{
    int	count;

	count = 0;
	if (n == -2147483648)
	{
		return (ft_printstr("-2147483648"));
	}
	else if (n < 0)
	{
		count += ft_printchar('-');
		n = -n;
	}
	else if (n == 0)
	{
		return (ft_printchar('0'));
	}
	if (n >= 10)
	{
		count += ft_printint(n / 10);
	}
	count += ft_printchar((n % 10) + '0');
	return (count);
}