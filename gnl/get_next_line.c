#include "get_next_line.h"

static char	*checker(char *ans, char **stash)
{
	size_t	index;
	char	*holder;

	holder = ans;
	index = 0;
	while (ans[index] && ans[index] != '\n')
		index++;
	if (*stash)
		free(*stash);
	if (ans[index] == '\n' && ans[index + 1] != '\0')
		*stash = ft_strdup(ans + index + 1);
	else
		*stash = NULL;
	if (holder[index] == '\n')
		ans = ft_substr(holder, 0, index + 1);
	else
		ans = ft_substr(holder, 0, index);
	free(holder);
	return (ans);
}

static int	append(char *buf, char **ans)
{
	size_t	index;
	int		flag;
	char	*holder;

	holder = *ans;
	index = 0;
	flag = 0;
	while (buf[index])
	{
		if (buf[index] == '\n')
			flag = 1;
		index++;
	}
	*ans = ft_strjoin(holder, buf);
	free(holder);
	if (!(*ans))
	{
		return (-1);
	}
	if (flag)
		return (1);
	return (0);
}

static int	check_stash(char **stash, char **ans)
{
	size_t	index;
	char	*holder;

	if (!stash || !*stash)
		return (0);
	holder = *stash;
	index = 0;
	while (holder[index])
	{
		if (holder[index] == '\n')
		{
			*ans = ft_substr(holder, 0, index + 1);
			if (holder[index + 1] != '\0')
				*stash = ft_strdup(holder + index + 1);
			else
				*stash = NULL;
			free(holder);
			return (1);
		}
		index++;
	}
	*ans = ft_strdup(holder);
	free(holder);
	*stash = NULL;
	return (0);
}

char	*read_from_file(int fd, char **stash, char *ans)
{
	char	*temp;
	int		flag;

	temp = malloc(BUFFER_SIZE + 1);
	if (!temp)
		return (free_strings(stash, temp, ans));
	flag = read(fd, temp, BUFFER_SIZE);
	while (flag)
	{
		if (flag == -1)
			return (free_strings(stash, temp, ans));
		temp[flag] = '\0';
		if (append(temp, &ans) == 1)
		{
			free(temp);
			return (checker(ans, stash));
		}
		flag = read(fd, temp, BUFFER_SIZE);
	}
	free_strings(stash, temp, NULL);
	return (ans);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*ans;

	ans = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (check_stash(&stash, &ans))
		return (ans);
	ans = read_from_file(fd, &stash, ans);
	return (ans);
}
