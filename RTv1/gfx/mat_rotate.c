/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwooden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 12:34:37 by mwooden           #+#    #+#             */
/*   Updated: 2017/03/05 17:50:39 by mwooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

static void	mat_theta(float mat[4][4], float theta)
{
	float	s;
	float	c;

	mat_identity(mat);
	s = sin(theta);
	c = cos(theta);
	mat[0][0] = c;
	mat[0][1] = s;
	mat[1][0] = s * -1;
	mat[1][1] = c;
}

static void	mat_phi(float mat[4][4], float phi)
{
	float	s;
	float	c;

	mat_identity(mat);
	s = sin(phi);
	c = cos(phi);
	mat[0][0] = c;
	mat[0][2] = s * -1;
	mat[2][0] = s;
	mat[2][2] = c;
}

static void	mat_psi(float mat[4][4], float psi)
{
	float	s;
	float	c;

	mat_identity(mat);
	s = sin(psi);
	c = cos(psi);
	mat[1][1] = c;
	mat[1][2] = s;
	mat[2][1] = s * -1;
	mat[2][2] = c;
}

void		mat_rotate(float mat[4][4], float psi, float phi, float theta)
{
	float	m_psi[4][4];
	float	m_phi[4][4];
	float	m_theta[4][4];

	mat_psi(m_psi, psi);
	mat_phi(m_phi, phi);
	mat_theta(m_theta, theta);
	mat_mult(mat, m_psi, mat);
	mat_mult(mat, m_phi, mat);
	mat_mult(mat, m_theta, mat);
}
