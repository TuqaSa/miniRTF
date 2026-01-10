/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 21:20:13 by tsaeed            #+#    #+#             */
/*   Updated: 2025/11/26 01:21:29 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"
#include "data_ctxs.h"
#include "parsing.h"

t_light	*point_light(t_tuple position, t_color intensity, float brightness)
{
	t_light	*result;

	result = (t_light *)calloc(1, sizeof(t_light));
	if (!result)
		return (NULL);
	result->position = position;
	ft_fill_color(&(result->intensity), intensity);
	result->brightness = brightness;
	result->next = NULL;
	return (result);
}

t_color	diffuse_cal(t_color effective_color, float diffuse_factor,
		t_tuple lightv, t_tuple normalv)
{
	float	light_dot_normal;

	light_dot_normal = tuple_dot_product(&lightv, &normalv);
	if (light_dot_normal < 0)
		return (color(0, 0, 0));
	return (multcolor(effective_color, diffuse_factor * light_dot_normal));
}

t_color	specular_cal(t_light **light_r, t_precomp *comp_r, t_tuple lightv)
{
	t_tuple	reflectv;
	t_tuple	neg_lightv;
	float	reflect_dot_eye;
	float	factor;

	neg_lightv = tuple_neg(&lightv);
	reflectv = reflect(&neg_lightv, &(comp_r->normalv));
	reflect_dot_eye = tuple_dot_product(&reflectv, &(comp_r->eyev));
	if (reflect_dot_eye <= 0)
		return (color(0, 0, 0));
	factor = pow(reflect_dot_eye, comp_r->object->material.shininess);
	return (multcolor((*light_r)->intensity,
			comp_r->object->material.specular * factor));
}

t_color	lighting(t_light *light, t_precomp *comp_r, int is_shadow)
{
	t_light_ctx	ctx;
	float		light_dot_normal;
	t_color		clr;

	ctx.effective_intensity = multcolor(light->intensity, light->brightness);
	if (comp_r->object->material.pattern.flag)
		clr = checker_at_object(comp_r->object, comp_r->point);
	else
		clr = comp_r->object->material.color;
	ctx.effective_color = hadamard(clr, ctx.effective_intensity);
	ctx.lightv = tuple_sub(&(light->position), &(comp_r->point));
	ctx.norm_lightv = tuple_norm(&ctx.lightv);
	ctx.ambient = multcolor(comp_r->object->material.ambient_color,
			comp_r->object->material.ambient_ratio);
	light_dot_normal = tuple_dot_product(&ctx.norm_lightv,
			&(comp_r->normalv));
	if (is_shadow || light_dot_normal < 0)
		return (ctx.ambient);
	ctx.diffuse = diffuse_cal(ctx.effective_color,
			comp_r->object->material.diffuse, ctx.norm_lightv, comp_r->normalv);
	ctx.specular = specular_cal(&light, comp_r, ctx.norm_lightv);
	return (addcolor(addcolor(ctx.ambient, ctx.diffuse), ctx.specular));
}
