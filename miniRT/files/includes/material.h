/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 12:16:20 by tde-cama          #+#    #+#             */
/*   Updated: 2021/04/14 10:06:33 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
# define MATERIAL_H

# include "numbers.h"
# include "ray.h"

typedef struct	s_hit_record
{
    t_point3		p;
    t_vec3		normal;
    double		t;
	struct s_material	*mat_ptr;
	bool		front_face;

}				t_hit_record;

typedef struct s_material{

        t_color albedo;
		double	fuzz;
		double	ir;
		bool	(*scatter)(t_ray, struct s_hit_record, t_color*, t_ray*);
	} t_material;

bool lambertian(t_ray r_in, struct s_hit_record rec, t_color *attenuation, t_ray *scattered);
bool metal(t_ray r_in, struct s_hit_record rec, t_color *attenuation, t_ray *scattered);
bool dielectric(t_ray r_in, struct s_hit_record rec, t_color *attenuation, t_ray *scattered);


t_material set_material(t_color c, double f, double i, bool (*scatter)(t_ray, struct s_hit_record, t_color*, t_ray*));


#endif
