/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmer <spalmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 17:36:09 by spalmer           #+#    #+#             */
/*   Updated: 2020/01/13 18:44:36 by spalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "libft/get_next_line.h"

int		find_height(char *argv)
{
	int		cnt;
	char	*line;
	int		fd;

	cnt = 0;
	if ((fd = open(argv, O_RDONLY)) < 0)
	{
		ft_putstr("ERROR");
		return (0);
	}
	while (get_next_line(fd, &line) == 1)
	{
		cnt++;
		free(line);
	}
	close(fd);
	return (cnt);
}

int		ft_cnt_lines(char const *s, char c)
{
	int		i;
	int		cnt;

	i = 0;
	cnt = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			cnt++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		if (s[i] == '\0')
			break ;
		i++;
	}
	return (cnt);
}

int		find_length(char *argv)
{
	int		cnt;
	char	*line;
	int		fd;

	cnt = 0;
	fd = open(argv, O_RDONLY);
	get_next_line(fd, &line);
	cnt = ft_cnt_lines(line, ' ');
	free(line);
	close(fd);
	return (cnt);
}

int		char_to_int(int *int_line, char *line, int length)
{
	char	**temp;
	int		i;

	temp = ft_strsplit(line, ' ');
	i = 0;
	while (temp[i])
	{
		int_line[i] = ft_atoi(temp[i]);
		free(temp[i]);
		i++;
	}
	if (i != length)
		return (0);
	free(temp);
	return (1);
}
/*
void	clean_map(t_map *map)
{
    int i;

    i = 
	while(map->map[i])
	{
		while(map->map[i][j])
	}
}
*/
int		read_map(char *argv, t_map *map)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	if ((map->height = find_height(argv)) == 0) //del
		return (0);								//del
	map->length = find_length(argv);			//del
	fd = open(argv, O_RDONLY);
	if (!(map->map = (int**)malloc(sizeof(int*) * (map->height + 1))))
		return (0);
	while (i <= map->height)
		if (!(map->map[i++] = (int*)malloc(sizeof(int) * (map->length + 1))))
			{
				//clean_map(map);
				return (0);
			}
	i = 0;
	while (get_next_line(fd, &line))
	{
		if ((char_to_int(map->map[i++], line, map->length)) == 0)
			return (0);
		free(line);
	}
	map->map[i] = NULL;
	close(fd);
	return (1);
}
