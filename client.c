/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: binurtas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:50:01 by binurtas          #+#    #+#             */
/*   Updated: 2023/01/14 18:53:08 by binurtas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	result;
	int	pn;

	i = 0;
	result = 0;
	pn = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || (nptr[i] == 32))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			pn *= -1;
		i++;
	}
	while (nptr[i] <= '9' && nptr[i] >= '0')
	{
		result = (result * 10) + (nptr[i] - '0');
		i++;
	}
	return (result * pn);
}

void	ft_send_bits(int pid, char c)
{
	static int	bit;

	while (bit < 8)
	{
		if ((c & (0x01 << bit)) != 0)
			kill(pid, SIGONE);
		else
			kill(pid, SIGZERO);
		usleep(100);
		bit++;
	}
	bit = 0;
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	i = 0;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (pid == -1)
			return (0);
		while (av[2][i])
		{
			ft_send_bits(pid, av[2][i]);
			i++;
		}
		ft_send_bits(pid, '\n');
	}
	else
	{
		ft_printf("Wrong format. You have to use like this :\n");
		ft_printf("./client <PID> <MESSAGE>\n");
	}
	return (0);
}
