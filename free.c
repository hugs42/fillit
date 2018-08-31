/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 15:45:10 by hugsbord          #+#    #+#             */
/*   Updated: 2018/08/31 16:07:28 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_free_tab(char **tab, unsigned int size)
{
	unsigned int	n;

	n = 0;
	while (n < size)
		free(tab[n++]);
	free(tab);
}
