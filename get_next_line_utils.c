/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaissne <tmaissne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 15:48:11 by tmaissne          #+#    #+#             */
/*   Updated: 2026/11/18 17:23:09 by tmaissne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	getreallen(size_t slen, unsigned int start, size_t len)
{
	if (start >= slen)
		return (0);
	if (len < slen - start)
		return (len);
	return (slen - start);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	reallen;
	char	*str;

	if (!s)
		return (NULL);
	i = 0;
	reallen = getreallen(ft_strlen((char *)s), start, len);
	str = malloc(sizeof(char) * (reallen + 1));
	if (!str)
		return (NULL);
	while (i < reallen)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while(str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}
int	ft_strchr(char *s, int c)
{
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(s);
	while (i < j + 1)
	{
		if (s[i] == (char)c)
		{
			return (i);
		}
		i++;
	}
	return (0);
}
