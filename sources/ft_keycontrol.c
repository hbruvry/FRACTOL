/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 12:00:51 by hbruvry           #+#    #+#             */
/*   Updated: 2018/03/22 08:24:20 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void	ft_zoomcontrol(int key)
{
	long double	tmp;
	t_ctrl		*c;

	c = ft_getctrl();
	tmp = c->s;
	if (key == 125)
	{
		c->s -= c->s / 10;
		c->fx = c->fx * (c->s / tmp);
		c->fy = c->fy * (c->s / tmp);
	}
	if (key == 126)
	{
		c->s += c->s / 10;
		c->fx = c->fx * (c->s / tmp);
		c->fy = c->fy * (c->s / tmp);
	}
	return ;
}

int		ft_hook(int key, t_ctrl *c)
{
	int		i;

	i = 10;
	if (key == 0)
		c->fx -= i;
	if (key == 1)
		c->fy += i;
	if (key == 2)
		c->fx += i;
	if (key == 13)
		c->fy -= i;
	if (key == 69)
		c->c -= 0x10;
	if (key == 78)
		c->c += 0x10;
	if (key == 123)
		c->p -= 5;
	if (key == 124)
		c->p += 5;
	ft_zoomcontrol(key);
	ft_fractcontrol(key);
	ft_drawthread();
	ft_drawtext();
	return (0);
}

int		ft_mousehook(int x, int y, t_ctrl *c)
{
	t_mlx	*m;

	m = ft_getmlx();
	c->mx = x - WIDTH / 2;
	c->my = y - HEIGHT / 2;
	ft_drawthread();
	ft_drawtext();
	return (0);
}

int		ft_scrollhook(int scroll, int x, int y, t_ctrl *c)
{
	long double	tmp;

	x = 0;
	y = 0;
	tmp = c->s;
	if (scroll == 4)
	{
		c->s -= c->s / 10;
		c->fx = c->fx * (c->s / tmp);
		c->fy = c->fy * (c->s / tmp);
	}
	else if (scroll == 5)
	{
		c->s += c->s / 10;
		c->fx = c->fx * (c->s / tmp);
		c->fy = c->fy * (c->s / tmp);
	}
	return (0);
}

void	ft_keycontrol(void)
{
	t_mlx	*m;
	t_ctrl	*c;

	m = ft_getmlx();
	c = ft_getctrl();
	mlx_hook(m->win, 2, 5, ft_hook, c);
	mlx_hook(m->win, 6, 64, ft_mousehook, c);
	mlx_mouse_hook(m->win, ft_scrollhook, c);
	return ;
}
