/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 17:18:08 by spalmer           #+#    #+#             */
/*   Updated: 2019/09/23 21:47:56 by spalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ss;

	i = 0;
	if (len + 1 == 0 || !s)
		return (NULL);
	if (!(ss = (char *)malloc(sizeof(*ss) * (len + 1))))
		return (NULL);
	else
	{
		while (i < len)
		{
			ss[i] = s[start + i];
			i++;
		}
		ss[i] = '\0';
	}
	return (ss);
}
