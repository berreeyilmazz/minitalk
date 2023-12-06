/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: havyilma <havyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 01:38:00 by havyilma          #+#    #+#             */
/*   Updated: 2022/12/30 17:07:34 by havyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putstr(char *str)
{
	int	indx;

	indx = 0;
	while (str[indx])
		write(1, &str[indx++], 1);
}

void	ft_decimal(int num)
{
	char	prnt;

	if (num > 9)
		ft_decimal(num / 10);
	prnt = num + 48;
	if (num % 10 < 10)
		prnt = num % 10 + 48;
	write(1, &prnt, 1);
}

int	ft_ascii(char *str)
{
	int	prnt;
	int	indx;

	indx = 0;
	prnt = 0;
	while (str[indx])
		prnt = 10 * prnt + (str[indx++] - 48);
	return (prnt);
}
