/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmer <spalmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 18:15:27 by spalmer           #+#    #+#             */
/*   Updated: 2020/01/07 14:45:55 by spalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "math.h"

#define  MOD(a) ((a < 0) ? -a : a)
#define MAX(a, b) (a > b ? a : b)


float	fmodule(float i)
{
	return (i < 0) ? -i : i;
}
/*
void    alg_bres(float x1, float y1, float x2, float y2, t_map *map)
{
	float	step_x;
	float	step_y;
	float	max;
	int		color;

	color = 0xffffff;
    if (map->map[(int)y1][(int)x1] != 0)
        color = 0xffaaff;
 
    float xx1 = x1;
    float yy1 = y1;
    float xx2 = x2;
    float yy2 = y2;
    x1 = xx1*cos(0.52) - yy1*sin(0.52);
    y1 = xx1*sin(0.52) + yy1*cos(0.52);
    x2 = xx2*cos(0.52) - yy2*sin(0.52);
    y2 = xx2*sin(0.52) + yy2*cos(0.52);

    x1 = x1*50;
    y1 = y1*50; 
    x2 = x2*50;
    y2 = y2*50;

    x1 +=450;
    y1 +=450;
    x2 +=450;
    y2 +=450;

step_x = x2 - x1;
	step_y = y2 - y1;
	max = MAX(fmodule(step_x), fmodule(step_y));
	step_x /= max;
	step_y /= max;

	while ((int)(x1 - x2) || (int)(y1 - y2))
	{
		mlx_pixel_put(map->mlx_ptr, map->win_ptr, x1, y1, color);
		x1 += step_x;
		y1 += step_y;
		if (y1 < 0 || x1 < 0)
			break ;
	}
}*/

void    alg_bres(float x1, float y1, float x2, float y2, t_map *map)
{
    float e;
    int dx;
    int dy;
    int color;
    int i = 0;
    int j = 0;

    color = 0xffffff;
    if (map->map[(int)y1][(int)x1] != 0)
        color = 0xffaaff;

    int xx1 = x1;
    int yy1 = y1;
    int xx2 = x2;
    int yy2 = y2;

    x1 = xx1*cos(0.52) - yy1*sin(0.52);
    y1 = xx1*sin(0.52) + yy1*cos(0.52);
    x2 = xx2*cos(0.52) - yy2*sin(0.52);
    y2 = xx2*sin(0.52) + yy2*cos(0.52);

    x1 = x1*50;
    y1 = y1*50; 
    x2 = x2*50;
    y2 = y2*50;

    x1 +=450;
    y1 +=450;
    x2 +=450;
    y2 +=450;

    dx = x2 - x1;
    dy = y2 - y1;
    dx = abs((int)dx);
    dy = abs((int)dy);
    e = dy/dx - 0.5;

    while ((int)x1 != (int)x2 && (int)y1 != (int)y2)
    {
        mlx_pixel_put(map->mlx_ptr, map->win_ptr, x1, y1, color);
        if (e >= 0.5)
        {
            y1++;;
            e = e - 1;
        }
        else if (e < 0.5)
        {
            x1++;
            e = e + (dy/dx);
            i++;
        }
    }
    
    while (i < dx && j < dy)
    {
        mlx_pixel_put(map->mlx_ptr, map->win_ptr, x1, y1, color);
        if (e >= 0.5)
        {
            y1++;;
            e = e - 1;
            j++;
        }
        else if (e < 0.5)
        {
            x1++;
            e = e + (dy/dx);
            i++;
        }
    }
}

/*
void    alg_bres(float x1, float y1, float x2, float y2, t_map *map)
{
    float e;
    int dx;
    int dy;
    int color;
    int i = 0;
    int j = 0;
 
    color = 0xffffff;
    if (map->map[(int)y1][(int)x1] != 0)
        color = 0xffaaff;

    float xx1 = x1;
    float yy1 = y1;
    float xx2 = x2;
    float yy2 = y2;


    x1 = xx1*cos(0.52) - yy1*sin(0.52);
    y1 = xx1*sin(0.52) + yy1*cos(0.52);
    x2 = xx2*cos(0.52) - yy2*sin(0.52);
    y2 = xx2*sin(0.52) + yy2*cos(0.52);

    x1 = x1*50;
    y1 = y1*50; 
    x2 = x2*50;
    y2 = y2*50;

    x1 +=450;
    y1 +=450;
    x2 +=450;
    y2 +=450;

    dx = x2 - x1;
    dy = y2 - y1;
    dx = abs(dx);
    dy = abs(dy);
    e = dy/dx -0.5;

    while (i <= dx && j <= dy)
    {
        mlx_pixel_put(map->mlx_ptr, map->win_ptr, x1, y1, color);
        if (e >= 0)
        {
            y1++;
            e++;
            j++;
        }
        else if (e < 0)
        {
            x1++;
            e = e + dy/dx;
            i++;
        }
    }
}


void    alg_bres(float x1, float y1, float x2, float y2, t_map *map)
{
    int a;
    int b;
    int color;
    int sign;
    int signa;
    int signb;
    int f = 0;

    color = 0xffffff;
    if (map->map[(int)y1][(int)x1] != 0)
        color = 0xffaaff;

    float xx1 = x1;
    float yy1 = y1;
    float xx2 = x2;
    float yy2 = y2;

    x1 = xx1*cos(0.52) - yy1*sin(0.52);
    y1 = xx1*sin(0.52) + yy1*cos(0.52);
    x2 = xx2*cos(0.52) - yy2*sin(0.52);
    y2 = xx2*sin(0.52) + yy2*cos(0.52);

    x1 = x1*50;
    y1 = y1*50; 
    x2 = x2*50;
    y2 = y2*50;

    x1 +=450;
    y1 +=450;
    x2 +=450;
    y2 +=450;

    b = x2 - x1;
    a = y2 - y1;

    sign = (abs(a) >= abs(b) ? 1 : -1);
    signa = (a < 0 ? -1: 1);
    signb = (b < 0 ? -1: 1);


    int x = x1;
    int y = y1;

    mlx_pixel_put(map->mlx_ptr, map->win_ptr, x1, y1, color);

    if (sign == -1)
    {
        while(x != x1 || y != y1)
        {
            f += a * signa;
            if (f > 0)
            {
                f -= b * signb;
                y += signa;
            }   
            x -= signb;
            mlx_pixel_put(map->mlx_ptr, map->win_ptr, x, y, color);
        }
    }
    else
    {
        while(x != x1 || y != y1)
        {
            f += b * signb;
            if (f > 0)
            {
                f -= a * signa;
                x -= signb;
            }
            y += signa;
            mlx_pixel_put(map->mlx_ptr, map->win_ptr, x, y, color);
        }
    }
    
    
}
*/
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
            //printf("%f, %f\n", x, y);
        }
        y++;
    }
}