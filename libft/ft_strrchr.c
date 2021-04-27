/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 15:12:14 by hugsbord          #+#    #+#             */
/*   Updated: 2018/02/02 14:58:04 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ptr;

	i = 1;
	while (s[i] != '\0')
		i++;
	while (1)
	{
		if (s[i] == c)
		{
			ptr = &((char *)s)[i];
			return (ptr);
		}
		if (!i)
			break ;
		i--;
	}
	return (NULL);
}
