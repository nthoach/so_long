/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 06:56:41 by codespace         #+#    #+#             */
/*   Updated: 2024/02/16 12:37:39 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	place_image(t_solong *solong, char *loc, int i, int j)
{
	int	sizei;
	int	sizej;

	sizei = IMGH;
	sizej = IMGW;
	solong->img = mlx_xpm_file_to_image(solong->mlx, loc, &sizei, &sizej);
	mlx_put_image_to_window(solong->mlx, solong->mlx_win, solong->img, \
								j * IMGH, i * IMGW);
	mlx_destroy_image(solong->mlx, solong->img);
}

void	put_images(t_solong *solong, int i, int j)
{
	if (solong->map[i][j] == '0')
		place_image(solong, S, i, j);
	else if (solong->map[i][j] == '1')
		place_image(solong, W, i, j);
	else if (solong->map[i][j] == 'P')
	{
		solong->i0 = i;
		solong->j0 = j;
		place_image(solong, S, i, j);
		place_image(solong, P_F, i, j);
	}
	else if (solong->map[i][j] == 'C')
	{
		place_image(solong, S, i, j);
		place_image(solong, C, i, j);
	}
	else if (solong->map[i][j] == 'E')
		place_image(solong, E, i, j);
}

void	draw_map(t_solong *solong)
{
	int	i;
	int	j;

	solong->mlx_win = mlx_new_window(solong->mlx, solong->w * IMGW, \
										solong->h * IMGH, "so_long");
	i = 0;
	while (solong->map[i])
	{
		j = 0;
		while (solong->map[i][j])
		{
			put_images(solong, i, j);
			j++;
		}
		i++;
	}
}
