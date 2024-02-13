/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 07:11:49 by codespace         #+#    #+#             */
/*   Updated: 2024/02/13 08:46:39 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_step(t_solong *solong, int i, int j)
{
	int	i1;
	int	j1;

	i1 = solong->i0 + i;
	j1 = solong->j0 + j;
	if (solong->map_pp[i1][j1] == '1')
		return ;
	if (solong->exit == 0)
	{
		if (solong->map_pp[i1][j1] == 'C')
				solong->no_award--;
		if (solong->map_pp[i1][j1] == '0' || solong->map_pp[i1][j1] == 'C')
		{	
			solong->map_pp[i1][j1] = 'P';
			solong->map_pp[solong->i0][solong->j0] = '0';
		}
		else if (solong->map_pp[i1][j1] == 'E' && solong->no_award == 0)
			close_window(solong);
		else if (solong->map_pp[i1][j1] == 'E' && solong->no_award > 0)
		{
			solong->exit = 1;
			solong->map_pp[i1][j1] = 'P';
			solong->map_pp[solong->i0][solong->j0] = '0';
		}
	}
	else
	{
		if (solong->map_pp[i1][j1] == 'C')
				solong->no_award--;
		if (solong->map_pp[i1][j1] == '0' || solong->map_pp[i1][j1] == 'C')
		{	
			solong->map_pp[i1][j1] = 'P';
			solong->map_pp[solong->i0][solong->j0] = 'E';
			solong->exit = 2;
		}
		else if (solong->map_pp[i1][j1] == 'E')
		{
			solong->exit = 3;
			solong->map_pp[i1][j1] = 'P';
			solong->map_pp[solong->i0][solong->j0] = 'E';
		}
	}
	put_images_move(solong, i1, j1);
	ft_printf("Step: %d\n", ++(solong->ct_steps));
}
