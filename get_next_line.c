/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaissne <tmaissne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 14:59:19 by tmaissne          #+#    #+#             */
/*   Updated: 2026/11/13 17:02:26 by tmaissne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char	*get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*str;

	buffer[BUFFER_SIZE] = '\0';
	read(fd, buffer, BUFFER_SIZE);
	str = buffer;
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
