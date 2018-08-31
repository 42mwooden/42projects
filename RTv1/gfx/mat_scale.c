/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_scale.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwooden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 13:24:30 by mwooden           #+#    #+#             */
/*   Updated: 2017/01/19 13:28:09 by mwooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

void	mat_scale(float mat[4][4], float x, float y, float z)
{
	float	m_scale[4][4];

	mat_identity(m_scale);
	m_scale[0][0] = x;
	m_scale[1][1] = y;
	m_scale[2][2] = z;
	mat_mult(mat, m_scale, mat);
}
