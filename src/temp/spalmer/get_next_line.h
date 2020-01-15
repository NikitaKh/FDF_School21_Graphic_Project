/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmer <spalmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 18:01:40 by spalmer           #+#    #+#             */
/*   Updated: 2020/01/10 20:42:52 by spalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 50

# include <stdlib.h>
# include <limits.h>
# include "libft.h"

int get_next_line(const int fd, char **line);
int full_line(char **line, char **ar, int fd);
int check_temp(char *temp);

#endif
