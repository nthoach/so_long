/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 07:11:49 by codespace         #+#    #+#             */
/*   Updated: 2024/02/16 13:22:59 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*select_player_img(t_solong *solong, int i1, int j1)
{
	if ((i1 - solong->i0) == -1)
		return (P_B);
	else if ((j1 - solong->j0) == -1)
		return (P_L);
	else if ((j1 - solong->j0) == 1)
		return (P_R);
	else
		return (P_F);
}

void	put_image_case23(t_solong *solong, int i1, int j1)
{
	if (solong->exit == 2)
	{
		place_image(solong, S, i1, j1);
		place_image(solong, select_player_img(solong, i1, j1), i1, j1);
		place_image(solong, E, solong->i0, solong->j0);
		solong->exit = 0;
		solong->i0 = i1;
		solong->j0 = j1;
	}
	else if (solong->exit == 3)
	{
		place_image(solong, E, i1, j1);
		place_image(solong, select_player_img(solong, i1, j1), i1, j1);
		place_image(solong, E, solong->i0, solong->j0);
		solong->exit = 1;
		solong->i0 = i1;
		solong->j0 = j1;
	}
}

void	put_images_move(t_solong *solong, int i1, int j1)
{
	if (solong->exit == 0)
	{
		place_image(solong, S, i1, j1);
		place_image(solong, select_player_img(solong, i1, j1), i1, j1);
		place_image(solong, S, solong->i0, solong->j0);
		solong->i0 = i1;
		solong->j0 = j1;
	}
	else if (solong->exit == 1)
	{
		place_image(solong, E, i1, j1);
		place_image(solong, select_player_img(solong, i1, j1), i1, j1);
		place_image(solong, S, solong->i0, solong->j0);
		solong->i0 = i1;
		solong->j0 = j1;
	}
	else
		put_image_case23(solong, i1, j1);
}
