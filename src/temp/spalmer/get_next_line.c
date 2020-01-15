/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 19:08:58 by spalmer           #+#    #+#             */
/*   Updated: 2019/10/23 18:35:50 by spalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	full_line(char **line, char **ar, int fd)
{
	int		cnt;
	char	*del;

	del = NULL;
	cnt = 0;
	while (ar[fd][cnt] != '\n' && ar[fd][cnt] != '\0')
		cnt++;
	*line = ft_strsub(ar[fd], 0, cnt);
	if (ar[fd][cnt] != '\0')
		del = ft_strdup(&ar[fd][cnt + 1]);
	free(ar[fd]);
	ar[fd] = del;
	return (1);
}

int	check_temp(char *temp)
{
	int i;

	i = 0;
	while (temp[i] != '\0')
	{
		if (temp[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	get_next_line(const int fd, char **line)
{
	static char	*ar[OPEN_MAX];
	int			ret;
	char		temp[BUFF_SIZE + 1];
	char		*temp_temp;

	while ((ret = read(fd, temp, BUFF_SIZE)) > 0)
	{
		temp[ret] = '\0';
		if (ar[fd])
		{
			temp_temp = ft_strdup(ar[fd]);
			free(ar[fd]);
			ar[fd] = ft_strjoin(temp_temp, temp);
			free(temp_temp);
		}
		else
			ar[fd] = ft_strdup(temp);
		if (check_temp(temp) == 1)
			break ;
	}
	if (ret < 0 || !line || fd < 0 || fd > OPEN_MAX)
		return (-1);
	if ((ar[fd] == NULL || ar[fd][0] == '\0') && ret == 0)
		return (0);
	return (full_line(line, ar, fd));
}
