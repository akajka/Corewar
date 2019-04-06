/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs_sound_die.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:35:04 by akorobov          #+#    #+#             */
/*   Updated: 2019/04/05 19:03:15 by akorobov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		sound_die(void)
{
	static char	*die[3] = {"afplay",
		"./sound/death.mp3",
		NULL};

	if (fork() == 0)
		execv("/usr/bin/afplay", die);
}
