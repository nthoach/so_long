/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 07:11:49 by codespace         #+#    #+#             */
/*   Updated: 2024/02/15 09:58:42 by honguyen         ###   ########.fr       */
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
		close_window(solong, "You Win, Congrats!!!");
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
}

void	move_step(t_solong *solong, int i, int j)
{
	int	i1;
	int	j1;

	i1 = solong->i0 + i;
	j1 = solong->j0 + j;
	if (solong->map[i1][j1] == '1')
		return ;
	if (solong->exit == 0)
		move_step_exit0(solong, i1, j1);
	else
		move_step_exit1(solong, i1, j1);
	put_images_move(solong, i1, j1);
	ft_printf("Step: %d\n", ++(solong->ct_steps));
}
