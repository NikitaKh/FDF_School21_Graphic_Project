/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 14:05:14 by spalmer           #+#    #+#             */
/*   Updated: 2019/09/21 15:43:12 by spalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	a;
	size_t			i;
	char			*ar;

	a = c;
	i = 0;
	ar = b;
	while (i < len)
	{
		ar[i] = a;
		i++;
	}
	return (ar);
}
