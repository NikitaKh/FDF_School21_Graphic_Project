/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dops.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoliath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 15:51:26 by spalmer           #+#    #+#             */
/*   Updated: 2020/01/14 17:47:47 by cgoliath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void    menu(t_map *map)
{
    mlx_string_put(map->mlx_ptr, map->win_ptr, 10, 990, 0xffaaff, "MENU FOR GREAT FDF");
    mlx_string_put(map->mlx_ptr, map->win_ptr, 10, 1020, 0xffffff, "Rotate X - press Q/A");
    mlx_string_put(map->mlx_ptr, map->win_ptr, 10, 1040, 0xffffff, "Rotate Y - press W/S");
    mlx_string_put(map->mlx_ptr, map->win_ptr, 10, 1060, 0xffffff, "Rotate Z - press E/D");
    mlx_string_put(map->mlx_ptr, map->win_ptr, 10, 1080, 0xffffff, "Zoom - press Z/X");
    mlx_string_put(map->mlx_ptr, map->win_ptr, 10, 1100, 0xffffff, "Move - press up/down/left/right");
    mlx_string_put(map->mlx_ptr, map->win_ptr, 10, 1120, 0xffffff, "Extrude Z - press -/+");
    mlx_string_put(map->mlx_ptr, map->win_ptr, 10, 1150, 0xffffff, "TOP - press 1");
    mlx_string_put(map->mlx_ptr, map->win_ptr, 10, 1170, 0xffffff, "ISOMETRIC - press 2");
    mlx_string_put(map->mlx_ptr, map->win_ptr, 10, 1190, 0xffffff, "DIMETRIC - press 3");
    }