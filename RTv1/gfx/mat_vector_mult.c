/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_vector_mult.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwooden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 14:41:11 by mwooden           #+#    #+#             */
/*   Updated: 2017/01/19 15:19:15 by mwooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

static void	get_vert(t_3dp *src, float vert[4])
{
	vert[0] = src->x;
	vert[1] = src->y;
	vert[2] = src->z;
	vert[3] = 1;
}

void		mat_vector_mult(t_3dp *src, float mat[4][4], t_3dp *dst)
{
	float	vert[4];
	int		i;

	get_vert(src, vert);
	dst->x = 0;
	dst->y = 0;
	dst->z = 0;
	i = 0;
	while (i < 4)
	{
		dst->x += mat[0][i] * vert[i];
		dst->y += mat[1][i] * vert[i];
		dst->z += mat[2][i] * vert[i];
		i++;
	}
}
