/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaissne <tmaissne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 14:42:49 by tmaissne          #+#    #+#             */
/*   Updated: 2026/11/19 15:23:02 by tmaissne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char *ft_read(int fd, char *stach, ssize_t size)
{
	char	*tmp;
	char	*str;

	str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (ft_strchr(stach, '\n') == 0 && size != 0)
	{
		size = read(fd, str, BUFFER_SIZE);
		if (size == -1)
		{
			free(stach);
			free(str);
			return (NULL);
		}
		str[size] = '\0';
		tmp = ft_strjoin(stach, str);
		free (stach);
		stach = tmp;
	}
	free(str);
	return(stach);
}
static char	*fill_lines(int fd, char *stach)
{
	ssize_t	size;

	size = 1;
	if (!stach)
	{
		stach = malloc(sizeof(char) * 1);
		stach[0] = '\0';
	}
	stach = ft_read(fd, stach, size);
	return(stach);
}

void	ft_separate_lines(char *stach, char **line, char **temp)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(stach[i] && stach[i] != '\n')
		i++;
	while(stach[j])
		j++;
	if (j != 0)
	{
		*line = ft_substr(stach, 0, i + 1);
		*temp = ft_substr(stach, i + 1, j);
	}
}
char *get_next_line(int fd)
{
	char		*line;
	char		*temp;
	static char *stach;

	line = NULL;
	temp = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stach = fill_lines(fd, stach);
	if (!stach)
		return (NULL);
	ft_separate_lines(stach, &line, &temp);
	free(stach);
	stach = temp;
	return(line);
}

