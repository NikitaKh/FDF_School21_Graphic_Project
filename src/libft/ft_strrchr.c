/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:13:19 by spalmer           #+#    #+#             */
/*   Updated: 2019/09/23 20:51:05 by spalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	x;

	i = ft_strlen(s);
	x = (char)c;
	while (i >= 0)
	{
		if (*(s + i) == x)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}
