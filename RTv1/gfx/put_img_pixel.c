/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwooden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 10:09:19 by mwooden           #+#    #+#             */
/*   Updated: 2017/03/05 23:10:57 by mwooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

void	put_img_pixel(t_env *env, float y, float x, unsigned int color)
{
	int		i;
	int		tx;
	int		ty;

	tx = (int)x;
	ty = (int)y;
	(void)color;
	i = (tx * 4) + (ty * env->size_line);
	env->img[i] = 0xFF;
	env->img[i + 1] = 0xFF;
	env->img[i + 2] = 0xFF;
}
