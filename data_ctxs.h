/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_ctxs.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:14:59 by rsrour            #+#    #+#             */
/*   Updated: 2025/12/07 23:19:43 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_CTXS_H
# define DATA_CTXS_H

# include "color.h"
# include "matrix.h"
# include "minirt.h"

typedef struct s_vallinectx
{
	size_t			i;
	char			*id;
	int				j;
}				t_vallinectx;

typedef struct s_linectx
{
	int		fd;
	int		status;
	char	*line;
}				t_linectx;

typedef struct s_submat4_ctx
{
	t_matrix4		*mat;
	t_matrix3		*submat;
	int				i;
	int				j;
	int				k;
	int				l;
}					t_submat4_ctx;

typedef struct s_submat3_ctx
{
	t_matrix3		*mat;
	t_matrix2		*submat;
	int				i;
	int				j;
	int				k;
	int				l;
}					t_submat3_ctx;

typedef struct s_hyperboloid_parse_ctx
{
	t_tuple			position;
	float			radius;
	float			minimum;
	float			maximum;
	t_color			clr;
	int				i;
}					t_hypbparsectx;

typedef struct s_cylt_ctx
{
	float			t[2];
	float			y[2];
	int				i;
	int				count;
	t_cylinder		*cyl;
}					t_cylt_ctx;

typedef struct s_sphparse_ctx
{
	int				i;
	t_tuple			position;
	float			diameter;
	t_color			clr;
}					t_sphparse_ctx;

typedef struct s_cyl_orint
{
	t_matrix4		result;
	t_tuple			upv;
	t_tuple			rightv;
	t_tuple			forwardv;
	t_tuple			tmpv;
	float			dotproduct;
	t_tuple			projection;
}					t_cyl_orint;

typedef struct s_light_ctx
{
	t_color			effective_color;
	t_color			effective_intensity;
	t_tuple			lightv;
	t_color			ambient;
	t_color			diffuse;
	t_color			specular;
	t_tuple			norm_lightv;
}					t_light_ctx;

typedef struct s_atofctx
{
	int				i;
	int				flt;
	int				dig_ind;
	int				sign;
}					t_atofctx;

typedef struct s_rayctx
{
	float			xoffset;
	float			yoffset;
	float			world_x;
	float			world_y;
	t_tuple			pixel;
	t_tuple			origin;
	t_tuple			direction;
}					t_rayctx;

typedef struct s_cylparsectx
{
	t_tuple			position;
	t_tuple			orientationv;
	float			diameter;
	float			height;
	t_color			clr;
	int				i;
}					t_cylparsectx;

typedef struct s_shadowctx
{
	t_tuple			v;
	float			distance;
	t_tuple			direction;
	t_ray			ray;
	t_intersections	txs;
	t_intersection	hitx;
	t_tuple			tmp;
	t_tuple			offset_point;
}					t_shadowctx;

typedef struct s_planeparsectx
{
	int				i;
	t_color			clr;
	t_tuple			normalv;
	t_tuple			point_coord;
}					t_planeparsectx;

typedef struct s_bonusparsectx
{
	float			specular;
	int				checker_flag;
	t_color			checker_c1;
	t_color			checker_c2;
}					t_bonusparsectx;

t_cylparsectx		ft_initcylctx(char **id_r, int *ct_r);

#endif