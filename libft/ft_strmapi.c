/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 15:44:49 by hugsbord          #+#    #+#             */
/*   Updated: 2018/02/03 11:49:30 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len;
	unsigned int	counter;
	char			*new_str;

	if (!s)
		return (NULL);
	if (!f)
		return (ft_strdup(s));
	len = ft_strlen(s);
	new_str = ft_strnew(len);
	if (new_str == NULL)
		return (NULL);
	counter = 0;
	while (counter < len)
	{
		new_str[counter] = (*f)(counter, s[counter]);
		counter++;
	}
	return (new_str);
}
