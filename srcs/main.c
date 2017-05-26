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

int	main(void)
{
	t_fill *f;

	f = ft_memalloc(sizeof(t_fill));
	ft_initialize(f);
	while (get_next_line(0, &(f->line)) > 0)
	{
		copy_line(f);
		ft_getmap(f);
		if (ft_getpiece(f) == 1)
		{
			ft_makeheatmap(f);
			ft_analize(f);
			printvalue(f);
			ft_freeit(f);
		}
		free(f->line2);
	}
	free(f);
	return (0);
}
