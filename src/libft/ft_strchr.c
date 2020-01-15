/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 16:49:49 by spalmer           #+#    #+#             */
/*   Updated: 2019/09/21 19:59:50 by spalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	x;

	i = 0;
	x = (char)c;
	while (*(s + i) != '\0')
	{
		if (*(s + i) == x)
			return ((char *)s + i);
		i++;
	}
	if (x == '\0')
		return ((char *)s + i);
	return (NULL);
}
