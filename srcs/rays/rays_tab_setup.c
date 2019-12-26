
#include "../../includes/cube3d.h"

t_rays  *rays_tab_init()
{
    t_rays  *rays_tab;
    int     i;

    i = 0;
    if(!(rays_tab = malloc(WIN_WIDTH * sizeof(t_vect))))
        return (0);
    rays_tab[i] = ray_setup((-(FOV_DEG/2)));
    i++;
    while (i < WIN_WIDTH)
    {
        rays_tab[i] = ray_setup((i - WIN_WIDTH * 0.5) * FOV_DEG / WIN_WIDTH);
        i++;
    }
    return (rays_tab);
}