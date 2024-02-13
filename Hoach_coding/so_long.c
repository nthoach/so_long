/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 05:56:29 by codespace         #+#    #+#             */
/*   Updated: 2024/02/13 09:18:10 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_solong(t_solong *solong, char *s)
{
	int	i;

	i = 0;
	ft_printf("%s\n", s);
	while (solong->map_pp[i])
	{
		free(solong->map_pp[i]);
		i++;
	}
	free(solong->map_pp);
	exit(1);
}

int	user_move(int	key, t_solong *solong)
{
	if (key == 13)
		move_step(solong, 0 , -1); //up
	else if (key == 0)
		move_step(solong, -1 , 0); //left
	else if (key == 1)
		move_step(solong, 0 , 1); //down
	else if (key == 2)
		move_step(solong, 1 , 0); //right
	else if (key == 53)
		close_window(solong);
	return (0);
}

int	close_window(t_solong *solong)
{
	mlx_clear_window(solong->mlx, solong->mlx_win);
	mlx_destroy_window(solong->mlx, solong->mlx_win);
	free_solong(solong, "!!!Congrats!!!You Win!!!");
	exit(0);
}

int	main(int agc, char **agv)
{
	t_solong	*solong;
	int			error;
	
	error = 0;
	solong = NULL;
	ft_memset(solong, 0, sizeof(t_solong));
	if (agc != 2)
	{
		ft_printf("Error\nInvalid Arguments\ne.g., ./so_long ./data/maps/map.ber");		
	}
	check_map_all(solong, agv[1], &error);
	solong->mlx = mlx_init();
	if (!solong->mlx)
		return (0);
	draw_map(solong);	//malloc inside this for solong->map_pp
	map_solvable(solong, &error);
	if (error)
		free_solong(solong, "Free and Exit\n");
	mlx_key_hook(solong->mlx_win, user_move, solong);
	mlx_hook(solong->mlx_win, 17, 0, close_window, solong);
	mlx_loop(solong->mlx);
	return (0);
}