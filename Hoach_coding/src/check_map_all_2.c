/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_all_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:55:16 by codespace         #+#    #+#             */
/*   Updated: 2024/02/14 11:39:40 by honguyen         ###   ########.fr       */
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

char	*join_oneline(int fd, int *err)
{
	char	*line;
	char	*oneline;

	oneline = "";
	line = get_next_line(fd);
	ft_printf("2.2.1-OK\n");//
	if (!line || line[0] == '\n' || line[0] == '\0')
		msg_err("Invalid Map\n", err);
	while (line)
	{
		if (line[0] == '\n')
			msg_err("Invalid Map\n", err);
		oneline = ft_strjoin(oneline, line);
		ft_printf("2.2.1.1-OK\n");//
		line = get_next_line(fd);
	}
	ft_printf("Map = %s", oneline);//
	return (oneline);
}

void	write_map(t_solong *solong, char *ber, int *err)
{
	int		fd;
	char	*oneline;

	fd = open(ber, O_RDONLY);
	if (fd < 0)
		msg_err("Error\n Cannot read *.ber file\n", err);
	oneline = join_oneline(fd, err);
	close(fd);
	solong->map = ft_split(oneline, '\n');
	ft_printf("2.2.2-OK\n");//
	free(oneline);
	ft_printf("2.2.3-OK\n");//
}

void	check_rect(t_solong *solong, int *err)
{
	int	i;

	solong->w = (int)ft_strlen(solong->map[0]);
	i = 0;
	while (solong->map[i])
	{
		if ((int)ft_strlen(solong->map[i]) != solong->w)
			msg_err("Invalid Map\n", err);
		i++;
	}
	solong->h = i;
}

void	check_wall(t_solong *solong, int *err)
{
	int	i;

	i = 0;
	while (solong->map[0][i])
	{
		if (solong->map[0][i] != '1')
			msg_err("Error\nInvalid Upper Boundary", err);
		if (solong->map[solong->h - 1][i] != '1')
			msg_err("Error\nInvalid Lower Boundary", err);
		i++;
	}
	i = 1;
	while (solong->map[i])
	{
		if (solong->map[i][0] != '1')
			msg_err("Error\nInvalid Left Boundary", err);
		if (solong->map[i][solong->w - 1] != '1')
			msg_err("Error\nInvalid Right Boundary", err);
		i++;
	}
}
