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

int		placepiece(t_fill *f)
{
	f->count = 0;
	while (f->piece[f->i] != 0)
	{
		while (f->piece[f->i][f->j] != '\0')
		{
			if (f->piece[f->i][f->j] == '*')
			{
				if (placepiece2(f) == 1)
					return (1);
			}
			else
			{
				f->x++;
				f->j++;
			}
		}
		f->j = 0;
		f->x = f->ogx;
		f->i++;
		f->y++;
	}
	if (f->count != 1)
		return (1);
	return (0);
}

int		placepiece2(t_fill *f)
{
	if (f->ogy + f->i < 0 || f->ogx + f->j < 0)
		return (1);
	if (f->ogy + f->i > f->yaxis - 1 || f->ogx + f->j > f->xaxis)
		return (1);
	if (f->map[f->y][f->x] != f->play2 && f->map[f->y][f->x] != f->play2 + 32)
	{
		if (f->map[f->y][f->x] == f->play || f->map[f->y][f->x] == f->play + 32)
		{
			f->count++;
			if (f->count > 1)
				return (1);
		}
		f->j++;
		f->x++;
	}
	else
		return (1);
	return (0);
}

void	ft_freeit(t_fill *f)
{
	f->hold = 0;
	while (f->hold <= f->yaxis)
	{
		if (f->map[f->hold])
			free(f->map[f->hold]);
		if (f->heat[f->hold])
			free(f->heat[f->hold]);
		f->hold++;
	}
	f->hold = 0;
	while (f->hold <= f->p_ht)
	{
		if (f->piece[f->hold])
			free(f->piece[f->hold]);
		f->hold++;
	}
	if (f->map)
		free(f->map);
	if (f->piece)
		free(f->piece);
	if (f->heat)
		free(f->heat);
}

void	ft_line2(t_fill *f)
{
	int i;

	i = 6;
	while (i < 17)
	{
		if (f->heat[6][i] != f->play && f->heat[6][i] != f->play2)
			f->heat[6][i] = '9';
		i++;
	}
}
