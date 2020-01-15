/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 19:59:47 by spalmer           #+#    #+#             */
/*   Updated: 2019/09/23 20:26:33 by spalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	const char		*ss;

	ss = (const char *)s;
	i = 0;
	if (s == NULL && n == 0)
		return (NULL);
	while (i < n)
	{
		if (((unsigned char *)ss)[i] == (unsigned char)c)
			return ((void *)ss + i);
		i++;
	}
	return (NULL);
}
