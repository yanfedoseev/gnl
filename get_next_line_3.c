#include "get_next_line.h"
#include <stdio.h>

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
	//free(s1);
	return (res);
}

static char		mystrchr(const char *s, int c)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == c)
			return ((char*)s);
		s++;
	}
	if (c == '\0')
		return ((char*)s);
	return (NULL);
}

static int		ft_getline(char **arr, int fd, char **line)
{
	char			*res;
	int				i;
	int				len;

	if (arr[fd] == NULL)
		return (0);
	len = ft_strlen(arr[fd]);

	i = 0;
	while (arr[fd][i] != '\n' || arr[fd][i + 1] != '\0')
		i++;
	if (arr[fd][i] != '\n' && arr[fd][i + 1] == '\0')
		return (0);
	if (!(res = ft_strnew(i)))
		return (0);
	ft_strncpy(res, arr[fd], i);
	if (!(*line = ft_strdup(res)))
	{
		free(res);
		return (0);
	}
	arr[fd] = ft_strdup(&arr[fd][i + 1]);
	free(res);
	return (1);
}

static int		myread(char **arr, int fd, char **line)
{
	int				bsize;
	char			buf[BUFF_SIZE + 1];

	while (1)
	{
		if (mystrchr(arr[fd], '\n'))
		{
			ft_getline(arr, fd, line);
			return (1);
		}
		bsize = read(fd, buf, BUFF_SIZE);
		if (bsize == -1)
			return (-1);
		if (bsize == 0)
		{
			printf("arrfd before check = %s\n", arr[fd]);
			if (ft_strcmp(arr[fd], ""))
				return (0);
			//printf("%d", arr[fd]);
			*line = ft_strdup(arr[fd]);
			printf("arrfd before free  = %s\n", arr[fd]);
			//ft_strdel(&arr[fd]);
			arr[fd] = ft_strdup("");
			printf("arrfd after free   = %s\n", arr[fd]);
			return (1);
		}
		if (arr[fd] == 0)
			arr[fd] = ft_strnew(0);
		buf[bsize] = '\0';
		arr[fd] = strjoin_free(arr[fd], buf);
	}
}

int				get_next_line(int const fd, char **line)
{
	static char		*arr[12000];
	int				ret;

	if (!line || fd < 0 || fd > 12000)
		return (-1);
	ret = myread(arr, fd, line);
	return (ret);
}