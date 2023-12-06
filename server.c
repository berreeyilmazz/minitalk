/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: havyilma <havyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 01:38:24 by havyilma          #+#    #+#             */
/*   Updated: 2022/12/30 17:07:49 by havyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_takebyt(int signumb, siginfo_t *siginfo, void *unused)
{
	static int	prnt = 0;
	static int	move = 7;

	(void)unused;
	if (signumb == SIGUSR1)
		signumb = 1;
	if (signumb == SIGUSR2)
		signumb = 0;
	prnt += signumb << move;
	if (move == 0)
	{
		write(1, &prnt, 1);
		move = 7;
		prnt = 0;
		if (kill(siginfo->si_pid, SIGUSR2) == -1)
			ft_putstr("Something went wrong!");
	}
	else
		move--;
}

int	main(void)
{
	struct sigaction	message;

	ft_putstr("PID Adress : ");
	ft_decimal(getpid());
	write(1, "\n", 1);
	message.sa_flags = SA_SIGINFO;
	message.sa_sigaction = ft_takebyt;
	if (sigaction(SIGUSR1, &message, 0) == -1)
		ft_putstr("Signal(1) error!\n");
	if (sigaction(SIGUSR2, &message, 0) == -1)
		ft_putstr("Signal(2) error!\n");
	while (1)
		pause();
}
