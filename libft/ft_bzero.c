/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 13:49:28 by hugsbord          #+#    #+#             */
/*   Updated: 2018/01/29 10:22:52 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	bzero met a 0 (octets contnant '\0') les n premiers octets du bloc
**	pointe par s
**
**	En faisant un appel a la fonction memset
**
**00000000000000000000000000000000000000000000000000000000000000000000000000000
*/

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
