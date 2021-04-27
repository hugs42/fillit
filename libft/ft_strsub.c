/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 15:39:55 by hugsbord          #+#    #+#             */
/*   Updated: 2018/01/23 15:42:21 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*str;
	unsigned int	end;

	i = 0;
	end = start + len;
	if (!s)
		return (NULL);
	else if ((str = (char *)malloc(len + 1)) && end != 0)
	{
		while (start < end)
			str[i++] = s[start++];
		str[i] = '\0';
	}
	return (str);
}
