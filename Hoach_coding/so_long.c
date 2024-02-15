/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 05:56:29 by codespace         #+#    #+#             */
/*   Updated: 2024/02/15 11:08:32 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	msg_err(char *s, int *err)
{
	ft_printf("%s\n", s);
	*err = 1;
	return (1);
}

void	free_solong(t_solong *solong, char *s)
{
	int	i;

	i = 0;
	ft_printf("%s\n", s);
	while (solong->map[i])
	{
		free(solong->map[i]);
		i++;
	}
	free(solong->map);
	exit (1);
}
// move: up, left, down, right

int	user_move(int key, t_solong *solong)
{
	if (key == KEY_LEFT || key == KEY_A)
		move_step(solong, 0, -1);
	else if (key == KEY_RIGHT || key == KEY_D)
		move_step(solong, 0, 1);
	else if (key == KEY_UP || key == KEY_W)
		move_step(solong, -1, 0);
	else if (key == KEY_DOWN || key == KEY_S)
		move_step(solong, 1, 0);
	else if (key == KEY_ESC || key == KEY_Q)
		close_window(solong, "Window Closed.");
	return (0);
}

int	close_window(t_solong *solong, char *s)
{
	if (*s == 'c')
		s = "Window Closed.";
	mlx_clear_window(solong->mlx, solong->mlx_win);
	mlx_destroy_window(solong->mlx, solong->mlx_win);
	free_solong(solong, s);
	exit(0);
}

int	main(int agc, char **agv)
{
	t_solong	solong;
	int			error;

	error = 0;
	ft_memset(&solong, 0, sizeof(t_solong));
	if (agc != 2)
	{
		msg_err("Invalid Arguments, e.g., ./so_long map.ber", &error);
		return (-1);
	}
	check_map_all(&solong, agv[1], &error);
	solong.mlx = mlx_init();
	if (!solong.mlx)
		return (0);
	draw_map(&solong);
	map_solvable(&solong, &error);
	if (error)
		free_solong(&solong, "Free and Exit\n");
	mlx_key_hook(solong.mlx_win, user_move, &solong);
	mlx_hook(solong.mlx_win, 17, 0, close_window, &solong);
	mlx_loop(solong.mlx);
	return (0);
}