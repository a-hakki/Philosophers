/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 23:56:08 by aelsayed          #+#    #+#             */
/*   Updated: 2025/03/07 00:28:42 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*freed(char *store, char *buffer)
{
	if (store)
	{
		free(store);
		store = NULL;
	}
	if (buffer)
	{
		free(buffer);
		buffer = NULL;
	}
	return (NULL);
}

static char	*fetch_segment(char *store, int fd)
{
	char	*buffer;
	char	*total;
	ssize_t	readbytes;

	readbytes = 1;
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer || !store)
		return (freed(store, buffer));
	while (readbytes > 0 && ft_strchr_index(store, '\n') == -1)
	{
		readbytes = read(fd, buffer, BUFFER_SIZE);
		if (readbytes == -1)
			return (freed(store, buffer));
		buffer[readbytes] = '\0';
		total = ft_strjoin(store, buffer);
		if (!total)
			return (freed(store, buffer));
		free(store);
		store = total;
	}
	free(buffer);
	return (store);
}

static char	*segment_to_newline(char *store)
{
	char	*line;
	int		position;

	position = 0;
	if (!store || !*store)
		return (NULL);
	while (store[position] != '\n' && store[position])
		position++;
	if (!store[1])
		line = ft_strndup(store, 1);
	else if (!store[position])
		line = ft_strndup(store, position);
	else
		line = ft_strndup(store, position + 1);
	return (line);
}

static char	*clear_till_newline(char *store)
{
	int		position;
	char	*new_store;

	position = 0;
	while (store[position] != '\n' && store[position])
		position++;
	if (!store[position])
		return (freed(store, NULL));
	new_store = ft_substr(store, position + 1, ft_strlen(store));
	free(store);
	return (new_store);
}

char	*get_next_line(int fd)
{
	static char	*store;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= 0x7FFFFFFF)
		return (free(store), NULL);
	if (!store)
		store = ft_strndup("", 0);
	store = fetch_segment(store, fd);
	if (!store)
		return (NULL);
	line = segment_to_newline(store);
	if (!line)
	{
		free(store);
		store = NULL;
		return (NULL);
	}
	store = clear_till_newline(store);
	return (line);
}
