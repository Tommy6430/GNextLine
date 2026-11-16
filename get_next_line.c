/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaissne <tmaissne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 14:59:19 by tmaissne          #+#    #+#             */
/*   Updated: 2026/11/16 19:24:59 by tmaissne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

static char	*fillstr(char *buffer, char *str, int fd)
{
	int	i;

	i = 0;
	read(fd, buffer, BUFFER_SIZE);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	str = ft_substr(buffer, 0, i);
	while (ft_strchr(str, '\n') == 0)
	{
		read(fd, buffer, BUFFER_SIZE);
		str = ft_strjoin(str, buffer);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*str;
	static char	*stack = NULL;
	int			k;
	int			i;

	i = 0;
	str = NULL;
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	str = fillstr(buffer, str, fd);
	if (ft_strchr(str, '\n') != 0)
	{
		k = ft_strchr(str, '\n');
		stack = malloc(sizeof(char) * BUFFER_SIZE + 1);
		while (str[k])
		{
			stack[i] = str[k];
			i++;
			k++;
		}
	}
	if (stack != NULL)
		str = ft_substr(str, 0, (ft_strlen(str) - i));
	return (str);
}

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("txt.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("%s", str);
}
