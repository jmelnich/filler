/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 14:43:29 by imelnych          #+#    #+#             */
/*   Updated: 2017/10/23 14:43:30 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	int a;
	int b;

	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		if (nb == -2147483648)
		{
			ft_putchar_fd('2', fd);
			nb = nb % 1000000000;
		}
		nb = nb * (-1);
	}
	if ((nb / 10) != 0)
	{
		a = nb % 10;
		b = nb / 10;
		ft_putnbr_fd(b, fd);
		ft_putchar_fd(a + '0', fd);
	}
	if ((nb / 10) == 0)
	{
		ft_putchar_fd(nb + '0', fd);
	}
}
