#include "get_next_line.h"

static char		*strjoin_free(char *s1, char *s2)
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
	free(s1);
	return (res);
}

static int		ft_getline(char **arr, int fd, char **line)
{
	char			*res;
	int				i;

	if (!(ft_strchr(arr[fd], '\n')))
		return (0);
	i = -1;
	while (arr[fd][++i] != '\n')
		;
	if (!(res = ft_strnew(i)))
		return (-1);
	ft_strncpy(res, arr[fd], i);
	if (!(*line = ft_strdup(res)))
	{
		free(res);
		return (-1);
	}
	arr[fd] = ft_strdup(&arr[fd][i + 1]);
	free(res);
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	static char		*arr[12000];
	int				bsize;
	char			buf[BUFF_SIZE + 1];

	if (!line || fd < 0 || fd > 12000)
		return (-1);
	while ((bsize = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[bsize] = '\0';
		if (arr[fd] == 0)
			arr[fd] = ft_strnew(0);
		arr[fd] = strjoin_free(arr[fd], buf);
		if (ft_getline(arr, fd, line))
			return (1);
	}
	if (bsize == -1)
		return (-1);
	//if (!ft_strlen(arr[fd]))
	//	return (0);
	if (!arr[fd][0])
		return (0);
	if (ft_getline(arr, fd, line))
		return (1);
	*line = ft_strdup(arr[fd]);
	free(arr[fd]);
	return (1);
}