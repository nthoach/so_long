/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 14:02:32 by honguyen          #+#    #+#             */
/*   Updated: 2024/02/13 09:12:32 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libs/libft/libft.h"
# include "libs/mlx/mlx.h"

# define S	"data/xpm/S.xpm"
# define W	"data/xpm/W.xpm"
# define P	"data/xpm/P.xpm"
# define C	"data/xpm/C.xpm"
# define E	"data/xpm/E.xpm"
# define IMGW	100
# define IMGH	100

typedef struct s_solong
{
	int		width;
	int		height;
	int		no_award;
	int		ct_exit;
	int		ct_award;
	int		exit;
	int		i0;
	int		j0;
	int		ct_steps;
	char	**map_pp;
	char	map_h[256][256];
	void	*mlx;
	void	*mlx_win;
	void	*image;
}	t_solong;

int		close_window(t_solong *solong);
int		user_move(int	key, t_solong *solong);
void	free_solong(t_solong *solong, char *s);
int		msg_err(char *s, int *err);
void	move_step(t_solong *solong, int i, int j);
void	put_images_move(t_solong *solong, int i1, int j1);

int		scan_continue(t_solong *solong, int	i, int j);
void	scan_map(t_solong *solong, int i, int j);
void	map_solvable(t_solong *solong, int *err);
void	place_image(t_solong *solong, char *loc, int i, int j);
void	put_images(t_solong *solong, int i, int j);
void	draw_map(t_solong *solong);

void	check_ber(char *ber, int *err);
void	write_map_pp(t_solong *solong, char * ber, int *err);
void	check_rect(t_solong *solong, int *err);
void	check_wall(t_solong *solong, int *err);
int		count_element(t_solong *solong, char c);
void	check_no_element(t_solong *solong, int *err);
void	check_type_element(t_solong *solong, int *err);
void	check_map_all(t_solong *solong, char *ber, int *err);

#endif