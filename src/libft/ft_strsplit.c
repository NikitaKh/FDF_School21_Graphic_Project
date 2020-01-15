/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 18:29:10 by spalmer           #+#    #+#             */
/*   Updated: 2019/10/13 18:53:52 by spalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_cnt_lines(char const *s, char c)
{
	int		i;
	size_t	cnt;

	i = 0;
	cnt = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			cnt++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		if (s[i] == '\0')
			break ;
		i++;
	}
	return (cnt);
}

static size_t	ft_len_word(char const *s, size_t i, char c)
{
	size_t cnt;

	cnt = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		cnt++;
	}
	return (cnt);
}

static char		*ft_full_str(size_t *i, const char *s, char c)
{
	char	*strr;
	int		jj;

	jj = 0;
	if (!(strr = (char *)malloc(sizeof(char) * ((ft_len_word(s, *i, c) + 1)))))
		return (NULL);
	while (s[*i] != c && s[*i])
	{
		strr[jj] = s[*i];
		jj++;
		*i += 1;
	}
	strr[jj] = '\0';
	return (strr);
}

static void		ft_clean_double_ar(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	ii;
	char	**str;

	if (s == NULL)
		return (NULL);
	i = 0;
	ii = 0;
	if (!(str = (char **)malloc(sizeof(char*) * (ft_cnt_lines(s, c) + 1))))
		return (NULL);
	while (ii < ft_cnt_lines(s, c) && s[i])
	{
		while (s[i] == c && s[i])
			i++;
		str[ii] = ft_full_str(&i, s, c);
		if (str[ii] == NULL)
			ft_clean_double_ar(str);
		ii++;
	}
	str[ii] = NULL;
	return (str);
}
