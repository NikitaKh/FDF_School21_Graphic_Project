/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 16:49:02 by spalmer           #+#    #+#             */
/*   Updated: 2019/09/23 22:45:01 by spalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ss;
	int		len;
	int		i;

	if (s == NULL || f == NULL)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	ss = (char *)malloc(sizeof(char) * (len + 1));
	if (ss == NULL)
		return (NULL);
	while (i < len)
	{
		ss[i] = f(s[i]);
		i++;
	}
	ss[i] = '\0';
	return (ss);
}
