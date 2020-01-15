/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoliath <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 19:53:49 by cgoliath          #+#    #+#             */
/*   Updated: 2019/10/05 19:46:54 by cgoliath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	int		ft_new_line(char **s, char **line, int fd)
{
	char	*tmp;
	int		len;

	len = 0;
	while (s[fd][len] != '\n' && s[fd][len] != '\0')
		len++;
	*line = ft_strsub(s[fd], 0, len);
	if (s[fd][len] == '\n')
		tmp = ft_strdup(s[fd] + len + 1);
	else
		tmp = ft_strdup(s[fd] + len);
	free(s[fd]);
	s[fd] = tmp;
	if (s[fd][0] == '\0')
		ft_strdel(&s[fd]);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char	*s[FD_MAX];
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	int			ret;

	if (fd < 0 || line == NULL || FD_MAX > 4864)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strnew(1);
		tmp = ft_strjoin(s[fd], buf);
		free(s[fd]);
		s[fd] = tmp;
		if (ft_strchr(s[fd], '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (s[fd] == NULL || s[fd][0] == '\0'))
		return (0);
	return (ft_new_line(s, line, fd));
}
