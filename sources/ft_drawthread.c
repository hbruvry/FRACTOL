/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawthread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 09:08:17 by hbruvry           #+#    #+#             */
/*   Updated: 2018/03/20 10:06:43 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void	ft_drawthread(void)
{
	int			i;
	pthread_t	thread[THREADS];
	t_env		**e;
	t_mlx		*m;

	i = -1;
	m = ft_getmlx();
	e = ft_getenv(THREADS);
	while (++i < THREADS)
	{
		if (pthread_create(&thread[i], NULL, ft_drawfract, e[i]))
			return ;
	}
	i = -1;
	while (++i < THREADS)
	{
		if (pthread_join(thread[i], NULL))
			return ;
	}
	mlx_put_image_to_window(m->mlx, m->win, m->pic, 0, 0);
	return ;
}
