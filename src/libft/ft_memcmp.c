/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 20:30:29 by spalmer           #+#    #+#             */
/*   Updated: 2019/09/23 20:33:36 by spalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*ss1;
	const char	*ss2;
	size_t		i;

	i = 0;
	ss1 = (const char *)s1;
	ss2 = (const char *)s2;
	while (i < n)
	{
		if (ss1[i] != ss2[i])
			return ((unsigned char)ss1[i] - (unsigned char)ss2[i]);
		i++;
	}
	return (0);
}
