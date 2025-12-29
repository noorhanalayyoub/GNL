static char	*checker(char *ans, char *stash)
{
	size_t	index;
	char	*holder;

	holder = ans;
	index = 0;
	while (ans[index] && ans[index] != '\n')
		index++;
	stash = ft_strdup(ans + index);
	ans = ft_substr(holder, 0, index + 1);
	free(holder);
	return (ans);
}

static char	*append(char *buf, char *ans, char *stash)
{
	size_t	index;
	int		flag;
	char	*holder;

	holder = ans;
	index = 0;
	flag = 0;
	while (buf[index])
	{
		if (buf[index] == '\n')
			flag = 1;
		index++;
	}
	ans = ft_strjoin(buf, holder);
	free(holder);
	if (flag)
		return (checker(ans, stash));
	return (NULL);
}

static void	*free_strings(char *str1, char *str2, char *str3)
{
	free(str1);
	free(str2);
	free(str3);
	return (NULL);
}

st char	*get_next_line(int fd)
{
	static char	*stash;
	char		*ans;
	char		*temp;
	int			flag;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	temp = malloc(BUFFER_SIZE + 1);
	if (!temp)
		return (free_strings(stash, ans, temp));
	ans = NULL;
	flag = read(fd, temp, BUFFER_SIZE);
	while (flag)
	{
		if (flag == -1)
			return (free_strings(stash, ans, temp));
		temp[flag] = '\0';
		if (append(temp, ans))
		{
			free(temp);
			return (ans);
		}
		flag = read(fd, temp, BUFFER_SIZE);
	}
	free(stash);
	free(temp);
	return (ans);
}
