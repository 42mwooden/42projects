/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_3dp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwooden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 03:08:50 by mwooden           #+#    #+#             */
/*   Updated: 2017/01/14 03:11:34 by mwooden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

t_3dp	*create_3dp(double x, double y, double z)
{
	t_3dp	*out;

	out = (t_3dp *)malloc(sizeof(t_3dp));
	out->x = x;
	out->y = y;
	out->z = z;
	return (out);
}
