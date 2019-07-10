/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawfract.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 12:43:07 by hbruvry           #+#    #+#             */
/*   Updated: 2018/03/22 08:21:56 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

t_nbr	ft_setburnship(t_pos p, t_nbr n, t_env *e)
{
	t_ctrl	*c;

	c = ft_getctrl();
	e->fw = (1 - (-2.5)) * c->s;
	e->fh = (1 - (-1)) * c->s;
	n.zr = c->mx * 0.001;
	n.zi = c->my * 0.001;
	n.r = (p.x + c->fx + (e->fw - WIDTH) / 2) / c->s + (-2.5);
	n.i = (p.y + c->fy + (e->fh - HEIGHT) / 2) / c->s + (-1);
	return (n);
}

t_nbr	ft_setfract(t_pos p, t_nbr n, t_env *e)
{
	t_ctrl	*c;

	c = ft_getctrl();
	if (!ft_strcmp("mandelbrot", c->fn))
	{
		e->fw = (0.6 - (-2.1)) * c->s;
		e->fh = (1.2 - (-1.2)) * c->s;
		n.zr = c->mx * 0.001;
		n.zi = c->my * 0.001;
		n.r = (p.x + c->fx + (e->fw - WIDTH) / 2) / c->s + (-2.1);
		n.i = (p.y + c->fy + (e->fh - HEIGHT) / 2) / c->s + (-1.2);
	}
	if (!ft_strcmp("julia", c->fn))
	{
		e->fw = (1 - (-1)) * c->s;
		e->fh = (1.2 - (-1.2)) * c->s;
		n.r = 0.285 + c->mx * 0.001;
		n.i = 0.01 + c->my * 0.001;
		n.zr = (p.x + c->fx + e->fw / 2 - WIDTH / 2) / c->s + (-1);
		n.zi = (p.y + c->fy + e->fh / 2 - HEIGHT / 2) / c->s + (-1.2);
	}
	if (!ft_strcmp("burningship", c->fn))
		return (ft_setburnship(p, n, e));
	return (n);
}

int		ft_setcol(int i)
{
	int		col;
	t_ctrl	*c;

	c = ft_getctrl();
	if (i == c->p)
		return (0x000000);
	i = 255 * i / c->p;
	if (c->col == 0)
		col = 2 * i * 0x10101;
	else if (c->col == 1)
	{
		col = 0xFF0000;
		col = col - i * 0x10000 + i * 0x100 + i * 0x10101;
	}
	else if (c->col == 2)
	{
		col = 0x00FF00;
		col = col - i * 0x100 + i + i * 0x10101;
	}
	else
	{
		col = 0x0000FF;
		col = col + i * 0x10000 - i + i * 0x010101;
	}
	return (col + i * c->c);
}

int		ft_getcol(t_nbr n)
{
	int			i;
	long double	tmp;
	int			col;
	t_ctrl		*c;

	i = -1;
	c = ft_getctrl();
	while (++i < c->p && n.zr * n.zr + n.zi * n.zi < 4)
	{
		if (!ft_strcmp("burningship", c->fn))
		{
			tmp = n.zr * n.zr - n.zi * n.zi + n.r;
			n.zi = fabsl(2 * n.zr * n.zi + n.i);
			n.zr = fabsl(tmp);
		}
		else
		{
			tmp = n.zr;
			n.zr = n.zr * n.zr - n.zi * n.zi + n.r;
			n.zi = 2 * n.zi * tmp + n.i;
		}
	}
	col = ft_setcol(i);
	return (col);
}

void	*ft_drawfract(void *ag)
{
	t_pos	p;
	t_nbr	n;
	t_mlx	*m;
	t_env	*e;

	m = ft_getmlx();
	e = (t_env*)ag;
	p.x = -1;
	p.y = e->y - 1;
	while (++p.y < e->ty)
	{
		while (++p.x < WIDTH)
		{
			n.zr = 0;
			n.zi = 0;
			n = ft_setfract(p, n, e);
			if (p.x < WIDTH && p.y < HEIGHT)
				m->picstr[p.y * WIDTH + p.x] = ft_getcol(n);
		}
		p.x = -1;
	}
	pthread_exit(NULL);
}
