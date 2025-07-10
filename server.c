/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryan <aryan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:45:41 by aryan             #+#    #+#             */
/*   Updated: 2025/07/10 17:28:35 by aryan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int sig)
{
	static unsigned char	c = 0;
	static int				bit_count = 0;

	c <<= 1;

	if (sig == SIGUSR1)
		c |= 1;

	bit_count++;

	if (bit_count == 8)
	{
		if( c == '\0')
			write(1,"\n",1);
		else
			ft_printchar(c);
		c = 0;
		bit_count = 0;
	}
}

int main(void)
{
    ft_printint(getpid());
	ft_printchar('\n');
    
    signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);

	while (1)
		pause();  
	return (0);
}