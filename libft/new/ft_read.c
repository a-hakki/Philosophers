/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:58:40 by aelsayed          #+#    #+#             */
/*   Updated: 2025/03/07 00:50:08 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	**ft_read(int fd, char *filename)
{
	char	**file;
	char	*line;
	int		line_counter;
	int		i;

	if (!filename)
		return (NULL);
	i = 0;
	line_counter = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line_counter++;
		line = get_next_line(fd);
	}
	file = (char **)malloc((line_counter + 1) * sizeof(char *));
	if (!file)
		return (NULL);
	fd = open(filename, O_RDONLY);
	while (i < line_counter + 1)
		file[i++] = get_next_line(fd);
	close (fd);
	return (file);
}
