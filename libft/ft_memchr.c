/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 14:23:08 by hugsbord          #+#    #+#             */
/*   Updated: 2018/01/30 11:33:00 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** FT_MEMCCPY 000000000000000000000000000000000000000000000000000000000000000000
**
**             Examine les n premiers octets de la zone mémoire pointée
**             par s à la recherche du caractère c. Le premier octet
**             correspondant à c arrête l'opération.
**
**00000000000000000000000000000000000000000000000000000000000000000000000000000
*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char		*str;
	size_t		i;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		if ((unsigned char)str[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}
