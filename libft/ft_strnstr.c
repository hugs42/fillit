/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 17:28:01 by hugsbord          #+#    #+#             */
/*   Updated: 2018/02/02 14:55:50 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t n)
{
	unsigned int len_2;

	if (*find == '\0')
		return ((char *)str);
	len_2 = ft_strlen(find);
	while (*str != '\0' && n-- >= len_2)
	{
		if (*str == *find && ft_memcmp(str, find, len_2) == 0)
			return ((char *)str);
		str++;
	}
	return (NULL);
}
