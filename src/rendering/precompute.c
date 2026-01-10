/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precompute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:40:29 by rsrour            #+#    #+#             */
/*   Updated: 2025/11/26 00:10:02 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "shape.h"

t_precomp	prepare_computations(t_ray *ray_r, t_intersection *xs_r)
{
	t_precomp	new;
	t_tuple		tmp;

	ft_memset(&new, 0, sizeof(t_precomp));
	new.t = xs_r->t;
	new.object = xs_r->object;
	new.point = position(*ray_r, new.t);
	new.eyev = tuple_neg(&(ray_r->direction));
	new.normalv = normal_at(new.object, new.point);
	if (tuple_dot_product(&(new.normalv), &(new.eyev)) < 0)
	{
		new.inside = 1;
		new.normalv = tuple_neg(&(new.normalv));
	}
	else
		new.inside = 0;
	tmp = tuple_scale(&new.normalv, 0.001f);
	new.over_point = tuple_add(&new.point, &tmp);
	return (new);
}

void	precomp_info(t_precomp *comp_r)
{
	printf("precompute.t = %f\n", comp_r->t);
	printf("precompute.point\n");
	tuple_info(&comp_r->point);
	printf("precompute.eyev\n");
	tuple_info(&comp_r->eyev);
	printf("precompute.normalv\n");
	tuple_info(&comp_r->normalv);
}
