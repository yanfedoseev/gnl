static char		*strjoin_free(char const *s1, char const *s2)
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

static int		getline(int const fd, char **line, char *str)
{
	char			*res;
	int				i;

	while (!(ft_strchr(str, '\n')))
	{
		buffsize = strread(fd, str);
		if (buffsize == 0 && str == 0)
			return (0);
	}
	i = 0;
	while (str[i] != '\n')
	{
		res[i] == str[i];
		i++;
	}
	res[i] = '\0';
	if (i = ft_strlen())
	*line = strjoin_free(res, "");
}

static int		strread(int const fd, char *str)
{
	char			buf[BUFF_SIZE + 1];
	int				ret;

	if ((ret = read(fd, buf, BUFF_SIZE)) == -1)
		return (-1);
	buf[ret] = '\0';
	*str = strjoin_free(*str, buf);
	return (ret);
}

int				get_next_line(int const fd, char **line)
{
	static char		*str;
	int				ret;
	int				buffsize;
	
	if (str == 0)
		str = "";
	getline(fd, *line, str);
	// если в str нет \n считываем дальше
		buffsize = strread(fd, str);
		if (buffsize == 0 && str == 0)
			return (0);
	return (0);
}