
#include "../../includes/cube3d.h"

t_rays	ray_setup(double angle)
{
	t_rays	ray;
	double	radian_a;

	radian_a = degrees_to_radian(angle);
	rays_init(ray);
	ray.x = -sin(radian_a);
	ray.y = cos(radian_a);
	return (ray);
}