/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahameed <ahameed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:06:12 by ahameed           #+#    #+#             */
/*   Updated: 2022/06/22 18:06:12 by ahameed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>

typedef	struct{
	int	power;
	int	result;
} t_type;

t_type	g_values;

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr (int nb)
{
	if (nb == -2147483648)
	{
		ft_putnbr (nb / 10);
		ft_putchar ('8');
	}
	else if (nb < 0)
	{
		ft_putchar ('-');
		ft_putnbr (-nb);
	}
	else
	{
		if (nb > 9)
		{
			ft_putnbr (nb / 10);
		}
		ft_putchar(48 + nb % 10);
	}
}

void	sighandler(int signum)
{
	if (g_values.power == 8)
	{
		write(1, &g_values.result, 1);
		g_values.power = 0;
		g_values.result = 0;
	}
	if (signum == SIGUSR1)
	{
		g_values.result += 2 ^ g_values.power;
		g_values.power++;
	}
	else if (signum == SIGUSR2)
		g_values.power++;
}

int	main(void)
{
	int	pid;

	pid = getpid();
	write(1, "PID: ", 6);
	ft_putnbr(pid);
	while (1)
	{
		signal(SIGUSR2, sighandler);
		signal(SIGUSR1, sighandler);
		pause();
	}
	return (0);
}