/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_world.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwooden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 16:28:59 by mwooden           #+#    #+#             */
/*   Updated: 2017/03/04 18:23:17 by mwooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

void	mat_world(float mat[4][4], t_fdf *env)
{
	mat_identity(mat);
	mat_scale(mat, env->scale, env->scale, env->scale);
	mat_translate(mat, env->xshift, env->yshift, 0);
	mat_rotate(mat, env->xrot, env->yrot, env->zrot);
}
