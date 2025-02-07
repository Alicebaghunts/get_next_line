/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisharu <alisharu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:27:36 by alisharu          #+#    #+#             */
/*   Updated: 2025/02/05 17:11:17 by alisharu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*future_next_line(char *line)
{
	int		count;
	char	*buffer;
	int		i;

	i = 0;
	count = 0;
	while (line[count] && line[count] != '\n')
		count++;
	if (!line[count])
	{
		free(line);
		line = NULL;
		return (NULL);
	}
	buffer = (char *)malloc(sizeof(char) * (ft_strlen(line) - count));
	if (buffer == NULL)
	{
		free(line);
		line = NULL;
		return (NULL);
	}
	while (line[++count])
		buffer[i++] = line[count];
	buffer[i] = '\0';
	return (free (line), buffer);
}

char	*ft_cut_str(char *line)
{
	int		count;
	int		i;
	char	*buffer;

	count = 0;
	i = 0;
	while (line[count] && line[count] != '\n')
		count++;
	buffer = (char *)malloc(sizeof(char) * (count + 2));
	if (buffer == NULL)
		return (NULL);
	while (line[i] && i < count)
	{
		buffer[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
		buffer[i++] = '\n';
	buffer[i] = '\0';
	return (buffer);
}

void	ft_get_line(int fd, char **line)
{
	char	*buffer;
	int		bytes;

	bytes = 0;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return ;
	while (1)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(*line);
			*line = NULL;
			break ;
		}
		if (bytes == 0)
			break ;
		buffer[bytes] = '\0';
		*line = ft_strjoin (*line, buffer);
		if (ft_strchr(*line, '\n') != NULL)
			break ;
	}
	free(buffer);
}

char	*get_next_line(int fd)
{
	static char	*line[OPEN_MAX] = {0};
	char		*curr_line;

	curr_line = NULL;
	if ((fd < 3 && fd != 0) || BUFFER_SIZE <= 0)
		return (NULL);
	ft_get_line(fd, &line[fd]);
	if (!line[fd] || (line[fd] && !*line[fd]))
	{
		free (line[fd]);
		line[fd] = NULL;
		return (NULL);
	}
	curr_line = ft_cut_str(line[fd]);
	if (curr_line && !curr_line[0])
	{
		free (curr_line);
		curr_line = NULL;
		return (NULL);
	}
	line[fd] = future_next_line(line[fd]);
	return (curr_line);
}
