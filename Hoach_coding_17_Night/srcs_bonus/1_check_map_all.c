/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_all_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthoach <nthoach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 09:26:03 by honguyen          #+#    #+#             */
/*   Updated: 2024/02/16 22:09:42 by nthoach          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../so_long.h"

int	count_element(t_solong *solong, char c)
{
	int	no;
	int	i;
	int	j;

	i = 0;
	no = 0;
	while (solong->map[i])
	{
		j = 0;
		while (solong->map[i][j])
		{
			if (solong->map[i][j] == c)
				no++;
			j++;
		}
		i++;
	}
	return (no);
}

void	check_no_element(t_solong *solong, int *err)
{
	if (count_element(solong, 'P') != 1)
	{
		free_solong(solong);
		msg_err("One Player\n", err);
	}
	if (count_element(solong, 'E') != 1)
	{
		free_solong(solong);
		msg_err("One Exit\n", err);
	}
	solong->no_aw = count_element(solong, 'C');
	if (solong->no_aw < 1)
	{
		free_solong(solong);
		msg_err("At Least One Collectibles", err);
	}
}

void	check_type_element(t_solong *solong, int *err)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (solong->map[i])
	{
		j = 0;
		while (solong->map[i][j])
		{
			c = solong->map[i][j];
			if (c != 'P' && c != 'C' && c != 'E' && c != '0' && c != '1')
			{
				free_solong(solong);
				msg_err("Invalid Symbol on Map\n", err);
			}
			j++;
		}
		i++;
	}
}

void	check_map_all(t_solong *solong, char *ber, int *err)
{
	check_ber(ber, err);
	write_map(solong, ber, err);
	check_rect(solong, err);
	check_wall(solong, err);
	check_no_element(solong, err);
	check_type_element(solong, err);
}
