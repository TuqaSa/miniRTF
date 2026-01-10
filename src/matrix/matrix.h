/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:37:51 by rsrour            #+#    #+#             */
/*   Updated: 2025/12/10 09:49:59 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include <MLX42/MLX42.h>

# ifndef EPSILON
#  define EPSILON 1e-6f
# endif

typedef struct s_tuple
{
	float		x;
	float		y;
	float		z;
	float		w;
}				t_tuple;

typedef struct s_mat
{
	float	(*det)(void *self);
	void	(*info)(void *self);
	void	(*inverse)(void *self, void *inv_mat);
	float	(*minor)(void *self, void *sub_mat, int row, int col);
	void	(*sub_mat)(void *self, void *sub_mat, int row, int col);
	float	(*cofactor)(void *self, void *sub_mat, int row, int col);
	int		is_invertable;
	float	det_value;
}				t_mat;

typedef struct s_mat4
{
	t_mat	mat;
	float	m[4][4];
}				t_matrix4;

typedef struct s_mat3
{
	t_mat	mat;
	float	m[3][3];
}				t_matrix3;

typedef struct s_mat2
{
	t_mat	mat;
	float	m[2][2];
}				t_matrix2;

typedef struct s_shear
{
	float	xy;
	float	xz;
	float	yx;
	float	yz;
	float	zx;
	float	zy;
}				t_shear;

void		tuple_neg_set(t_tuple *tup);
void		tuple_scale_set(t_tuple *t, float sc);
void		tuple_sub_set(t_tuple *t1, t_tuple t2);
void		tuple_add_set(t_tuple *t1, t_tuple *t2);
void		tuple_norm_set(t_tuple *t_r);

t_tuple		tuple_norm(t_tuple *t_r); //normalize a vector
t_tuple		tuple_neg(t_tuple *tup_r);
t_tuple		tuple_scale(t_tuple *t_r, float sc);
t_tuple		tuple_sub(t_tuple *t1_r, t_tuple *t2_r);
t_tuple		tuple_add(t_tuple *t1_r, t_tuple *t2_r);
t_tuple		reflect(t_tuple *incident_r, t_tuple *normal_r);

float		tuple_magnitude(t_tuple *t_r);
t_tuple		point(float x, float y, float z);
t_tuple		vector(float x, float y, float z);

float		tuple_dot_product(t_tuple *t1_r, t_tuple *t2_r);
t_tuple		mat4_multi_tuple(t_matrix4 m, t_tuple tup);
int			tuple_cross_product(t_tuple *r_res, t_tuple t1, t_tuple t2);
void		mat4_multiplication(t_matrix4 *res, t_matrix4 m1, t_matrix4 m2);

t_matrix4	init_mat4(void);
t_matrix4	matrix4_identity(void);
t_matrix3	init_mat3(void);
t_matrix2	init_mat2(void);

int			mat_isinvertable(void *mat);
int32_t		mat4_equality(t_matrix4 *r_m1, t_matrix4 *r_m2);
t_matrix4	matrix4_transpose(t_matrix4 matrix);

float		mat2_det(void *self);
float		mat3_det(void *self);
float		mat4_det(void *self);
float		mat_det(void *_base_mat);

void		mat4_submat(void *self, void *sub_mat, int row, int col);
void		mat3_submat(void *self, void *sub_mat, int row, int col);
void		ft_sub_mat(void *_base_mat, void *sub_mat, int row, int col);

float		mat3_minor(void *self, void *sub_mat, int row, int col);
float		mat4_minor(void *self, void *sub_mat, int row, int col);
float		mat_minor(void *_base_mat, void *sub_mat, int row, int col);

float		mat3_cofactor(void *self, void *sub_mat, int row, int col);
float		mat4_cofactor(void *self, void *sub_mat, int row, int col);
float		mat_cofactor(void *_base_mat, void *sub_mat, int row, int col);

void		inverse_mat(void *base_mat, void *inv_mat);
void		mat4_inverse(void *self, void *inv_mat);

t_matrix4	translation(float x, float y, float z);
t_matrix4	scaling(float x, float y, float z);
t_matrix4	rotation_x(float radians);
t_matrix4	rotation_y(float radians);
t_matrix4	rotation_z(float radians);
t_matrix4	shearing(t_shear params);

void		tuple_info(t_tuple *t_r);
void		mat_info(void *_base_mat);
void		mat4_info(void *self);
void		mat3_info(void *self);
void		mat2_info(void *self);

t_matrix4	view_transform(t_tuple originalp, t_tuple top, t_tuple upv);

// math.c
float		ft_abs(float a);
int			ft_float_equal(float a, float b);
void		swap(float *a, float *b);

#endif
