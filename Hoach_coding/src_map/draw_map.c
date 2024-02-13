/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 06:56:41 by codespace         #+#    #+#             */
/*   Updated: 2024/02/13 07:41:27 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	place_image(t_solong *solong, char *loc, int i, int j)
{
	int	sizei;
	int	sizej;

	sizei = IMGH;
	sizej = IMGW;
	solong->image = mlx_xpm_file_to_image(solong->mlx, loc, &sizei, &sizej);
	mlx_put_image_to_window(solong->mlx, solong->mlx_win, solong->image, i * sizei, j * sizej);
	mlx_destroy_image(solong->mlx, solong->image);
}

void	put_images(t_solong *solong, int i, int j)
{
	if (solong->map_pp[i][j] == '0')
		place_image(solong, S, i, j);
	else if (solong->map_pp[i][j] == '1')
		place_image(solong, W, i, j);
	else if (solong->map_pp[i][j] == 'P')
	{
		solong->i0 = i;
		solong->j0 = j;
		place_image(solong, S, i, j);
		place_image(solong, P, i, j);
	}
	else if (solong->map_pp[i][j] == 'C')
	{
		place_image(solong, S, i, j);
		place_image(solong, C, i, j);
	}
	else if (solong->map_pp[i][j] == 'E')
		place_image(solong, E, i, j);
}

void	draw_map(t_solong *solong)
{
	int	i;
	int	j;
		
	solong->mlx_win = mlx_new_window(solong->mlx, solong->width * IMGW,
		solong->height * IMGH, "so_long");
	i = 0;
	while (solong->map_pp[i])
	{
		j = 0;
		while (solong->map_pp[i][j])
		{
			put_images(solong, i, j);
			j++;
		}
		i++;		
	}
}