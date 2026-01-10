/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsrour <rsrour@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:36:32 by rsrour            #+#    #+#             */
/*   Updated: 2025/12/07 16:01:53 by rsrour           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

typedef struct s_color
{
	float	r;
	float	g;
	float	b;
}	t_color;

void	color_info(t_color *color_r);
t_color	color(float r, float g, float b);
t_color	multcolor(t_color a, float b);
t_color	addcolor(t_color a, t_color b);
t_color	subcolor(t_color a, t_color b);
t_color	hadamard(t_color a, t_color b);

#endif
