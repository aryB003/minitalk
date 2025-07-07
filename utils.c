/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryan <aryan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:45:38 by aryan             #+#    #+#             */
/*   Updated: 2025/07/07 18:29:16 by aryan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int ft_printchar(int c)
{
    return( write(1, &c, 1));
}

int ft_printstring(char* str)
{
    int	i;

	i = 0;
	if (str == NULL)
	{
		ft_printfstr("(null)");
		return (6);
	}
	while (*str != '\0')
	{
		ft_printfchar((int)*str);
		str++;
		i++;
	}
	return (i);
}