
#ifndef RAYS_H
# define RAYS_H

#include "cube3d.h"

t_bool  rays_init(t_rays rays);
t_rays	ray_setup(double angle);
t_rays  *rays_tab_init();

#endif