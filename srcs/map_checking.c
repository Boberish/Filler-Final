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

int		ft_heatcheck(t_fill *f)
{
	f->i = 0;
	f->y = 0;
	f->x = f->ogx;
	f->y = f->ogy;
	f->score = 0;
	while (f->piece[f->i] != 0)
	{
		while (f->piece[f->i][f->j] != '\0')
		{
			if (f->piece[f->i][f->j] == '*')
			{
				if (f->heat[f->y][f->x] != '0' &&
				f->heat[f->y][f->x] != f->play)
					f->score += f->heat[f->y][f->x] - '0';
			}
			f->x++;
			f->j++;
		}
		f->j = 0;
		f->x = f->ogx;
		f->i++;
		f->y++;
	}
	return (f->score);
}

void	check_if_on_board(t_fill *f, int x)
{
	if (f->i + x >= f->yaxis - 1)
		f->bot = 0;
	if (f->i <= 0 + x)
		f->top = 0;
	if (f->j <= 0 + x)
		f->left = 0;
	if (f->j + x >= f->xaxis)
		f->right = 0;
}
