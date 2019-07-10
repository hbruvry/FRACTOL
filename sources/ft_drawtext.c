/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawtext.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 08:05:40 by hbruvry           #+#    #+#             */
/*   Updated: 2018/03/21 11:38:26 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void	ft_drawnbr(char *str, int x, int y)
{
	int		col;
	t_mlx	*m;

	col = 0xFFFFFF;
	m = ft_getmlx();
	mlx_string_put(m->mlx, m->win, x, y, col, str);
	free(str);
}

void	ft_drawtext(void)
{
	int		w;
	int		h;
	int		col;
	t_mlx	*m;
	t_ctrl	*c;

	w = WIDTH;
	h = HEIGHT;
	col = 0xFFFFFF;
	m = ft_getmlx();
	c = ft_getctrl();
	mlx_string_put(m->mlx, m->win, 25, 25, col, "FRACTOL - hbruvry");
	mlx_string_put(m->mlx, m->win, w - 140, h - 101, col, "posx =");
	ft_drawnbr(ft_itoa(w / 2 + c->fx), w - 70, h - 101);
	mlx_string_put(m->mlx, m->win, w - 140, h - 84, col, "posy =");
	ft_drawnbr(ft_itoa(w / 2 + c->fy), w - 70, h - 84);
	mlx_string_put(m->mlx, m->win, w - 140, h - 67, col, "scale =");
	ft_drawnbr(ft_itoa(c->s), w - 60, h - 67);
	mlx_string_put(m->mlx, m->win, w - 140, h - 50, col, "prec =");
	ft_drawnbr(ft_itoa(c->p), w - 70, h - 50);
}
