/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_all.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:55:16 by codespace         #+#    #+#             */
/*   Updated: 2024/02/13 09:15:29 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_ber(char *ber, int *err)
{
	int	len;

	len = ft_strlen(ber);
	if (len < 4 && ber[len - 4] != '.' && ber[len - 3] != 'b'
		&& ber[len - 2] != 'e' && ber[len - 1] != 'r')
		msg_err("Error\n Invalid Exention [*.ber]\n", err);
}

void	write_map_pp(t_solong *solong, char * ber, int *err)
{
	int		fd;
	char	*line;
	char	*oneline;
	
	oneline = "";
	fd = open(ber, O_RDONLY);
	if (fd < 0)
		msg_err("Error\n Cannot read *.ber file\n", err);
	line = get_next_line(fd);
	if (!line || line[0] == '\n' || line[0] == '\0')
		msg_err( "Invalid Map\n", err);
	while (line)
	{	
		oneline = ft_strjoin(oneline, line);
		line = get_next_line(fd);
		if (line[0] == '\n')
			msg_err("Invalid Map\n", err);
		close(fd);
	}
	solong->map_pp = ft_split(oneline, '\n');
	free(oneline);
	free(line);
}
	
void	check_rect(t_solong *solong, int *err)
{	
	int	i;
	
	solong->width = ft_strlen(solong->map_pp[0]);
	i = 0;
	while (solong->map_pp[i])
	{
		if ((int)ft_strlen(solong->map_pp[i]) != solong->width)
			msg_err("Invalid Map\n", err);
		i++;
	}
		solong->height = i;
}

void	check_wall(t_solong *solong, int *err)
{
	int	i;

	i = 0;
	while (solong->map_pp[0][i])
	{
		if (solong->map_pp[0][i] != '1')
			msg_err("Error\nInvalid Upper Boundary", err);
		if (solong->map_pp[solong->height - 1][i] != '1')
			msg_err("Error\nInvalid Lower Boundary", err);
		i++;
	}
	i = 1;
	while (solong->map_pp[i])
	{
		if (solong->map_pp[i][0] != '1')
			msg_err("Error\nInvalid Left Boundary", err);
		if (solong->map_pp[i][solong->width - 1] != '1')
			msg_err("Error\nInvalid Right Boundary", err);
		i++;
	}
}

int	count_element(t_solong *solong, char c)
{
	int	no;
	int	i;
	int	j;

	i = 0;
	no = 0;
	while (solong->map_pp[i])
	{
		j = 0;
		while (solong->map_pp[i][j])
		{
			if (solong->map_pp[i][j] == c)
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
	solong->no_award = count_element(solong, 'C');
	if (solong->no_award < 1)
		msg_err("Error\nAt Least One Coin Needed", err);
}

void	check_type_element(t_solong *solong, int *err)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (solong->map_pp[i])
	{
		j = 0;
		while (solong->map_pp[i][j])
		{
			c = solong->map_pp[i][j];
			if (c != 'P' && c != 'C' && c != 'E' && c != '0' && c != '1')
				msg_err("Error\nInvalide Symbol on Map", err);
			j++;
		}
		i++;
	}
}

void	check_map_all(t_solong *solong, char *ber, int *err)
{
	check_ber(ber, err);
	write_map_pp(solong, ber, err); // malloc for map_pp inside this function
	check_rect(solong, err);
	check_wall(solong, err);
	check_no_element(solong, err);
	check_type_element(solong, err);	
}