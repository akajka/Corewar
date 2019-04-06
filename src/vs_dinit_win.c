/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinit_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 11:21:56 by akorobov          #+#    #+#             */
/*   Updated: 2019/04/05 19:04:59 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	dinit_win(void)
{
	endwin();
	system("killall sh music.sh afplay");
	exit(EXIT_SUCCESS);
}
