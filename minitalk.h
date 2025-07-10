/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryan <aryan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:45:45 by aryan             #+#    #+#             */
/*   Updated: 2025/07/10 14:59:58 by aryan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINITALK_H
#define MINITALK_H

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "libft/libft.h"
#include <sys/types.h>

int	check_input(int argc, char **argv);
void sendChar(pid_t pid, char c);
void	handle_signal(int sig);
int ft_printchar(int c);
int ft_printstr(char* str);
int ft_printint(int n);

#endif