/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 09:28:07 by hugsbord          #+#    #+#             */
/*   Updated: 2018/01/31 19:04:05 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*my_list;
	void		*cpy;

	my_list = (t_list *)ft_memalloc(sizeof(t_list));
	if (!my_list)
		return (NULL);
	if (content == NULL)
	{
		my_list->content = NULL;
		my_list->content_size = 0;
	}
	else
	{
		cpy = ft_memalloc(content_size);
		if (!cpy)
			return (NULL);
		my_list->content = ft_memcpy(cpy, content, content_size);
		my_list->content_size = content_size;
	}
	my_list->next = NULL;
	return (my_list);
}
