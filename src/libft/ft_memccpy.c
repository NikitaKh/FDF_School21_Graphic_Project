/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 17:43:50 by spalmer           #+#    #+#             */
/*   Updated: 2019/09/23 21:28:12 by spalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c,
		size_t n)
{
	unsigned char			*a;
	unsigned const char		*b;
	size_t					i;
	unsigned char			x;

	a = (unsigned char *)dst;
	b = (unsigned char *)src;
	i = 0;
	x = (unsigned char)c;
	while (i < n)
	{
		if (*b == x)
		{
			*a = *b;
			a++;
			return (a);
		}
		*a = *b;
		a++;
		b++;
		i++;
	}
	return (NULL);
}
