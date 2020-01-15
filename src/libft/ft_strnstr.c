/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 19:15:38 by spalmer           #+#    #+#             */
/*   Updated: 2019/09/23 19:34:21 by spalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	ii;
	size_t	check;

	if (needle[0] == '\0')
		return ((char *)haystack);
	i = 0;
	while (i < len && haystack[i] != '\0')
	{
		check = 0;
		if (haystack[i] == needle[0])
		{
			ii = 0;
			while (haystack[i + ii] == needle[ii] && needle[ii] &&
				haystack[i + ii] && (i + ii) < len)
			{
				check++;
				ii++;
			}
			if (check == ft_strlen(needle))
				return (&((char *)haystack)[i]);
		}
		i++;
	}
	return (0);
}
