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

void	ft_analize(t_fill *f)
{
	int a;
	int k;
	int r;

	a = -1;
	k = 0;
	r = 0;
	f->hold = 0;
	f->x = (f->p_len - 1) * -1;
	f->y = (f->p_ht - 1) * -1;
	f->i = 0;
	f->j = 0;
	f->ogx = f->x;
	f->ogy = f->y;
	while (f->yaxis - 1 > a++)
	{
		ft_analize2(f, k, r);
		k = 0;
		f->ogy += 1;
		f->ogx -= f->xaxis;
		f->y = f->ogy;
		f->x = f->ogx;
	}
	f->bscore = 0;
}

void	ft_analize2(t_fill *f, int k, int r)
{
	while (f->xaxis > k)
	{
		if ((placepiece(f) == 0))
		{
			if (f->bscore == 0)
				map0_1(f);
			if ((r = ft_heatcheck(f) > f->bscore))
			{
				f->bscore = r;
				f->bestx = f->ogx;
				f->besty = f->ogy;
			}
		}
		f->i = 0;
		f->j = 0;
		f->ogx += 1;
		f->x = f->ogx;
		f->y = f->ogy;
		k++;
	}
}

void	map0_1(t_fill *f)
{
	if ((f->yaxis == 15 && f->play == 'X') ||
			(f->yaxis == 100 && f->play == 'O')
			|| (f->yaxis == 24 && f->play == 'X'))
	{
		if (f->hold2 == 0)
		{
			f->bestx = f->ogx;
			f->besty = f->ogy;
		}
		f->hold2 = 1;
	}
	else
	{
		f->bestx = f->ogx;
		f->besty = f->ogy;
	}
}

void	printvalue(t_fill *f)
{
	ft_putnbr(f->besty);
	ft_putchar(' ');
	ft_putnbr(f->bestx);
	ft_putchar('\n');
}

int		ft_initialize(t_fill *f)
{
	f->piece = NULL;
	f->map = NULL;
	f->heat = NULL;
	f->line = NULL;
	f->yaxis = 0;
	f->xaxis = 0;
	f->p_ht = 0;
	f->p_len = 0;
	f->ogy = 0;
	f->ogx = 0;
	f->y = 0;
	f->x = 0;
	f->a = 0;
	f->i = 0;
	f->j = 0;
	f->hold = 0;
	f->star = NULL;
	f->count = 0;
	f->hold2 = 0;
	f->fd = 0;
	f->bscore = 0;
	return (0);
}
