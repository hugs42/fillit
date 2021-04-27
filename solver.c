/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 13:41:06 by hugsbord          #+#    #+#             */
/*   Updated: 2018/09/01 18:59:42 by vimucchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static unsigned int		ft_algo_get_size(unsigned int nbr)
{
	unsigned int	size;

	size = 2;
	while (size * size < nbr)
		size += 1;
	return (size);
}

static char				ft_algo_set_map(unsigned int size, t_map *map)
{
	unsigned int	n;

	if ((*map).tab)
		ft_free_tab((*map).tab, (*map).size);
	if (((*map).tab = malloc(sizeof(char *) * size)) == NULL)
		return (FALSE);
	n = 0;
	while (n < size)
	{
		if (((*map).tab[n] = malloc(size)) == NULL)
		{
			ft_free_tab((*map).tab, n);
			return (FALSE);
		}
		ft_memset((*map).tab[n++], '.', size);
	}
	(*map).size = size;
	return (TRUE);
}

static void				ft_algo_place_tetriminos(t_tetriminos *tetri,
											t_map map, t_coord coord,
											char c)
{
	map.tab[coord.y + tetri->pos[0].y][coord.x + tetri->pos[0].x] = c;
	map.tab[coord.y + tetri->pos[1].y][coord.x + tetri->pos[1].x] = c;
	map.tab[coord.y + tetri->pos[2].y][coord.x + tetri->pos[2].x] = c;
	map.tab[coord.y + tetri->pos[3].y][coord.x + tetri->pos[3].x] = c;
}

static char				ft_algo_brutforce(t_tetriminos *tetri, t_map map)
{
	t_coord		coord;

	if (tetri == NULL)
		return (TRUE);
	coord.y = 0;
	while (coord.y + tetri->max_value.y < map.size)
	{
		coord.x = 0;
		while (coord.x + tetri->max_value.x < map.size)
		{
			if (ft_algo_tool(tetri, map, coord) == TRUE)
			{
				ft_algo_place_tetriminos(tetri, map, coord, tetri->name);
				if (ft_algo_brutforce(tetri->next, map) == TRUE)
					return (TRUE);
				ft_algo_place_tetriminos(tetri, map, coord, '.');
			}
			coord.x += 1;
		}
		coord.y += 1;
	}
	return (FALSE);
}

char					ft_algo(t_tetriminos *tetriminos)
{
	t_map			map;
	char			end;
	unsigned int	size;

	map.tab = NULL;
	map.size = ft_algo_get_size(ft_nbr_tetriminos(tetriminos) * 4);
	end = FALSE;
	size = map.size;
	while (end == FALSE)
	{
		ft_algo_set_map(size, &map);
		size = map.size;
		if (ft_algo_brutforce(tetriminos, map) == TRUE)
			end = TRUE;
		if (end == FALSE)
			size += 1;
	}
	ft_print(map);
	ft_free_tab(map.tab, map.size);
	return (TRUE);
}
