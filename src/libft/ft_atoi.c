/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 19:51:50 by spalmer           #+#    #+#             */
/*   Updated: 2019/09/24 22:11:11 by spalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int		ft_atoi_dop(const char *str, int n, int minus)
{
	long int res;

	res = 0;
	while (*(str + n) != '\0')
	{
		if ((*(str + n) >= '0') && (*(str + n) <= '9'))
		{
			if ((*(str + n) - '0') + res * 10 < res)
			{
				if (minus == 1)
					return (-1);
				if (minus == -1)
					return (0);
			}
			res = (*(str + n) - '0') + res * 10;
			n++;
		}
		else
			break ;
	}
	return (res * minus);
}

int					ft_atoi(const char *str)
{
	int n;
	int minus;
	int check;

	check = 0;
	minus = 1;
	n = 0;
	while ((*(str + n) == '0') || (*(str + n) == '\t') ||
			(*(str + n) == '\v') || (*(str + n) == '\f') ||
			(*(str + n) == '\r') || (*(str + n) == '\n') ||
			(*(str + n) == ' ') || (*(str + n) == '+') || (*(str + n) == '-'))
	{
		if (*(str + n) == '-' || *(str + n) == '+')
		{
			if (*(str + n) == '-')
				minus = -1;
			check++;
			if (check > 1 || (*(str + n) == '-' && (*(str + n + 1) < '0' ||
							(*(str + n + 1) > '9'))))
				return (0);
		}
		n++;
	}
	return (ft_atoi_dop(str, n, minus));
}
