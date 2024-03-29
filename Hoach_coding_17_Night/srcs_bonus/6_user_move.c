/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_user_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 07:11:49 by codespace         #+#    #+#             */
/*   Updated: 2024/02/17 11:57:41 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_step_exit0(t_solong *solong, int i1, int j1)
{
	if (solong->map[i1][j1] == 'C')
		solong->no_aw--;
	if (solong->map[i1][j1] == '0' || solong->map[i1][j1] == 'C')
	{
		solong->map[i1][j1] = 'P';
		solong->map[solong->i0][solong->j0] = '0';
	}
	else if (solong->map[i1][j1] == 'E' && solong->no_aw == 0)
		close_window(solong, "You Win, Congrats!!!\n");
	else if (solong->map[i1][j1] == 'G')
		close_window(solong, "Sorry!!! Game Over\n");
	else if (solong->map[i1][j1] == 'E' && solong->no_aw > 0)
	{
		solong->exit = 1;
		solong->map[i1][j1] = 'P';
		solong->map[solong->i0][solong->j0] = '0';
	}
}

void	move_step_exit1(t_solong *solong, int i1, int j1)
{
	if (solong->map[i1][j1] == 'C')
		solong->no_aw--;
	if (solong->map[i1][j1] == '0' || solong->map[i1][j1] == 'C')
	{
		solong->map[i1][j1] = 'P';
		solong->map[solong->i0][solong->j0] = 'E';
		solong->exit = 2;
	}
	else if (solong->map[i1][j1] == 'E')
	{
		solong->exit = 3;
		solong->map[i1][j1] = 'P';
		solong->map[solong->i0][solong->j0] = 'E';
	}
	else if (solong->map[i1][j1] == 'G')
		close_window(solong, "Sorry!!! Game Over\n");
}

void	move_step(t_solong *solong, int i, int j)
{
	int		i1;
	int		j1;
	char	*steps;

	i1 = solong->i0 + i;
	j1 = solong->j0 + j;
	if (solong->map[i1][j1] == '1')
		return ;
	steps = ft_strjoin("Steps: ", ft_itoa(++(solong->ct_steps)));
	if (solong->exit == 0)
		move_step_exit0(solong, i1, j1);
	else
		move_step_exit1(solong, i1, j1);
	put_images_move(solong, i1, j1);
	place_image(solong, W0, 0, 0);
	mlx_string_put(solong->mlx, solong->mlx_win, 15, 53, ORANGE, steps);
	ft_printf("%s\n", steps);
	ft_printf("C = %i\n", solong->no_aw);
	free(steps);
}
