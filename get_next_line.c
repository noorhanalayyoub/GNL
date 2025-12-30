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
	if (ans[index] && ans[index] == '\n')
		*stash = ft_strdup(ans + index + 1);
	else
		*stash = NULL;
	ans = ft_substr(holder, 0, index + 1);
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
	if (!(*ans))
	{
		return (-1);
	}
	free(holder);
	if (flag)
		return (1);
	return (0);
}

static void	*free_strings(char **stash, char *buf, char *ans)
{
	if (stash && *stash)
	{
		free(*stash);
		*stash = NULL;
	}
	if (buf)
		free(buf);
	if (ans)
	{
		free(ans);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*ans;
	char		*temp;
	int		flag;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	ans = NULL;
	temp = malloc(BUFFER_SIZE + 1);
	if (!temp)
		return (free_strings(&stash, temp, ans));
	flag = read(fd, temp, BUFFER_SIZE);

	while (flag)
	{
		if (flag == -1)
			return (free_strings(&stash, temp, ans));
		temp[flag] = '\0';
		if (append(temp, &ans))
		{
			free(temp);
			return (checker(ans, &stash));
		}
		flag = read(fd, temp, BUFFER_SIZE);
	}
	free_strings(&stash, temp, NULL); return (ans);
}
