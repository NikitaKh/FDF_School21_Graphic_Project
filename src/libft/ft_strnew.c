/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 15:28:02 by spalmer           #+#    #+#             */
/*   Updated: 2019/09/19 22:12:23 by spalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *str;

	str = NULL;
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str)
	{
		ft_memset(str, '\0', size + 1);
		return (str);
	}
	return (NULL);
}
