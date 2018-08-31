#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "./libft/libft.h"

# define BUFFER_SIZE	(546)
# define TRUE			(1)
# define FALSE			(0)
# define ERROR			(-1)
# define FINISH			(0)

typedef struct		s_coord {
	unsigned char			x;
	unsigned char			y;
}					t_coord;

typedef struct		s_tetriminos {
	unsigned char			name;
	t_coord					pos[4];
	t_coord					max_value;
	int						flag;
	struct s_tetriminos		*next;
}					t_tetriminos;

typedef struct		s_map {
	char					**tab;
	unsigned int			size;
}					t_map;

t_tetriminos	*ft_init_tetriminos(void);
void		ft_clear_tetriminos(t_tetriminos *tetriminos);
t_tetriminos	*ft_add_tetriminos(t_tetriminos *tetriminos);
unsigned int	ft_nbr_tetriminos(t_tetriminos *tetriminos);
void		ft_free_tab(char **map, unsigned int size);
char		ft_validation(char buf[BUFFER_SIZE]);
char		ft_parser(char buf[BUFFER_SIZE]);
char		ft_algo(t_tetriminos *tetriminos);
void		ft_print(t_map map);
#endif
