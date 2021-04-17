/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-cama <tde-cama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 10:46:33 by tde-cama          #+#    #+#             */
/*   Updated: 2021/04/17 00:05:23 by tde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "material.h"

bool lambertian(t_ray r_in, struct s_hit_record rec, t_color *attenuation, t_ray *scattered)
{
	t_vec3 scatter_direction = vec_add(rec.normal, random_unit_vector());
	if (near_zero(scatter_direction))
        scatter_direction = rec.normal;
	*scattered = cast_ray(rec.p, scatter_direction);
	*attenuation = rec.mat_ptr->albedo;
	r_in = *scattered;
	return true;
}

bool metal(t_ray r_in, struct s_hit_record rec, t_color *attenuation, t_ray *scattered)
{
	t_vec3 reflected = reflect(unit_vector(r_in.dir), rec.normal);
	*scattered = cast_ray(rec.p, vec_add(reflected, vec_multiply(rec.mat_ptr->fuzz, random_in_unit_sphere())));
	*attenuation = rec.mat_ptr->albedo;
	return (dot(scattered->dir, rec.normal) > 0);
}

static double reflectance(double cosine, double ref_idx)
{
    double r0 = (1 - ref_idx) / (1 + ref_idx);
    r0 = r0 * r0;
    return (r0 + (1 - r0) * pow((1 - cosine),5));
}

bool dielectric(t_ray r_in, struct s_hit_record rec, t_color *attenuation, t_ray *scattered)
{
	*attenuation = init_vec(1, 1, 1);
	double refraction_ratio;

	if (rec.front_face)
	 	refraction_ratio = (1.0 / rec.mat_ptr->ir);
	else
		refraction_ratio = rec.mat_ptr->ir;
	t_vec3 unit_direction = unit_vector(r_in.dir);
	double cos_theta = fmin(dot(vec_multiply(-1,unit_direction), rec.normal), 1.0);
	double sin_theta = sqrt(1.0 - (cos_theta * cos_theta));
	bool cannot_refract = refraction_ratio * sin_theta > 1.0;
	t_vec3 direction;
	if (cannot_refract || reflectance(cos_theta, refraction_ratio) > random_double())
	 	direction = reflect(unit_direction, rec.normal);
	else
		direction = refract(unit_direction, rec.normal, refraction_ratio);
	*scattered = cast_ray(rec.p, direction);
	return (true);
}



t_material set_material(t_color c, double f,double i, bool (*scatter)(t_ray, struct s_hit_record, t_color*, t_ray*))
{
	if (f > 1.0)
		f = 1;
	t_material m;
	m.albedo = c;
	m.fuzz = f;
	m.ir = i;
	m.scatter = scatter;
	return (m);
}
