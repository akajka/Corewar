/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_for_help.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybuhai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 14:24:39 by ybuhai            #+#    #+#             */
/*   Updated: 2019/04/04 19:48:46 by ybuhai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		is_filename(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	i -= 4;
	if (i > 0)
		return (ft_strcmp(&str[i], ".cor"));
	else
		return (1);
}

void	add_file(t_cor *cor, int *i, char **argv)
{
	t_files *tmp;

	if (!cor->list)
		cor->list = create_list(0, argv[*i]);
	else
	{
		tmp = cor->list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = create_list(0, argv[*i]);
	}
	(*i)++;
}

int		find_adress(int i)
{
	i %= MEM_SIZE;
	if (i < 0)
		i += MEM_SIZE;
	return (i);
}

t_files	*create_list(int i, char *data)
{
	t_files *new;

	new = (t_files *)malloc(sizeof(t_files));
	new->id = i;
	new->file = data;
	new->next = NULL;
	return (new);
}

int		mod_atoi(char *str)
{
	long	res;
	int		minus;
	int		i;

	res = 0;
	i = 0;
	minus = str[i] == '-' ? -1 : 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		res = res * 10 + str[i] - 48;
		if (res > 2147483648)
			return (-1);
		i++;
	}
	if ((minus == 1 && res >= 2147483648) || str[i])
		return (-1);
	return ((int)res * minus);
}
