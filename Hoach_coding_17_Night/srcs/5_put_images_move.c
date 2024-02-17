/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 07:11:49 by codespace         #+#    #+#             */
/*   Updated: 2024/02/17 10:36:44 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_image_case23(t_solong *solong, int i1, int j1)
{
	if (solong->exit == 2)
	{
		place_image(solong, S, i1, j1);
		place_image(solong, P_F, i1, j1);
		place_image(solong, E, solong->i0, solong->j0);
		solong->exit = 0;
		solong->i0 = i1;
		solong->j0 = j1;
	}
	else if (solong->exit == 3)
	{
		place_image(solong, E, i1, j1);
		place_image(solong, P_F, i1, j1);
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
		place_image(solong, P_F, i1, j1);
		place_image(solong, S, solong->i0, solong->j0);
		solong->i0 = i1;
		solong->j0 = j1;
	}
	else if (solong->exit == 1)
	{
		place_image(solong, E, i1, j1);
		place_image(solong, P_F, i1, j1);
		place_image(solong, S, solong->i0, solong->j0);
		solong->i0 = i1;
		solong->j0 = j1;
	}
	else
		put_image_case23(solong, i1, j1);
}
