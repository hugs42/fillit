/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 14:26:04 by hugsbord          #+#    #+#             */
/*   Updated: 2018/01/30 11:32:45 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** FT_MEMCMP 000000000000000000000000000000000000000000000000000000000000000000
**
**            compare les n premiers octets des zones mémoire s1 et s2. Elle
**            renvoie un entier inférieur, égal, ou supérieur à zéro, si s1 est
**           respectivement inférieure, égale ou supérieur à s2
**
**
**00000000000000000000000000000000000000000000000000000000000000000000000000000
*/

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*str1;
	char	*str2;
	size_t	i;

	i = 0;
	str1 = (char *)s1;
	str2 = (char *)s2;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	return (0);
}
