/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: binurtas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:44:41 by binurtas          #+#    #+#             */
/*   Updated: 2023/01/14 18:49:08 by binurtas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handler(int signal)
{
	static int				bit;
	static unsigned char	i;

	if (signal == SIGONE)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
	}
}

int	main(int ac, char **av)
{
	(void)av;
	if (ac != 1)
	{
		ft_printf("You should use like this :\n./server");
		return (0);
	}
	ft_printf("PID : %d\n", getpid());
	while (ac == 1)
	{
		signal(SIGONE, ft_handler);
		signal(SIGZERO, ft_handler);
		pause();
	}
	return (0);
}
