/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_3dp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwooden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 10:07:37 by mwooden           #+#    #+#             */
/*   Updated: 2017/02/09 18:00:16 by mwooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"
#include <math.h>

/*
** y axis = 1
** x axis = 0
*/

static void	draw_x(t_env *env, t_bham *ham, t_3dp *p1, t_3dp *p2)
{
	float		y;
	float		x;

	y = p1->y;
	x = p1->x;
	while ((x * ham->da_sign) < (p2->x * ham->da_sign))
	{
		if (y >= 0 && x >= 0 && y < W_HEIGHT && x <= W_WIDTH)
			put_img_pixel(env, y, x, 16777215);
		if (ham->err > 0)
		{
			ham->err -= 1;
			y += ham->pa_sign;
		}
		ham->err += ham->m;
		x += ham->da_sign;
	}
}

static void	draw_y(t_env *env, t_bham *ham, t_3dp *p1, t_3dp *p2)
{
	float		y;
	float		x;

	y = p1->y;
	x = p1->x;
	while ((y * ham->da_sign) < (p2->y * ham->da_sign))
	{
		if (y >= 0 && x >= 0 && y < W_HEIGHT && x < W_WIDTH)
			put_img_pixel(env, y, x, 16777215);
		if (ham->err > 0)
		{
			ham->err -= 1;
			x += ham->pa_sign;
		}
		ham->err += ham->m;
		y += ham->da_sign;
	}
}

static void	find_axes(t_bham *ham, t_3dp *p1, t_3dp *p2)
{
	float	delta_x;
	float	delta_y;

	delta_x = (float)fabs(p2->x - p1->x);
	delta_y = (float)fabs(p2->y - p1->y);
	if (delta_y > delta_x)
	{
		ham->m = delta_x / delta_y;
		ham->da = 1;
		ham->da_sign = p2->y - p1->y < 0 ? -1 : 1;
		ham->pa = 0;
		ham->pa_sign = p2->x - p1->x < 0 ? -1 : 1;
		ham->err = ham->m - 1;
	}
	else
	{
		ham->m = delta_y / delta_x;
		ham->da = 0;
		ham->da_sign = p2->x - p1->x < 0 ? -1 : 1;
		ham->pa = 1;
		ham->pa_sign = p2->y - p1->y < 0 ? -1 : 1;
		ham->err = ham->m - 1;
	}
}

void		draw_line_3d(t_env *env, t_3dp *p1, t_3dp *p2)
{
	t_bham	*ham;

	ham = (t_bham *)malloc(sizeof(t_bham));
	find_axes(ham, p1, p2);
	if (ham->da == 1)
		draw_y(env, ham, p1, p2);
	else
		draw_x(env, ham, p1, p2);
	free(ham);
}
