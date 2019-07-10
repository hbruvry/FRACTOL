/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyhook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 08:25:54 by hbruvry           #+#    #+#             */
/*   Updated: 2018/03/21 10:53:56 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void	ft_colorcontrol(int key)
{
	t_mlx	*m;
	t_ctrl	*c;

	m = ft_getmlx();
	c = ft_getctrl();
	if (key == 82)
		c->col = 0;
	if (key == 83)
		c->col = 1;
	if (key == 84)
		c->col = 2;
	if (key == 85)
		c->col = 3;
	return ;
}

/*
** Control reset and exit;
*/

void	ft_fractcontrol(int key)
{
	t_mlx	*m;
	t_ctrl	*c;

	m = ft_getmlx();
	c = ft_getctrl();
	if (key == 11)
		c->fn = ft_strcpy(c->fn, "burningship");
	if (key == 38)
		c->fn = ft_strcpy(c->fn, "julia");
	if (key == 46)
		c->fn = ft_strcpy(c->fn, "mandelbrot");
	if (key == 51)
	{
		c->p = 50;
		c->s = 100;
		c->c = 0x0;
		c->fx = 0;
		c->fy = 0;
	}
	if (key == 53)
		mlx_destroy_window(m->mlx, m->win);
	if (key == 53)
		exit(0);
	ft_colorcontrol(key);
	return ;
}
