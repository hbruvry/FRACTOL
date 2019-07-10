/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbruvry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 12:32:19 by hbruvry           #+#    #+#             */
/*   Updated: 2018/03/21 10:17:49 by hbruvry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

t_env	**ft_getenv(int i)
{
	int				j;
	static t_env	**e = NULL;

	j = -1;
	if (e)
		return (e);
	if (!(e = ft_memalloc(i * sizeof(t_env*))))
		return (NULL);
	while (++j < i)
	{
		if (!(e[j] = ft_memalloc(sizeof(t_env))))
			return (NULL);
	}
	j = -1;
	while (++j < i)
	{
		e[j]->fw = 0;
		e[j]->fh = 0;
		e[j]->y = j * ((float)HEIGHT / i);
		e[j]->ty = (j + 1) * ((float)HEIGHT / i);
	}
	return (e);
}
