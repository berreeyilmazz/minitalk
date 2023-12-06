/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: havyilma <havyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 01:38:22 by havyilma          #+#    #+#             */
/*   Updated: 2022/12/30 17:05:57 by havyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_response(int sig, siginfo_t *info, void *unused)
{
	(void)sig;
	(void)info;
	(void)unused;
	ft_putstr("Signal Delivered\n");
}

void	ft_bitwiser(int s_pid, unsigned char *mes)
{
	int	base;
	int	indx;

	base = 128;
	indx = 0;
	while (mes[indx])
	{
		while (base >= 1)
		{
			if (mes[indx] / base)
			{
				kill(s_pid, SIGUSR1);
				mes[indx] = mes[indx] - base;
			}
			else
				kill(s_pid, SIGUSR2);
			usleep(100);
			base /= 2;
		}
		base = 128;
		indx++;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	resp;

	resp.sa_flags = SA_SIGINFO;
	resp.sa_sigaction = ft_response;
	if (sigaction(SIGUSR2, &resp, 0) == -1)
		ft_putstr("Signal couldn't be delivered!");
	if (argc == 3)
		ft_bitwiser(ft_ascii(argv[1]), (unsigned char *)argv[2]);
	else
		ft_putstr("Wrong input, please try again!");
}
