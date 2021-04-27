/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugsbord <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 19:30:22 by hugsbord          #+#    #+#             */
/*   Updated: 2018/09/02 15:19:57 by vimucchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		ft_read(int fd)
{
	char	buf[BUFFER_SIZE + 1];
	ssize_t	ret;

	if ((ret = read(fd, buf, BUFFER_SIZE)) == -1)
		return (FALSE);
	if (ret == BUFFER_SIZE || ret == 0)
		return (FALSE);
	buf[ret] = '\0';
	if (ft_validation(buf) == FALSE)
		return (FALSE);
	if (ft_parser(buf) == FALSE)
		return (FALSE);
	return (TRUE);
}

static char		ft_open(const char *path)
{
	int		fd;

	if (path == NULL)
		return (FALSE);
	if ((fd = open(path, O_RDONLY)) == -1)
		return (FALSE);
	if (ft_read(fd) == FALSE)
		return (FALSE);
	if (close(fd) == -1)
		return (FALSE);
	return (TRUE);
}

int				main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putendl_fd("Usage: ./fillit [file]", 1);
		return (ERROR);
	}
	if (ft_open(argv[1]) == FALSE)
	{
		ft_putendl_fd("error", 1);
		return (ERROR);
	}
	return (FINISH);
}
