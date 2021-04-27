/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 14:34:18 by hugsbord          #+#    #+#             */
/*   Updated: 2018/02/02 15:08:55 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		max_len;
	size_t		dst_len;
	size_t		i;
	size_t		j;

	dst_len = ft_strlen(dst);
	j = dst_len + ft_strlen(src);
	i = 0;
	max_len = size - dst_len - 1;
	while (size > dst_len + 1 && src[i])
	{
		dst[dst_len++] = src[i++];
		max_len--;
	}
	dst[dst_len] = '\0';
	if (size < j - ft_strlen(src))
		return (size + ft_strlen(src));
	else
		return (j);
	return (0);
}
