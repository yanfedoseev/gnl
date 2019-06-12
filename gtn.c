/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leha.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 17:14:09 by gmarin            #+#    #+#             */
/*   Updated: 2019/06/12 17:20:56 by gmarin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char			*strjoin_free(char *s1, char *s2)
{
	char			*res;
	size_t			i;
	size_t			j;

	if (!s1 || !s2)
		return (NULL);
	if (!(res = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i])
		res[i] = s1[i];
	while (s2[j])
		res[i++] = s2[j++];
	//free(s1);
	return (res);
}

static int			ft_getline(char *str, char **line)
{
	char			*res;
	int				i;

	i = -1;
	while (str[++i] != '\n')
		;
	if (!(res = ft_strnew(i)))
		return (-1);
	ft_strncpy(res, str, i);
	if (!(*line = ft_strdup(res)))
	{
		free(res);
		return (-1);
	}
	free(res);
	return (i);
}

int					get_next_line(int const fd, char **line)
{
	static char		*arr[12000];
	int				bsize;
	char			*tmp;
	char			buf[BUFF_SIZE + 1];
	int				i;

	if (!line || fd < 0 || fd > 12000)
		return (-1);
	if (arr[fd] == 0)
	{
		arr[fd] = ft_strnew(0);
		printf("OOOOOOOOOOOOOOOOOOOOOOOOOOO\n");
	}
	printf("\n\narr[fd] = %s ||||||||||||||||||||\n", arr[fd]);
	while ((bsize = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[bsize] = '\0';
		arr[fd] = strjoin_free(arr[fd], buf);
		if (ft_strchr(arr[fd], '\n'))
		{
			i = ft_getline(arr[fd], line);
			arr[fd] = ft_strdup(&arr[fd][i + 1]);
			return (1);
		}
	}
	if (bsize == -1)
		return (-1);
	if (ft_strchr(arr[fd], '\n'))
	{
		i = ft_getline(arr[fd], line);
		arr[fd] = ft_strdup(&arr[fd][i + 1]);
		return (1);
	}
	printf("\n\nstrlen = %i\n\n", (int)ft_strlen(arr[fd]));
	if ((int)ft_strlen(arr[fd]) == 0)
		return (0);
	*line = ft_strdup(arr[fd]);
	//printf("OOOOOOOOOOOOOOOOOOOOOOOOOOO\n");
	//ft_strdel(&arr[fd]);
	free(arr[fd]);
	return (1);
}
