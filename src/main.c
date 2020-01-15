/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmer <spalmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 18:05:55 by spalmer           #+#    #+#             */
/*   Updated: 2020/01/13 18:38:32 by spalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "libft/get_next_line.h"

int deal_key(int key, t_map *map)
{
    printf("%d\n", key);
    if(key == 53)
        exit(0);
    else if (key == 12)     //rotate
        map->angle[0] += 0.05;
    else if (key == 0)
        map->angle[0] -= 0.05;
    else if (key == 13)
        map->angle[1] += 0.05;
    else if (key == 1)
        map->angle[1] -= 0.05;
    else if (key == 14)
        map->angle[2] += 0.05;
    else if (key == 2)
        map->angle[2] -= 0.05;
    else if (key == 6 && map->scale > 0)      //scale
        map->scale -= 1;
    else if (key == 7 && map->scale < 100)
        map->scale += 1;
    else if (key == 126)        //move
        map->move[1] -= 3;
    else if (key == 125)
        map->move[1] += 3;
    else if (key == 123)
        map->move[0] -= 3;
    else if (key == 124)
        map->move[0] += 3;
    else if (key == 18 || key == 83)     //make top
    {
        map->scale = 50;
        map->angle[0] = 0;
        map->angle[1] = 0;
        map->angle[2] = 0;
    }
    else if (key == 19 || key == 84)      //make iso
    {
        map->angle[0] = 0.523599;
        map->angle[1] = 0.785398;
        map->angle[2] = -0.523599;
        map->scale = 50;
        map->move[0] = 0;
        map->move[1] = 0;
        map->ext = 0.1;
    }

    else if (key == 20 || key == 85)     //make dim
    {
        map->angle[0] = 1;
        map->angle[1] = 0.719948;
        map->angle[2] = -0.123918;
        map->scale = 50;
        map->move[0] = 0;
        map->move[1] = 0;
        map->ext = 0.1;       
    }
    else if (key == 24 || key == 69)     //extrude
        map->ext += 0.02;
    else if (key == 27 || key == 78)    
        map->ext -= 0.02;

    mlx_clear_window(map->mlx_ptr, map->win_ptr);
    draw_matrix(map);
    return (0);
}

int main(int argc, char **argv)
{
    t_map *map;
    int i;
    int j;

    i = 0;
    j = 0;
    if (argc > 2)
    {
        ft_putstr("ERROR");
        return (0);
    } 
    if (!(map = (t_map*)malloc(sizeof(t_map))))
        return (0);
    map->angle[0] = 0.523599;
    map->angle[1] = 0.785398;
    map->angle[2] = -0.523599;
    map->scale = 50;
    map->move[0] = 0;
    map->move[1] = 0;
    map->ext = 0.1;
    if (read_map(argv[1], map) == 0)
	{
        ft_putstr("ERROR");
        return (0);
	}
    map->mlx_ptr = mlx_init();
    map->win_ptr = mlx_new_window(map->mlx_ptr, WID, HEI, "FDF");
    draw_matrix(map);
    mlx_hook(map->win_ptr, 2, 0, deal_key, map);
    mlx_loop(map->mlx_ptr);
    return(0);
}