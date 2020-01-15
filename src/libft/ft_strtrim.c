/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 17:25:37 by spalmer           #+#    #+#             */
/*   Updated: 2019/09/24 21:23:10 by spalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_first_whitespaces(char const *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != ' ' && s[i] != '\n' && s[i] != '\t')
			return (i);
		i++;
	}
	return (0);
}

static size_t	ft_last_whitespaces(char const *s)
{
	int len;

	len = ft_strlen(s);
	while ((len - 1) > 0)
	{
		if (s[len - 1] != ' ' && s[len - 1] != '\n' && s[len - 1] != '\t')
			return (len - 1);
		len--;
	}
	return (0);
}

char			*ft_strtrim(char const *s)
{
	int		i;
	int		len2;
	char	*str;
	size_t	first;
	size_t	last;

	if (s == NULL)
		return (NULL);
	first = ft_first_whitespaces(s);
	last = ft_last_whitespaces(s);
	len2 = last - first + 1;
	if (first == 0 && last == 0)
		len2 = 0;
	if (!(str = (char *)malloc(sizeof(*str) * (len2 + 1))))
		return (NULL);
	i = 0;
	while (i < len2)
		str[i++] = s[first++];
	str[i] = '\0';
	return (str);
}
