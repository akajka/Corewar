/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ystasiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 15:09:49 by ystasiv           #+#    #+#             */
/*   Updated: 2018/03/27 15:44:01 by ystasiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int x;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		x = -n;
	}
	else
		x = n;
	if (x / 10 > 0)
		ft_putnbr_fd(x / 10, fd);
	ft_putchar_fd(x % 10 + 48, fd);
}
