/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msucu <msucu@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 11:39:47 by msucu             #+#    #+#             */
/*   Updated: 2025/07/05 19:48:52 by msucu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

char	*ft_free(char **buffer, char **leftover, char **line, char *which_ones)
{
	if (*buffer && which_ones[0] == '1')
		free(*buffer);
	if (*leftover && which_ones[1] == '1')
		free(*leftover);
	if (*line && which_ones[2] == '1')
		free(*line);
	if (which_ones[0] == '1')
		*buffer = FT_NULL;
	if (which_ones[1] == '1')
		*leftover = FT_NULL;
	if (which_ones[2] == '1')
		*line = FT_NULL;
	return (FT_NULL);
}

char	*ft_val_update(char **line, char **leftover, char **buffer)
{
	char	*ln_location;

	ln_location = ft_strchr(*line, '\n');
	(*leftover)[0] = '\0';
	if (ln_location)
	{
		*leftover = ft_strjoin(*leftover, ln_location + 1);
		if (*leftover == FT_NULL)
			return (ft_free(buffer, leftover, line, "111"));
	}
	else
	{
		if (ft_strlen(*line) == 0)
			return (ft_free(buffer, leftover, line, "111"));
		*leftover = ft_strjoin(*leftover, "");
		if (*leftover == FT_NULL)
			return (ft_free(buffer, leftover, line, "111"));
	}
	if (ln_location)
		*(ln_location + 1) = '\0';
	*line = ft_strjoin(*line, "");
	if (*line == FT_NULL)
		return (ft_free(buffer, leftover, line, "111"));
	return (*line);
}

char	*ft_controls(char **buffer, char **line, char **leftover, int fd)
{
	*buffer = FT_NULL;
	*line = FT_NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (ft_free(buffer, leftover, line, "111"));
	*buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (*buffer == FT_NULL)
		return (ft_free(buffer, leftover, line, "111"));
	*line = (char *)malloc(1 * sizeof(char));
	if (*line == FT_NULL)
		return (ft_free(buffer, leftover, line, "111"));
	(*line)[0] = '\0';
	if (*leftover == FT_NULL)
	{
		*leftover = (char *)malloc(1 * sizeof(char));
		if (*leftover == FT_NULL)
			return (ft_free(buffer, leftover, line, "111"));
		(*leftover)[0] = '\0';
	}
	return (*line);
}

char	*ft_read_while(char **line, char **leftover, char *buffer, int fd)
{
	int	read_len;

	if (!ft_strchr(*leftover, '\n'))
	{
		read_len = read(fd, buffer, BUFFER_SIZE);
		while (read_len != 0)
		{
			if (read_len <= -1)
				return (ft_free(&buffer, leftover, line, "111"));
			buffer[read_len] = '\0';
			*line = ft_strjoin(*line, buffer);
			if (*line == FT_NULL)
				return (ft_free(&buffer, leftover, line, "111"));
			if (ft_strchr(*line, '\n'))
				break ;
			read_len = read(fd, buffer, BUFFER_SIZE);
		}
	}
	return (*line);
}

char	*get_next_line(int fd)
{
	static char	*leftover = FT_NULL;
	char		*buffer;
	char		*line;

	if (ft_controls(&buffer, &line, &leftover, fd) == FT_NULL)
	{
		leftover = FT_NULL;
		return (FT_NULL);
	}
	line = ft_strjoin(line, leftover);
	if (line == FT_NULL)
		return (ft_free(&buffer, &leftover, &line, "111"));
	if (ft_read_while(&line, &leftover, buffer, fd) == FT_NULL)
	{
		leftover = FT_NULL;
		return (FT_NULL);
	}
	if (ft_val_update(&line, &leftover, &buffer) == FT_NULL)
	{
		leftover = FT_NULL;
		return (FT_NULL);
	}
	ft_free(&buffer, &leftover, &line, "100");
	return (line);
}
