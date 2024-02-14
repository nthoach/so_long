/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_all_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 09:26:03 by honguyen          #+#    #+#             */
/*   Updated: 2024/02/14 11:26:56 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		msg_err("Error\nOnly One Player Needed", err);
	if (count_element(solong, 'E') < 1)
		msg_err("Error\nAt Least One Exit Needed", err);
	solong->no_aw = count_element(solong, 'C');
	if (solong->no_aw < 1)
		msg_err("Error\nAt Least One Coin Needed", err);
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
				msg_err("Error\nInvalid Symbol on Map", err);
			j++;
		}
		i++;
	}
}

void	check_map_all(t_solong *solong, char *ber, int *err)
{
	check_ber(ber, err);
	ft_printf("2.1-OK\n");//
	write_map(solong, ber, err);
	ft_printf("2.2-OK\n");//
	check_rect(solong, err);
	ft_printf("2.3-OK\n");//
	check_wall(solong, err);
	ft_printf("2.4-OK\n");//
	check_no_element(solong, err);
	ft_printf("2.5-OK\n");//
	check_type_element(solong, err);
	ft_printf("2.6-OK\n");//
	if (*err)
	{
		free_solong(solong, "Deleting solong - Exit");
		exit (1);
	}
	ft_printf("2.7-OK\n");//
}
