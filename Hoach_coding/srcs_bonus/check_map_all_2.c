/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_all_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:55:16 by codespace         #+#    #+#             */
/*   Updated: 2024/02/16 09:45:45 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_ber(char *ber, int *err)
{
	int	len;

	len = ft_strlen(ber);
	if (len < 4 || ber[len - 4] != '.' || ber[len - 3] != 'b'
		|| ber[len - 2] != 'e' || ber[len - 1] != 'r')
		msg_err("Invalid File Name [*.ber]\n", err);
}

char	*join_oneline(int fd, int *err)
{
	char	*line;
	char	*oneline;

	oneline = "";
	line = get_next_line(fd);
	if (!line)
		msg_err("Empty *.ber file\n", err);
	while (line)
	{
		if (line[0] == '\n' || line[0] == '\0')
		{
			*err = 1;
			get_next_line_err(fd, err);
			close(fd);
			if (!oneline)
				free(oneline);
			if (!line)
				free(line);
			msg_err("Empty Line on Map\n", err);
		}
		oneline = ft_strjoin(oneline, line);
		line = get_next_line(fd);
	}
	return (oneline);
}

void	write_map(t_solong *solong, char *ber, int *err)
{
	int		fd;
	char	*oneline;

	fd = open(ber, O_RDONLY);
	if (fd < 0)
		msg_err("File *.ber not found\n", err);
	oneline = join_oneline(fd, err);
	close(fd);
	solong->map = ft_split(oneline, '\n');
	if (!oneline)
		free(oneline);
}

void	check_rect(t_solong *solong, int *err)
{
	int	i;

	solong->w = (int)ft_strlen(solong->map[0]);
	i = 0;
	while (solong->map[i])
	{
		if ((int)ft_strlen(solong->map[i]) != solong->w)
		{
			free_solong(solong);
			msg_err("Map is not rectangular\n", err);
		}
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
		{
			free_solong(solong);
			msg_err("Invalid Upper Boundary\n", err);
		}
		if (solong->map[solong->h - 1][i] != '1')
		{			
			free_solong(solong);
			msg_err("Invalid Lower Boundary\n", err);
		}
		i++;
	}
	i = 1;
	while (solong->map[i])
	{
		if (solong->map[i][0] != '1')
		{
			free_solong(solong);
			msg_err("Invalid Left Boundary\n", err);			
		}

		if (solong->map[i][solong->w - 1] != '1')
		{
			free_solong(solong);
			msg_err("Invalid Right Boundary\n", err);			
		}

		i++;
	}
}
