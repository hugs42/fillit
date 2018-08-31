/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 13:51:39 by hugsbord          #+#    #+#             */
/*   Updated: 2018/02/03 11:03:24 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_str_len(int n)
{
	size_t		i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char			*ft_itoa(int n)
{
	char			*str;
	size_t			len;
	unsigned int	n_tmp;

	len = ft_str_len(n);
	n_tmp = n;
	if (n < 0)
	{
		n_tmp = -n;
		len++;
	}
	if (!(str = ft_strnew(len)))
		return (NULL);
	str[--len] = n_tmp % 10 + '0';
	while (n_tmp /= 10)
		str[--len] = n_tmp % 10 + '0';
	if (n < 0)
		*(str + 0) = '-';
	return (str);
}
