#include "get_next_line.h"
#include <stdio.h>

static int		ft_getline(char *str, char **line)
{
	char			*res;
	int				i;

	i = -1;
	while (str[++i] != '\n')
		;
	res = ft_strnew(i);
	ft_strncpy(res, str, i);
	*line = ft_strjoin(res, "");
	return (i);
}

int				get_next_line(int const fd, char **line)
{
	static char		*str;
	int				ret;
	char			buf[BUFF_SIZE + 1];
	int				i;
	
	if (str == 0)
		str = "";
	while (!(ft_strchr(str, '\n')))
	{
		if ((ret = read(fd, buf, BUFF_SIZE)) == -1)
			return (-1);
		buf[ret] = '\0';
		str = ft_strjoin(str, buf);
		if (ret == 0)
		{
			*line = ft_strjoin(str, "");
			return (1);
		}
	}
	i = ft_getline(str, line);
	str = ft_strjoin(&str[i+1], "");
	printf("\n\n%s\n", str);
	return (ret);
}