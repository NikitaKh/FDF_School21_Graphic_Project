/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoliath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 18:15:27 by spalmer           #+#    #+#             */
/*   Updated: 2020/01/14 17:50:26 by cgoliath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <math.h>

#define MOD(a) ((a < 0) ? -a : a)
#define MAX(a, b) (a > b ? a : b)


float	fmodule(float i)
{
	return (i < 0) ? -i : i;
}

void    rotate_x(float *y, float *z, t_map *map)
{
    float yy;
    float zz;

    yy = *y * cos(map->angle[0]) - *z * sin(map->angle[0]);
    zz = *y * sin(map->angle[0]) + *z * cos(map->angle[0]);
    *y = yy;
    *z = zz;
}

void    rotate_y(float *x, float *z, t_map *map)
{
    float xx;
    float zz;

    xx = *x * cos(map->angle[1]) + *z * sin(map->angle[1]);
    zz = -*x * sin(map->angle[1]) + *z * cos(map->angle[1]);
    *x = xx;
    *z = zz;
}

void    rotate_z(float *x, float *y, t_map *map)
{
    float xx;
    float yy;
    
    xx = *x * cos(map->angle[2]) - *y * sin(map->angle[2]);
    yy = *x * sin(map->angle[2]) + *y * cos(map->angle[2]);
    *x = xx;
    *y = yy;
}

void    scale(float *x, float *y, float *z, t_map *map)
{
    *x = *x*map->scale;
    *y = *y*map->scale; 
    *z = *z*map->scale/2;
}

void    move(float *x, float *y, t_map *map)
{
    *x = *x + map->move[0];
    *y = *y + map->move[1]; 
}

void    extrude(float *z1, float *z2, t_map *map)
{
    *z1 += map->ext;
    *z2 += map->ext;
}

void    alg_bres(float x1, float y1, float x2, float y2, t_map *map)
{
    float dx;
    float dy;
    int color;
    double tmp;
    int pixel;
    float x;
    float y;
    float z1;
    float z2;

    z1 = map->map[(int)y1][(int)x1]* map->ext;
    z2 = map->map[(int)y2][(int)x2]* map->ext;
    
    color = 0xffffff;
    if (z1 != 0 || z2 != 0)
        color = 0xffaaff;
        
    x1 -= map->length / 2;
    y1 -= map->height / 2;
    x2 -= map->length / 2;
    y2 -= map->height / 2;
    
    scale(&x1, &y1, &z1, map);
    scale(&x2, &y2, &z2, map);
    
    rotate_x(&y1, &z1, map);
    rotate_x(&y2, &z2, map);
    rotate_y(&x1, &z1, map);
    rotate_y(&x2, &z2, map);
    rotate_z(&x1, &y1, map);
    rotate_z(&x2, &y2, map);
    
    move(&x1, &y1, map);
    move(&x2, &y2, map);

    x1 += map->length / 2 * map->scale;
    y1 += map->height / 2 * map->scale;
    x2 += map->length / 2 * map->scale;
    y2 += map->height / 2 * map->scale;

    x1 += (WID / 2 - (map->length * map->scale) / 2);
    y1 += (HEI / 2 - (map->height * map->scale) / 2);
    x2 += (WID / 2 - (map->length * map->scale) / 2);
    y2 += (HEI / 2 - (map->height * map->scale) / 2);

    dx = abs((int)x2 - (int)x1);
    dy = abs((int)y2 - (int)y1);
 
    if (dx > dy)
        tmp = dx;
    else
        tmp = dy;

    pixel = (!round(tmp)) ? 1 : round(tmp);
 
    x = dx / tmp * (x1 < x2 ? 1 : -1);
    y = dy / tmp * (y1 < y2 ? 1 : -1);
    while (pixel--)
    {
        if ((x1 > map->length && x1 < 0) && (y1 > map->height && y1 < 0))
            pixel = 0;
        mlx_pixel_put(map->mlx_ptr, map->win_ptr, x1, y1, color);
        x1 += x;
        y1 += y;
    }
}

void    draw_matrix(t_map *map)
{
    float x;
    float y;

    x = 0;
    y = 0;
    while (y  < map->height)
    {
        x = 0;
        while (x < map->length)
        {
            if (x != map->length - 1)
                alg_bres(x, y, x + 1, y, map);
            if (y != map->height - 1)
                alg_bres(x, y, x, y + 1, map);
            x++;
        }
        y++;
    }
        menu(map);
}