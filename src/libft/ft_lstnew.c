/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 14:16:27 by spalmer           #+#    #+#             */
/*   Updated: 2019/09/29 17:41:07 by spalmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;

	if (!(list = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	list->next = NULL;
	list->content = NULL;
	list->content_size = 0;
	if (content != NULL)
	{
		list->content = malloc(content_size);
		if (list->content == NULL)
		{
			ft_memdel((void *)list);
			return (NULL);
		}
		list->content_size = content_size;
		list->content = ft_memcpy(list->content, content, content_size);
	}
	return (list);
}
