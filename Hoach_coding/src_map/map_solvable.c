/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_solvable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 05:40:11 by codespace         #+#    #+#             */
/*   Updated: 2024/02/13 06:53:26 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	scan_continue(t_solong *solong, int	i, int j)
{
	if (solong->map_pp[i][j] == '1' || solong->map_h[i][j] == '1')
		return (0);
	return (1);
}

void	scan_map(t_solong *solong, int i, int j)
{
	solong->map_h[i][j] = '1';
	if (solong->map_pp[i][j] == 'E')
		solong->ct_exit++;
	if (solong->map_pp[i][j] == 'C')
		solong->ct_award++;
	if (scan_continue(solong, i, j - 1) == 1)
		scan_map(solong, i, j - 1);
	if (scan_continue(solong, i, j + 1) == 1)
		scan_map(solong, i, j + 1);
	if (scan_continue(solong, i - 1, j) == 1)
		scan_map(solong, i - 1, j);
	if (scan_continue(solong, i + 1, j) == 1)
		scan_map(solong, i + 1, j);
}

void	map_solvable(t_solong *solong, int *err)
{
	int	i;
	int j;

	i = 0;
	while (i < solong->height)
	{
		ft_memset(solong->map_h[i], 0, sizeof(char) * solong->width);
		i++;
	}
	i = solong->i0;
	j = solong->j0;
	scan_map(solong, i, j);
	if (solong->ct_exit != 1 || solong->ct_award != solong->no_award)
		msg_err("Error\n Unsolvable Map", err);	
}