/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 12:32:19 by hbruvry           #+#    #+#             */
/*   Updated: 2018/03/19 15:04:33 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

t_mlx	*ft_getmlx(void)
{
	static	t_mlx *m = NULL;

	if (m)
		return (m);
	if (!(m = ft_memalloc(sizeof(t_mlx))))
		return (NULL);
	m->mlx = mlx_init();
	m->win = mlx_new_window(m->mlx, WIDTH, HEIGHT, "Fractol");
	m->pic = mlx_new_image(m->mlx, WIDTH, HEIGHT);
	m->picstr = (int*)mlx_get_data_addr(m->pic, &m->a, &m->b, &m->c);
	m->a = 0;
	m->b = 0;
	m->c = 0;
	return (m);
}
