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

void	left(t_fill *f)
{
	f->right = 0;
	f->j = f->star - f->heat[f->i];
	check_and_add(f, 3, '1');
	check_and_add(f, 1, '4');
	check_and_add(f, 2, '3');
	check_and_add(f, 0, '1');
	if (f->yaxis > 15)
	{
		check_and_add(f, 9, '3');
		check_and_add(f, 10, '3');
		check_and_add(f, 20, '1');
	}
}

void	right(t_fill *f)
{
	f->star = ft_strrchr((f->heat)[f->i], f->play2);
	f->j = f->star - f->heat[f->i];
	check_and_add(f, 3, '2');
	check_and_add(f, 1, '4');
	check_and_add(f, 2, '3');
	check_and_add(f, 0, '1');
	if (f->yaxis > 15)
	{
		check_and_add(f, 9, '3');
		check_and_add(f, 10, '3');
		check_and_add(f, 20, '1');
	}
}

void	if_2stars(t_fill *f)
{
	f->left = 1;
	left(f);
	f->left = 0;
	f->right = 1;
	right(f);
	f->right = 0;
	f->top = 1;
	f->bot = 1;
	topbot(f);
}

void	if_1star(t_fill *f)
{
	if_2stars(f);
}

void	topbot(t_fill *f)
{
	check_and_add(f, 1, '5');
}
