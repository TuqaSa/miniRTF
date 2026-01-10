/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:39:43 by rsrour            #+#    #+#             */
/*   Updated: 2025/12/09 21:06:46 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"
#include "libft.h"

t_shape	*init_shape(void)
{
	static int	next_id = 1;
	t_shape		*new;

	new = ft_calloc(1, sizeof(t_shape));
	if (!new)
		return (NULL);
	new->id = next_id++;
	new->transform = matrix4_identity();
	new->transform_inv = matrix4_identity();
	new->transpose_inv = matrix4_identity();
	new->inv_computed = 1;
	new->material = material();
	new->next = NULL;
	return (new);
}

t_material	material(void)
{
	t_material	mat;

	mat.color = color(1, 1, 1);
	mat.ambient_ratio = 0.9;
	mat.ambient_color = color(0.05, 0.05, 0.05);
	mat.diffuse = 0.9;
	mat.specular = 0.0f;
	mat.shininess = 10;
	mat.pattern = checkers_pattern(color(255, 255, 255),
			color(110, 10, 120), 0);
	return (mat);
}

void	set_transform(t_shape *shape, t_matrix4 transform)
{
	shape->transform = transform;
	shape->transform_inv = init_mat4();
	inverse_mat(&shape->transform, &shape->transform_inv);
	shape->inv_computed = 1;
	shape->transpose_inv = matrix4_transpose(shape->transform_inv);
}

void	del_shape(t_shape *shape)
{
	if (!shape)
		return ;
	free(shape->data);
	free(shape);
}

void	del_shapes(t_shape **root_r)
{
	t_shape	*curr;
	t_shape	*next;

	if (!root_r || !*root_r)
		return ;
	curr = *root_r;
	while (curr)
	{
		next = curr->next;
		del_shape(curr);
		curr = next;
	}
	*root_r = NULL;
	root_r = NULL;
}
