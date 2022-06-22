/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahameed <ahameed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:49:14 by ahameed           #+#    #+#             */
/*   Updated: 2022/06/22 20:12:40 by ahameed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int	g_pid;

int	ft_atoi(const char *str)
{
	unsigned int	result;
	int				sign;
	int				i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '	' || str[i] == '\n' || str[i]
		 == '\f' || str[i] == '\v' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	if (result > 2147483647 && sign == 1)
		return (-1);
	else if (result > 2147483648 && sign == -1)
		return (0);
	return (sign * result);
}

int	for_flags(int g_pid)
{
	if (g_pid < 0 || g_pid > 99999)
		return (0);
	else
		return (1);
}

void	function(char *str, int pid)
{
	int	i;
	int	shift;

	i = 0;
	shift = 0;
	while (str[i])
	{
		while (shift < 8)
		{
			if (((str[i] >> shift) & 1) == 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			shift++;
		}
		shift = 0;
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (0);
	g_pid = ft_atoi(argv[1]);
	if (for_flags(g_pid) == 1)
		function(argv[2], g_pid);
	return (0);
}