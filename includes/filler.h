/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_6.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaylor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 20:14:31 by jaylor            #+#    #+#             */
/*   Updated: 2017/03/24 15:51:49 by jaylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct	s_fill
{
	char		**piece;
	char		**map;
	char		**heat;
	char		*line;
	int			yaxis;
	int			xaxis;
	int			p_ht;
	int			p_len;
	int			ogy;
	int			ogx;
	int			y;
	int			x;
	int			i;
	int			j;
	int			a;
	int			hold;
	char		play;
	char		play2;
	char		*star;
	int			count;
	int			hold2;
	int			fd;
	int			top;
	int			bot;
	int			left;
	int			right;
	int			score;
	int			bscore;
	int			bestx;
	int			besty;
	char		*line2;
}				t_fill;

int				placepiece(t_fill *f);
int				placepiece2(t_fill *f);
void			ft_analize(t_fill *f);
int				ft_getpiece(t_fill *f);
int				ft_getmap(t_fill *f);
int				ft_heatcheck(t_fill *f);
void			ft_freeit(t_fill *f);
void			ft_gnlprint(t_fill *f);
void			ft_gnlprint2(t_fill *f);
void			ft_gnlprint3(t_fill *f);
int				ft_print2d(char **array);
void			printvalue(t_fill *f);
void			if_2stars(t_fill *f);
void			if_1star(t_fill *f);
void			ft_analize2(t_fill *f, int k, int r);
void			start_head(t_fill *f);
void			map0_1(t_fill *f);
void			makeheat2(t_fill *f);
void			check_if_on_board(t_fill *f, int x);
void			addheat(t_fill *f, int x, char y);
void			topbot(t_fill *f);
int				checkerino(t_fill *f);
int				ft_initialize(t_fill *f);
void			ft_makeheatmap(t_fill *f);
void			left(t_fill *f);
void			right(t_fill *f);
void			if_2stars(t_fill *f);
void			if_1star(t_fill *f);
void			start_head(t_fill *f);
void			ft_freeit(t_fill *f);
void			ft_print(t_fill *f);
void			ft_print2dc(char **array);
void			color1(char **move, int x, int y);
void			color2(char **move, int x, int y);
void			ft_print2dc2(char **move, int x, int y);
void			copy_line(t_fill *f);
void			check_and_add(t_fill *f, int dis, char heat);
void			ft_line(t_fill *f);
void			ft_line2(t_fill *f);
#endif
