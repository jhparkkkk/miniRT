/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_lighting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 16:39:13 by cgosseli          #+#    #+#             */
/*   Updated: 2022/10/17 16:36:17 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

// static void	specular_lighting(t_hit_point *hit, t_ray *ray)
// {
// 	hit->reflect = vec_scalar(hit->normal, 2.0);
// 	hit->reflect = vec_scalar(hit->reflect, vec_dot(hit->normal, vec_scalar(hit->vec_light, -1.0)));
// 	hit->reflect = vec_substract(hit->reflect, hit->vec_light);
// 	hit->reflect = vec_normalize(hit->reflect);
// 	hit->view = vec_scalar(ray->direction, -1.0);
// 	hit->r_dot_v = vec_dot(hit->reflect, hit->view);
// }

// static void	set_ray_to_light();

/* Calculates the intensity of light at the impact of *ray on the *sphere.
Returns the intensity. */
double	compute_lighting(t_ray *ray, t_object *sp, t_world *world)
{
	t_hit_point	hit;
	double intensity;
	
	intensity = 0.0;
	hit.point = vec_add(ray->origin, vec_scalar(ray->direction, ray->hit.root));
	hit.normal = vec_scalar(vec_substract(hit.point, sp->center), -1.0);
	// hit.normal = vec_normalize(hit.normal);
	hit.vec_light = vec_substract(hit.point, world->light.position);
	hit.n_dot_l = sqrt(vec_dot(hit.normal, hit.vec_light));
	//forcement sp_shadow et pas !sp_shadow sinon quand la light est loin et que donc il touche rien, 
	//ca eclaire pas donc pas cool.
	if (hit.n_dot_l > __DBL_EPSILON__ && sp_shadows(hit.point, hit.vec_light, world))
	{
		intensity += world->light.intensity * (hit.n_dot_l / (vec_len(hit.normal) * vec_len(hit.vec_light)));
		/* SPEC LIGHTNING */
		// if (sp->specular_exponent != -1.0)
		// {
		// 	specular_lighting(&hit, ray);
		// 	if (hit.r_dot_v > __DBL_EPSILON__) // si M_E bug et il faut remettre 0.0 puis M_E
		// 		intensity += world->light.intensity * (sp->k_spec * pow(hit.r_dot_v / (vec_len(hit.reflect) * vec_len(hit.view)), sp->specular_exponent * 5000.0));
		// 		// sp->specular_exponent = world->light.intensity * pow(hit.r_dot_v, sp->specular_exponent);
		// }
	}
	return (intensity);
}