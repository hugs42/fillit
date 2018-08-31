/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 13:54:36 by hugsbord          #+#    #+#             */
/*   Updated: 2018/04/03 15:02:40 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *find)
{
	unsigned int	i;
	unsigned int	len_find;
	const char		*p;

	i = -1;
	p = str;
	if (ft_strlen(find) == 0)
		return ((char *)p);
	else if (ft_strlen(p) < ft_strlen(find))
		return (NULL);
	len_find = ft_strlen(find);
	while (p[++i + len_find - 1])
		if (ft_memcmp(p + i, find, len_find) == 0)
			return ((char *)p + i);
	return (NULL);
}
