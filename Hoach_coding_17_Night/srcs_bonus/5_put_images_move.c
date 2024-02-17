/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_put_images_move.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 07:11:49 by codespace         #+#    #+#             */
/*   Updated: 2024/02/17 12:13:56 by honguyen         ###   ########.fr       */
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

void	put_enemy2(t_solong	*solong, int ri, int rj)
{
	solong->map[solong->ri0][solong->rj0] = 'C';
	place_image(solong, S, solong->ri0, solong->rj0);
	place_image(solong, C, solong->ri0, solong->rj0);
	solong->no_aw++;
	if (solong->map[ri][rj] == 'C')
		solong->no_aw--;
	solong->map[ri][rj] = 'G';
	place_image(solong, S, ri, rj);
	place_image(solong, G, ri, rj);
	solong->ri0 = ri;
	solong->rj0 = rj;
}

void	put_image_enemy(t_solong *solong, int i1, int j1)
{
	int	ri;
	int	rj;
	int	d;

	ri = 1 + rand() % (solong->h - 1);
	rj = 1 + rand() % (solong->w - 1);
	d = (ri - i1) * (ri - i1) * (rj - j1) * (rj - j1);
	if (!(solong->ri0) && !(solong->rj0) && solong->map[ri][rj] == '0')
	{
		solong->ri0 = ri;
		solong->rj0 = rj;
	}
	else if ((solong->map[ri][rj] == '0' || solong->map[ri][rj] \
		== 'C') && d <= 1)
		put_enemy2(solong, ri, rj);
}

void	put_images_move(t_solong *solong, int i1, int j1)
{
	put_image_enemy(solong, i1, j1);
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
