/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaissne <tmaissne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 14:42:49 by tmaissne          #+#    #+#             */
/*   Updated: 2026/11/18 19:34:34 by tmaissne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>


char	*fillfirstlign(int fd, char *stach)
{
	char	*str;
	char	*tmp;
	ssize_t	size;

	size = 0;
	if (!stach)
		stach = calloc(sizeof(char), BUFFER_SIZE);
	str = malloc(sizeof(char) * BUFFER_SIZE + 1);
	while (ft_strchr(stach, '\n') == 0)
	{
		size = read(fd, str, BUFFER_SIZE);
		str[size] = '\0';
		if (size == 0 && stach[0] == '\0')
		{
			free(stach);
			free(str);
			return (NULL);
		}
		tmp = ft_strjoin(stach, str);
		free (stach);
		stach = tmp;
	}
	free(str);
	return(stach);
}

char *get_next_line(int fd)
{
	char		*lign;
	char		*temp;
	static char *stach;
	int			i;
	int			j;

	i = 0;
	j = 0;
	lign = NULL;
	temp = NULL;
	stach = fillfirstlign(fd, stach);
	if (!stach)
		return (NULL);
	while(stach[i] && stach[i] != '\n')
		i++;
	while(stach[j])
		j++;
	if (j != 0)
	{
		lign = ft_substr(stach, 0, i + 1);
		temp = ft_substr(stach, i + 1, j);
	}
	free(stach);
	stach = temp;
	return(lign);
}

#include "get_next_line.h"
#include <stdio.h>

int    main(void)
{
    int        fd;
    char    *ligne;

    ligne = NULL;
    fd = open("txt.txt", O_RDONLY);
    while ((ligne = get_next_line(fd)) != NULL)
    {
        printf("%s", ligne);
        free(ligne);
    }
    close(fd);
}
