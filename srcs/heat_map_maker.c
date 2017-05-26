/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaylor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 20:14:31 by jaylor            #+#    #+#             */
/*   Updated: 2017/04/04 15:51:49 by jaylor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_makeheatmap(t_fill *f)
{
	f->play2 = (f->play == 'O') ? 'X' : 'O';
	f->heat = (char**)malloc(sizeof(char*) * (f->yaxis + 1));
	f->hold = f->yaxis;
	while (f->hold--)
	{
		f->i = 0;
		f->hold2 = f->xaxis;
		*(f->heat) = ft_strnew(f->xaxis);
		while (f->hold2--)
		{
			if ((*(f->map))[f->i] == f->play
					|| (*(f->map))[f->i] == f->play + 32)
				(*(f->heat))[f->i] = f->play;
			else if (((*(f->map))[f->i] != f->play2 &&
					(*(f->map))[f->i] != f->play2 + 32))
				(*(f->heat))[f->i] = '0';
			else
				(*(f->heat))[f->i] = f->play2;
			f->i += 1;
		}
		f->heat += 1;
		f->map += 1;
	}
	makeheat2(f);
}

void	makeheat2(t_fill *f)
{
	*(f->heat) = 0;
	f->heat -= f->yaxis;
	f->map -= f->yaxis;
	checkerino(f);
}

int		ft_getpiece(t_fill *f)
{
	if (f->line2[1] == 'i')
	{
		f->p_ht = ft_atoi(&(f->line[6]));
		f->p_len = ft_atoi(&(f->line[6 + ft_intlen(f->p_ht)]));
		f->piece = (char**)malloc(sizeof(char*) * (f->p_ht + 1));
		f->piece[f->p_ht] = 0;
		f->hold = f->p_ht;
		while (f->hold--)
		{
			get_next_line(0, &(f->line));
			*(f->piece) = ft_strndup(f->line, f->p_len);
			f->piece++;
			free(f->line);
		}
		f->piece -= f->p_ht;
		return (1);
	}
	return (0);
}

int		ft_getmap(t_fill *f)
{
	if (f->line2[0] == '$')
	{
		if (f->line2[15] != 'p')
			f->play = (f->line2[10] == '1') ? 'O' : 'X';
	}
	if (f->line2[1] == 'l')
	{
		f->yaxis = ft_atoi(&(f->line2[8]));
		f->xaxis = ft_atoi(&(f->line2[8 + ft_intlen(f->yaxis)]));
		f->map = (char**)malloc(sizeof(char*) * (f->yaxis + 1));
		f->map[f->yaxis] = 0;
		get_next_line(0, &(f->line));
		free(f->line);
		f->hold = f->yaxis;
		while (f->hold--)
		{
			get_next_line(0, &(f->line));
			*(f->map) = ft_strndup(&(f->line[4]), f->xaxis);
			f->map++;
			free(f->line);
		}
		f->map -= f->yaxis;
	}
	return (0);
}
