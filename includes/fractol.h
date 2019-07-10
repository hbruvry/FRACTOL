/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 11:39:38 by hbruvry           #+#    #+#             */
/*   Updated: 2018/06/12 11:19:08 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FRACTOL_H
# define __FRACTOL_H

# include "libft/libft.h"
# include "/usr/local/include/mlx.h"
# include <math.h>
# include <fcntl.h>
# include <errno.h>
# include <pthread.h>

# define WIDTH 500
# define HEIGHT 500
# define THREADS 64

typedef	struct	s_mlx
{
	void		*mlx;
	void		*win;
	void		*pic;
	int			*picstr;
	int			a;
	int			b;
	int			c;
}				t_mlx;

typedef	struct	s_env
{
	long double	fw;
	long double	fh;
	int			y;
	int			ty;
}				t_env;

typedef	struct	s_ctrl
{
	char		*fn;
	int			col;
	int			p;
	long double	s;
	int			c;
	long long	fx;
	long long	fy;
	int			mx;
	int			my;
}				t_ctrl;

typedef	struct	s_nbr
{
	long double	r;
	long double	i;
	long double	zr;
	long double	zi;
}				t_nbr;

typedef	struct	s_pos
{
	int			x;
	int			y;
}				t_pos;

typedef	struct	s_inc
{
	float		i;
	float		j;
	float		k;
	float		l;
}				t_inc;

t_mlx			*ft_getmlx(void);
t_ctrl			*ft_getctrl(void);
t_env			**ft_getenv(int i);
void			ft_drawthread(void);
void			*ft_drawfract(void *ag);
void			ft_drawtext(void);
void			ft_fractcontrol(int key);
void			ft_keycontrol(void);

#endif
