/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 18:54:10 by spalmer           #+#    #+#             */
/*   Updated: 2019/09/23 19:21:23 by spalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		ii;
	size_t	check;

	if (needle[0] == '\0')
		return ((char *)haystack);
	i = -1;
	check = 0;
	while (haystack[++i] != '\0')
	{
		if (haystack[i] == needle[0])
		{
			ii = 0;
			while (haystack[i + ii] == needle[ii] && needle[ii] &&
					haystack[i + ii++])
				check++;
			if (check == ft_strlen(needle))
				return (&((char *)haystack)[i]);
			else
				check = 0;
		}
	}
	return (0);
}
