/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 16:04:20 by spalmer           #+#    #+#             */
/*   Updated: 2019/09/22 18:40:18 by spalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t len1;
	size_t len2;
	size_t len;

	len1 = ft_strlen(dst);
	len2 = ft_strlen(src);
	len = 0;
	i = 0;
	if (dst == NULL || src == NULL)
		return (0);
	while (dst[len] && len < size)
		len++;
	if (len >= size)
		return (size + len2);
	while (src[i] && i < (size - len1 - 1))
	{
		dst[len + i] = ((char *)src)[i];
		i++;
	}
	dst[len + i] = '\0';
	return (len + len2);
}
