/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_lighting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgosseli <cgosseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 16:39:13 by cgosseli          #+#    #+#             */
/*   Updated: 2022/10/18 15:23:35 by cgosseli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static void	specular_lighting(t_hit_point *hit, t_ray *ray)
{
	hit->reflect = vec_scalar(hit->normal, 2.0);
	hit->reflect = vec_scalar(hit->reflect, vec_dot(hit->normal, vec_scalar(hit->vec_light, 1.0)));
	hit->reflect = vec_substract(hit->reflect, hit->vec_light);
	hit->view = vec_scalar(ray->direction, -1.0);
	hit->r_dot_v = sqrt(vec_dot(hit->reflect, hit->view));
}


/* Calculates the intensity of light at the impact of *ray on the *sphere.
Returns the intensity. */
double	compute_lighting(t_ray *ray, t_object *obj, t_world *world)
{
	t_hit_point	hit;
	double intensity;
	double	k_type;
	
	intensity = 0.0;
	hit.point = vec_add(ray->origin, vec_scalar(ray->direction, ray->hit.root));
	if (obj->type == PLANE)
	{
		hit.normal = obj->direction;
		k_type = 10.0;
	}
	else if (obj->type == SPHERE)
	{
		hit.normal = vec_substract(obj->center, hit.point);
		k_type = 1.0;
	}
	hit.vec_light = vec_substract(hit.point, world->light.position);
	hit.n_dot_l = sqrt(vec_dot(hit.normal, hit.vec_light));
	//On ne normalise pas la normal car sinon ca veut rien de faire ndotl qui est la longueur
	if (hit.n_dot_l > __DBL_EPSILON__ && sp_shadows(hit.point, hit.vec_light, world))
	{
		intensity += world->light.intensity * (hit.n_dot_l / (vec_len(hit.normal) * vec_len(hit.vec_light)));
		intensity /= k_type;
		/* SPEC LIGHTNING */
		if (obj->specular_exponent != -1.0)
		{
			specular_lighting(&hit, ray);
			if (hit.r_dot_v > __DBL_EPSILON__) // si M_E bug et il faut remettre 0.0 puis M_E
			{	
				intensity += world->light.intensity * (obj->k_spec * pow(hit.r_dot_v / (vec_len(hit.reflect) * vec_len(hit.view)), obj->specular_exponent * 500000.0));
				intensity /= k_type;
			}
				// obj->specular_exponent = world->light.intensity * pow(hit.r_dot_v, obj->specular_exponent);
		}
	}
	return (intensity);
}