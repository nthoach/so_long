/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 14:02:32 by honguyen          #+#    #+#             */
/*   Updated: 2024/02/17 13:25:33 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libs/libft/libft.h"
# include "libs/mlx/mlx.h"

# define S	"data/xpm/S100.xpm"
# define W	"data/xpm/W100.xpm"
# define W0	"data/xpm/W0100.xpm"
# define P	"data/xpm/P100.xpm"
# define P_F	"data/xpm/P_F100.xpm"
# define P_B	"data/xpm/P_B100.xpm"
# define P_R	"data/xpm/P_R100.xpm"
# define P_L	"data/xpm/P_L100.xpm"
# define C	"data/xpm/C100.xpm"
# define E	"data/xpm/E100.xpm"
# define G "data/xpm/G.xpm"

# ifndef LEVEL
#  define LEVEL 3
# endif

# define ORANGE 0xFE6500
# define WHITE	0xFFFFFF
# define IMGW		100
# define IMGH		100
# define KEY_A		0
# define KEY_D		2
# define KEY_W		13
# define KEY_S		1	
# define KEY_LEFT	123
# define KEY_RIGHT	124
# define KEY_UP		126
# define KEY_DOWN	125
# define KEY_ESC	53
# define KEY_Q		12

typedef struct s_solong
{
	int		w;
	int		h;
	int		no_aw;
	int		ct_exit;
	int		ct_aw;
	int		exit;
	int		i0;
	int		j0;
	int		ri0;
	int		rj0;
	int		ct_steps;
	char	**map;
	char	map_h[256][256];
	void	*mlx;
	void	*mlx_win;
	void	*mlx_text;
	void	*img;
}	t_solong;

void	msg_err(char *s, int *err);
void	free_solong(t_solong *solong);
int		user_move(int key, t_solong *solong);
int		close_window(t_solong *solong, char *s);

void	move_step_exit0(t_solong *solong, int i1, int j1);
void	move_step_exit1(t_solong *solong, int i1, int j1);
void	move_step(t_solong *solong, int i, int j);

void	put_image_case23(t_solong *solong, int i1, int j1);
void	put_images_move(t_solong *solong, int i1, int j1);

int		scan_continue(t_solong *solong, int i, int j);
void	scan_map(t_solong *solong, int i, int j);
void	map_solvable(t_solong *solong, int *err);

void	place_image(t_solong *solong, char *loc, int i, int j);
void	put_images(t_solong *solong, int i, int j);
void	draw_map(t_solong *solong);
void	put_enemy2(t_solong	*solong, int ri, int rj);
void	put_image_enemy(t_solong *solong, int i1, int j1);
char	*select_player_img(t_solong *solong, int i1, int j1);

void	check_ber(char *ber, int *err);
char	*join_oneline(int fd, int *err);
void	write_map(t_solong *solong, char *ber, int *err);
void	check_rect(t_solong *solong, int *err);
void	check_wall(t_solong *solong, int *err);

int		count_element(t_solong *solong, char c);
void	check_no_element(t_solong *solong, int *err);
void	check_type_element(t_solong *solong, int *err);
void	check_map_all(t_solong *solong, char *ber, int *err);

#endif