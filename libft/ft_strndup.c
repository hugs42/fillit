/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 11:33:26 by hugsbord          #+#    #+#             */
/*   Updated: 2018/02/01 11:34:29 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char *tab;

	tab = (char *)malloc(sizeof(char) * n + 1);
	if (tab == NULL)
		return (NULL);
	tab = ft_strncpy(tab, s, n);
	tab[n] = '\0';
	return (tab);
}
