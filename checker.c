/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 12:23:06 by hugsbord          #+#    #+#             */
/*   Updated: 2018/08/30 22:14:21 by hugsbord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		ft_validation_last_verif(char buf[BUFFER_SIZE])
{
	int		n;

	if (ft_strchr(buf, '#') != NULL)
		return (FALSE);
	n = 0;
	while (buf[n])
	{
		if (buf[n] == 'O')
			buf[n] = '#';
		n = n + 1;
	}
	return (TRUE);
}

static void		ft_validation_check_tetriminos(char buf[BUFFER_SIZE], int n,
											int *nbr)
{
	if (buf[n] == '#')
	{
		buf[n] = 'O';
		*nbr = *nbr + 1;
	}
	else
		return ;
	if (n - 5 > 0)
		ft_validation_check_tetriminos(buf, n - 5, nbr);
	if (n - 1 > 0)
		ft_validation_check_tetriminos(buf, n - 1, nbr);
	if (n + 1 < 20)
		ft_validation_check_tetriminos(buf, n + 1, nbr);
	if (n + 5 < 20)
		ft_validation_check_tetriminos(buf, n + 5, nbr);
}

static char		ft_validation_check_all_tetriminos(char buf[BUFFER_SIZE])
{
	int		n;
	int		i;
	int		nbr;

	n = 0;
	while (buf[n])
	{
		i = n;
		while (i - n < 20 && buf[i] != '#')
			i = i + 1;
		if (buf[i] != '#')
			return (FALSE);
		nbr = 0;
		ft_validation_check_tetriminos(buf + n, i - n, &nbr);
		if (nbr != 4)
			return (FALSE);
		n = (buf[n + 20] == '\0') ? n + 20 : n + 21;
	}
	if (ft_validation_last_verif(buf) == FALSE)
		return (FALSE);
	return (TRUE);
}

static char		ft_validation_check_line(const char c, const char end)
{
	static int		line = 0;
	static int		col = 0;
	static char		new_tetri = FALSE;

	if (c == '.' || c == '#')
	{
		col = col + 1;
		new_tetri = FALSE;
	}
	if (col > 4)
		return (FALSE);
	if (c == '\n')
	{
		if (((new_tetri == TRUE) ? line : col) != 4)
			return (FALSE);
		if (new_tetri == FALSE)
			col = 0;
		line = (new_tetri == TRUE) ? 0 : line + 1;
		new_tetri = (new_tetri == TRUE) ? FALSE : TRUE;
	}
	if (end == TRUE && (new_tetri != TRUE || line != 4 || col != 0))
		return (FALSE);
	return (TRUE);
}

char			ft_validation(char buf[BUFFER_SIZE])
{
	int		n;

	n = 0;
	while (buf[n])
	{
		if (buf[n] != '.' && buf[n] != '#' && buf[n] != '\n')
			return (FALSE);
		if (ft_validation_check_line(buf[n], FALSE) == FALSE)
			return (FALSE);
		n = n + 1;
	}
	if (ft_validation_check_line(buf[n], TRUE) == FALSE)
		return (FALSE);
	if (ft_validation_check_all_tetriminos(buf) == FALSE)
		return (FALSE);
	return (TRUE);
}
