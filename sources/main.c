/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 11:18:49 by hbruvry           #+#    #+#             */
/*   Updated: 2018/03/22 07:59:52 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void	ft_fractol(void)
{
	t_mlx	*m;

	m = ft_getmlx();
	ft_drawthread();
	ft_drawtext();
	ft_keycontrol();
	mlx_loop(m->mlx);
	return ;
}

int		ft_chooseprocess(char **ag, int ac, char **av)
{
	pid_t	pid;
	t_ctrl	*c;

	pid = fork();
	c = ft_getctrl();
	c->fn = ft_strdup(av[ac - 1]);
	if (pid == -1)
		return (-1);
	else if (!pid)
	{
		if (ac > 2)
			if (execv("./fractol", ag) == -1)
				exit(EXIT_FAILURE);
	}
	else
	{
		if (ac < 3)
		{
			ft_putstr("place : w/a/s/d\nscale : up/down or scroll\n");
			ft_putstr("detail : left/right\ncolor : 0/1/2/3\ncustom : +/-\n");
			ft_putstr("fract : b/j/m\nreset : delete\nclose : escape");
		}
		ft_fractol();
	}
	exit(EXIT_SUCCESS);
}

int		main(int ac, char **av)
{
	char	*ag[3];

	if (ac != 1)
	{
		ag[0] = ft_strdup("fractol");
		ag[1] = ft_strdup(av[1]);
		ag[2] = NULL;
	}
	if (ac < 2 || 3 < ac)
	{
		ft_putstr("usage: ./fractol fractal_name\n");
		ft_putstr("fractals: mandelbrot/julia/burningship\n");
		return (0);
	}
	if ((ft_strcmp("mandelbrot", av[1]) && ft_strcmp("julia", av[1])
	&& ft_strcmp("burningship", av[1])) || (ft_strcmp("mandelbrot", av[ac - 1])
	&& ft_strcmp("julia", av[ac - 1]) && ft_strcmp("burningship", av[ac - 1])))
	{
		ft_putstr("usage: ./fractol fractal_name\n");
		ft_putstr("fractals: mandelbrot/julia/burningship\n");
		return (0);
	}
	ft_chooseprocess(ag, ac, av);
	return (0);
}
