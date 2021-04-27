/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimucchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 15:10:38 by vimucchi          #+#    #+#             */
/*   Updated: 2018/09/02 15:17:51 by vimucchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_algo_tool(t_tetriminos *tetri, t_map map, t_coord coord)
{
	if (map.tab[tetri->pos[0].y + coord.y][tetri->pos[0].x + coord.x]
		== '.' && map.tab[tetri->pos[1].y + coord.y][tetri->pos[1].x
		+ coord.x] == '.' && map.tab[tetri->pos[2].y + coord.y]
		[tetri->pos[2].x + coord.x] == '.' && map.tab[tetri->pos[3].y +
		coord.y][tetri->pos[3].x + coord.x] == '.')
	{
		return (TRUE);
	}
	return (FALSE);
}

void	ft_free_tab(char **tab, unsigned int size)
{
	unsigned int	n;

	n = 0;
	while (n < size)
		free(tab[n++]);
	free(tab);
}
