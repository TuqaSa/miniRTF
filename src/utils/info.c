/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:40:06 by rsrour            #+#    #+#             */
/*   Updated: 2025/11/11 10:40:07 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ray_info(t_ray ray)
{
	printf("origin:\n");
	tuple_info(&ray.origin);
	printf("direction:\n");
	tuple_info(&ray.direction);
}

void	light_info(t_light *light)
{
	printf("brightness: %f\n", light->brightness);
	printf("poistion:\n");
	tuple_info(&light->position);
	printf("intensity:\n");
	color_info(&light->intensity);
}
