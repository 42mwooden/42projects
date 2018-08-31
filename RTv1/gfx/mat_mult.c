/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwooden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 13:29:07 by mwooden           #+#    #+#             */
/*   Updated: 2017/01/19 14:36:31 by mwooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "gfx.h"

void	mat_mult(float mat1[4][4], float mat2[4][4], float res[4][4])
{
	float	m1[4][4];
	float	m2[4][4];
	int		i;
	int		j;
	int		k;

	mat_copy(mat1, m1);
	mat_copy(mat2, m2);
	mat_bzero(res);
	i = 0;
	j = 0;
	k = -1;
	while (i < 4)
	{
		while (j < 4)
		{
			while (++k < 4)
				res[i][j] += m1[i][k] * m2[k][j];
			k = -1;
			j++;
		}
		j = 0;
		i++;
	}
}
