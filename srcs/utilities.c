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

void	addheat(t_fill *f, int x, char y)
{
	if (f->top && f->heat[f->i - 1 - x][f->j] != f->play2 &&
			f->heat[f->i - 1 - x][f->j] &&
			f->heat[f->i - 1 - x][f->j] != f->play)
		f->heat[f->i - 1 - x][f->j] = y;
	if (f->bot && f->heat[f->i + 1 + x][f->j] != f->play2 &&
			f->heat[f->i + 1 + x][f->j] && f->heat[f->i + 1 + x][f->j]
			!= f->play)
		f->heat[f->i + 1 + x][f->j] = y;
	if (f->left && f->heat[f->i][f->j - 1 - x] != f->play2 &&
			f->heat[f->i][f->j - 1 - x] && f->heat[f->i][f->j - 1 - x]
			!= f->play)
		f->heat[f->i][f->j - 1 - x] = y;
	if (f->right && f->heat[f->i][f->j + 1 + x] != f->play2 &&
			f->heat[f->i][f->j + 1 + x] && f->heat[f->i][f->j + 1 + x]
			!= f->play)
		f->heat[f->i][f->j + 1 + x] = y;
}

void	start_head(t_fill *f)
{
	int i;
	int j;

	i = 0;
	j = 0;
	f->star = NULL;
}

void	copy_line(t_fill *f)
{
	f->line2 = ft_strdup(f->line);
	free(f->line);
}

void	check_and_add(t_fill *f, int dis, char heat)
{
	check_if_on_board(f, dis);
	addheat(f, dis, heat);
}

void	ft_line(t_fill *f)
{
	int i;

	i = 3;
	while (i < 7)
	{
		if (f->heat[8][i] != f->play && f->heat[8][i] != f->play2)
			f->heat[8][i] = '9';
		i++;
	}
	i = 4;
	while (i < 17)
	{
		if (f->heat[7][i] != f->play && f->heat[7][i] != f->play2)
			f->heat[7][i] = '9';
		i++;
	}
	i = 6;
	while (i < 17)
	{
		if (f->heat[6][i] != f->play && f->heat[6][i] != f->play2)
			f->heat[6][i] = '5';
		i++;
	}
	ft_line2(f);
}
