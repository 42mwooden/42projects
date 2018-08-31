/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_translate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwooden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 13:19:05 by mwooden           #+#    #+#             */
/*   Updated: 2017/01/19 14:53:37 by mwooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

void	mat_translate(float mat[4][4], float x, float y, float z)
{
	float	m_trans[4][4];

	mat_identity(m_trans);
	m_trans[0][3] = x;
	m_trans[1][3] = y;
	m_trans[2][3] = z;
	mat_mult(mat, m_trans, mat);
}
