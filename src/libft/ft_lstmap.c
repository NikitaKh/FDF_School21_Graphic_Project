/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 16:45:17 by spalmer           #+#    #+#             */
/*   Updated: 2019/09/29 16:54:42 by spalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ret;

	if (lst == NULL || f == NULL)
		return (NULL);
	ret = f(lst);
	if (ret == NULL)
		return (NULL);
	ret->next = ft_lstmap(lst->next, f);
	return (ret);
}
