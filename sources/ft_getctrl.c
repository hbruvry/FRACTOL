/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 12:32:19 by hbruvry           #+#    #+#             */
/*   Updated: 2018/03/21 10:52:44 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

t_ctrl	*ft_getctrl(void)
{
	static	t_ctrl *c = NULL;

	if (c)
		return (c);
	if (!(c = ft_memalloc(sizeof(t_ctrl))))
		return (NULL);
	c->fn = "fractalname";
	c->col = 1;
	c->p = 50;
	c->s = 100;
	c->c = 0x0;
	c->fx = 0;
	c->fy = 0;
	c->mx = 0;
	c->my = 0;
	return (c);
}
