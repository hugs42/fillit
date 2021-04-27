/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 13:16:14 by hugsbord          #+#    #+#             */
/*   Updated: 2018/09/01 20:59:39 by vimucchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void			ft_parser_balance(t_tetriminos *tetriminos)
{
	int		min;
	int		index;

	min = 4;
	index = 0;
	while (index < 4)
	{
		if (tetriminos->pos[index].x < min)
			min = tetriminos->pos[index].x;
		index = index + 1;
	}
	index = 0;
	while (index < 4)
		tetriminos->pos[index++].x -= min;
	min = 4;
	index = 0;
	while (index < 4)
	{
		if (tetriminos->pos[index].y < min)
			min = tetriminos->pos[index].y;
		index = index + 1;
	}
	index = 0;
	while (index < 4)
		tetriminos->pos[index++].y -= min;
}

static void			ft_parser_add_value(t_tetriminos *tetriminos, int index,
										int nbr)
{
	int		n;

	if (nbr == 1)
	{
		tetriminos->pos[index].x = tetriminos->pos[index - 1].x + 1;
		tetriminos->pos[index].y = tetriminos->pos[index - 1].y;
	}
	else if (nbr == 5)
	{
		tetriminos->pos[index].x = tetriminos->pos[index - 1].x;
		tetriminos->pos[index].y = tetriminos->pos[index - 1].y + 1;
	}
	else
	{
		tetriminos->pos[index].x = tetriminos->pos[index - 1].x;
		tetriminos->pos[index].y = tetriminos->pos[index - 1].y + 1;
		n = 0;
		while (n < index)
			tetriminos->pos[n++].x += (5 - nbr);
	}
}

static void			ft_parser_max_value(t_tetriminos *tetriminos)
{
	unsigned char	index;

	index = 0;
	while (index < 4)
	{
		if (tetriminos->pos[index].y > tetriminos->max_value.y)
			tetriminos->max_value.y = tetriminos->pos[index].y;
		index = index + 1;
	}
	index = 0;
	while (index < 4)
	{
		if (tetriminos->pos[index].x > tetriminos->max_value.x)
			tetriminos->max_value.x = tetriminos->pos[index].x;
		index = index + 1;
	}
}

static void			ft_parser_check_tetriminos(const char buf[BUFFER_SIZE],
												t_tetriminos *tetriminos)
{
	int		n;
	int		i;
	int		index;

	n = 0;
	while (buf[n] != '#')
		n = n + 1;
	index = 1;
	while (index < 4)
	{
		i = n + 1;
		while (buf[i] != '#')
			i = i + 1;
		ft_parser_add_value(tetriminos, index, i - n);
		n = i;
		index = index + 1;
	}
	ft_parser_balance(tetriminos);
	ft_parser_max_value(tetriminos);
}

char				ft_parser(char buf[BUFFER_SIZE])
{
	t_tetriminos	*tetriminos;
	t_tetriminos	*tmp;
	int				n;

	if ((tetriminos = ft_init_tetriminos()) == NULL)
		return (FALSE);
	n = 0;
	tmp = tetriminos;
	while (buf[n])
	{
		if (n != 0 && (tmp = ft_add_tetriminos(tetriminos)) == NULL)
			return (FALSE);
		ft_parser_check_tetriminos(buf + n, tmp);
		n = (buf[n + 20] == '\0') ? n + 20 : n + 21;
	}
	ft_algo(tetriminos);
	ft_clear_tetriminos(tetriminos);
	return (TRUE);
}
