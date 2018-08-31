/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 13:32:54 by hugsbord          #+#    #+#             */
/*   Updated: 2018/08/31 12:55:30 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetriminos	*ft_init_tetriminos(void)
{
	static unsigned char	name = 'A';
	t_tetriminos			*tetriminos;

	if ((tetriminos = malloc(sizeof(t_tetriminos))) == NULL)
		return (NULL);
	tetriminos->name = name++;
	tetriminos->pos[0].x = 0;
	tetriminos->pos[0].y = 0;
	tetriminos->pos[1].x = 0;
	tetriminos->pos[1].y = 0;
	tetriminos->pos[2].x = 0;
	tetriminos->pos[2].y = 0;
	tetriminos->pos[3].x = 0;
	tetriminos->pos[3].y = 0;
	tetriminos->next = NULL;
	return (tetriminos);
}

void			ft_clear_tetriminos(t_tetriminos *tetriminos)
{
	if (tetriminos->next)
		ft_clear_tetriminos(tetriminos->next);
	free(tetriminos);
}

t_tetriminos	*ft_add_tetriminos(t_tetriminos *tetriminos)
{
	t_tetriminos	*tmp;

	tmp = tetriminos;
	while (tmp->next)
		tmp = tmp->next;
	if ((tmp->next = ft_init_tetriminos()) == NULL)
	{
		ft_clear_tetriminos(tetriminos);
		return (NULL);
	}
	return (tmp->next);
}
