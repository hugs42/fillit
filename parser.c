/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 13:16:14 by hugsbord          #+#    #+#             */
/*   Updated: 2018/08/30 21:51:30 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int					ft_tetri_counter(t_tetriminos *tetriminos)
{
	int				i;
	t_tetriminos	*tmp;

	tmp = tetriminos;
	i = 0;
	while (tmp->next != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	return (i + 1);
}

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

static void			ft_parser_check_tetriminos(const char buf[BUFFER_SIZE],
								t_tetriminos *tetriminos)
{
	int		n;
	int		i;
	int		index;

	n = 0;
	while (buf[n] != '#')
		n += 1;
	index = 1;
	while (index < 4)
	{
		i = n + 1;
		while (buf[i] != '#')
			i += 1;
		ft_parser_add_value(tetriminos, index, i - n);
		n = i;
		index += 1;
	}
	ft_parser_balance(tetriminos);
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
	tmp = tetriminos;
	while (tmp)
	{
		ft_putstr("Name : ");
		ft_putchar(tmp->name);
		ft_putstr("\nPOS[X] : x/y");
		ft_putstr("\nPOS[0] : ");
		ft_putnbr(tmp->pos[0].x);
		ft_putchar('/');
		ft_putnbr(tmp->pos[0].y);
		ft_putstr("\nPOS[1] : ");
		ft_putnbr(tmp->pos[1].x);
		ft_putchar('/');
		ft_putnbr(tmp->pos[1].y);
		ft_putstr("\nPOS[2] : ");
		ft_putnbr(tmp->pos[2].x);
		ft_putchar('/');
		ft_putnbr(tmp->pos[2].y);
		ft_putstr("\nPOS[3] : ");
		ft_putnbr(tmp->pos[3].x);
		ft_putchar('/');
		ft_putnbr(tmp->pos[3].y);
		ft_putstr("\n\n");
		tmp = tmp->next;
	}
	if ((ft_solve(tetriminos, 0, ft_tetri_counter(tetriminos))) == FALSE)
		return (FALSE);
	return (TRUE);
}
