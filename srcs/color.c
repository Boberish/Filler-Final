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

void	ft_print2dc(char **array)
{
	char	**move;
	int		x;
	int		y;

	x = 0;
	y = 0;
	move = array;
	ft_print2dc2(move, x, y);
}

void	ft_print2dc2(char **move, int x, int y)
{
	while (move[x])
	{
		y = 0;
		while (move[x][y])
		{
			if (move[x][y] == 'X')
			{
				ft_putstr_fd("\x1b[36;46m", 2);
				ft_putchar_fd(move[x][y], 2);
				ft_putstr_fd("\x1b[0m", 2);
			}
			else if (move[x][y] == '0')
			{
				ft_putstr_fd("\x1b[30;40m", 2);
				ft_putchar_fd(move[x][y], 2);
				ft_putstr_fd("\x1b[0m", 2);
			}
			color1(move, x, y);
			y++;
		}
		ft_putchar_fd('\n', 2);
		x++;
	}
}

void	color1(char **move, int x, int y)
{
	if (move[x][y] == '1')
	{
		ft_putstr_fd("\x1b[37;47m", 2);
		ft_putchar_fd(move[x][y], 2);
		ft_putstr_fd("\x1b[0m", 2);
	}
	if (move[x][y] == '3')
	{
		ft_putstr_fd("\x1b[33;43m", 2);
		ft_putchar_fd(move[x][y], 2);
		ft_putstr_fd("\x1b[0m", 2);
	}
	if (move[x][y] == 'O')
	{
		ft_putstr_fd("\x1b[31;41m", 2);
		ft_putchar_fd(move[x][y], 2);
		ft_putstr_fd("\x1b[0m", 2);
	}
	if (move[x][y] == '4')
	{
		ft_putstr_fd("\x1b[35;45m", 2);
		ft_putchar_fd(move[x][y], 2);
		ft_putstr_fd("\x1b[0m", 2);
	}
	color2(move, x, y);
}

void	color2(char **move, int x, int y)
{
	if (move[x][y] == '9')
	{
		ft_putstr_fd("\x1b[32;42m", 2);
		ft_putchar_fd(move[x][y], 2);
		ft_putstr_fd("\x1b[0m", 2);
	}
	if (move[x][y] == 14)
	{
		ft_putstr_fd("\x1b[33;43m", 2);
		ft_putchar_fd(move[x][y], 2);
		ft_putstr_fd("\x1b[0m", 2);
	}
	if (move[x][y] == '?')
	{
		ft_putstr_fd("\x1b[31;41m", 2);
		ft_putchar_fd(move[x][y], 2);
		ft_putstr_fd("\x1b[0m", 2);
	}
	if (move[x][y] == '?')
	{
		ft_putstr_fd("\x1b[35;45m", 2);
		ft_putchar_fd(move[x][y], 2);
		ft_putstr_fd("\x1b[0m", 2);
	}
}

int		checkerino(t_fill *f)
{
	f->j = 0;
	f->i = 0;
	f->hold = 0;
	f->hold2 = 0;
	ft_line(f);
	while (f->i <= f->yaxis - 1)
	{
		f->top = 0;
		f->bot = 0;
		f->left = 0;
		f->right = 0;
		if ((f->star = ft_strchr((f->heat)[f->i], f->play2)) != NULL)
		{
			if (ft_strchr(f->star + 1, f->play2) != NULL)
				if_2stars(f);
			else
				if_1star(f);
			f->i++;
		}
		else
			f->i++;
	}
	ft_print2dc(f->heat);
	return (0);
}
