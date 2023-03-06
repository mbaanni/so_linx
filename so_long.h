/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaanni <mbaanni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 08:16:50 by mbaanni           #+#    #+#             */
/*   Updated: 2023/03/06 11:57:35 by mbaanni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define SPRITE 64

# include "get_next_line.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_data
{
	void			*img[6];
	void			*cimg[4];
}					t_data;

typedef struct t_plist
{
	int				x;
	int				y;
	int				c;
	int				n;
	char			*n_move;
	int				e;
	int				*en;
	int				p[2];
}					t_plist;

typedef struct mlx_in
{
	void			*mlx;
	void			*win;
	char			**pam;
	unsigned int	move;
	int				e[2];
	t_plist			data;
	t_data			img;
}	t_mdata;

typedef struct rund
{
	int				*arr;
	int				**ps;
	int				fl;
}					t_frund;

int					close_it(t_mdata *mlx);
int					render_frame(t_mdata *mlx);
int					event(int keycode, t_mdata *mlx);
void				check_path(t_mdata *mlx);
char				**read_map(int fd);
void				ft_putnbr(int nbr);
void				load_image(t_mdata *mlx);
int					**rand_it(t_mdata *mlx, int t, int counter);
void				enemy_conf(t_mdata *mlx, int counter);
void				find_enemy(t_mdata *mlx, int i);
char				**ft_split(char const *s, char c);
void				*f_calloc(size_t size);
void				free_it_2d(char **str);
void				ft_end(t_mdata *mlx);
void				up_down(t_mdata *mlx, int keycode, int *p);
void				right_left(t_mdata *mlx, int keycode, int *p);
char				**check_file(char *av, t_mdata *data);
void				ft_n_to_s(unsigned int nbr, t_mdata *mlx);
void				free_move(t_mdata *mlx);
int					check_element(char **pam, t_plist *data, int j);
int					valid_path(char **pam);
#endif
