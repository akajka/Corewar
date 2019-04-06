/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ystasiv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 15:45:39 by ystasiv           #+#    #+#             */
/*   Updated: 2018/03/29 14:21:17 by ystasiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned long long int	res;
	int						znak;

	res = 0;
	znak = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-')
	{
		znak = -1;
		str++;
	}
	else	if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9' && *str)
	{
		res = res * 10;
		res = res + *str - '0';
		str++;
	}
	if (res >= 9223372036854775807 && znak == 1)
		return (-1);
	if (res > 9223372036854775807 && znak == -1)
		return (0);
	return ((int)(res * znak));
}
