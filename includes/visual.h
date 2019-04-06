/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorobov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 19:45:44 by akorobov          #+#    #+#             */
/*   Updated: 2019/04/06 12:26:42 by ybuhai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_H
# define VISUAL_H
# include "corewar.h"
# include <ncurses.h>
# include <string.h>
# include <sys/types.h>
# define KEY_ESC 27
# define KEY_SPACE 32

WINDOW *g_win_arena;
WINDOW *g_win_status_bar;

void	init_win(t_cor *cor);
void	dinit_win();
void	init_status_bar(t_cor *cor);
void	update_arena(t_cor *cor);
void	update(WINDOW *win);
void	key_control();
void	print_control_key();
void	print_players_info(t_cor *cor);
void	print_header();
void	init_status_bar(t_cor *cor);
void	print_border(int y);
void	ftoa(float n, char *ret, int afterpoint);
void	update_bar(t_cor *cor);
void	winner(t_hero winner);
void	sound_die();

char	*g_music_set;
int		g_delay;
float	g_speed;

#endif
