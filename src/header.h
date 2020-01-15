/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoliath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 17:35:44 by spalmer           #+#    #+#             */
/*   Updated: 2020/01/14 17:49:48 by cgoliath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <stdlib.h>
//# include <mlx.h>
# include <fcntl.h>
# include "libft/get_next_line.h"
# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# define WID 1500
# define HEI 1300
typedef struct s_map
{
    int length;
    int height;
    int **map;
    float angle[3];
    int scale;
    float move[2];
    float ext;
    
    void    *mlx_ptr;
    void    *win_ptr;

}               t_map;

void    alg_bres(float x1, float y1, float x2, float y2, t_map *map);
void    draw_matrix(t_map *map);
void    menu(t_map *map);
int    read_map(char *argv, t_map *map);
int deal_key(int key, t_map *map);
int    char_to_int(int *z_line, char *line, int length);
int find_length(char *argv);
int	ft_cnt_lines(char const *s, char c);
int find_height(char *argv);

#endif
