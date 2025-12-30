#include "get_next_line.h"

static char    *checker(char *ans, char **stash)
{
    size_t    index;
    char    *holder;

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

static int	append(char *buf, char **ans) // removed stash from here
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
        return (-1); // in case of error (we can use it once we check for errors later)
    }
	if (flag)
		return (1);
	return (0); // made it return a flag instead(cuz simpler)
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

static int check_stash(char **stash, char **ans)
{
    size_t  index;
    char    *holder;

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

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*ans;
	char		*temp;
	int			flag;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
    ans = NULL;
    if (check_stash(&stash, &ans))
    {
        return (ans);
    }
	temp = malloc(BUFFER_SIZE + 1);
	if (!temp)
		return (free_strings(&stash, temp, ans));
	flag = read(fd, temp, BUFFER_SIZE);
	while (flag)
	{
		if (flag == -1)
			return (free_strings(&stash, temp, ans));
		temp[flag] = '\0';
		if (append(temp, &ans) == 1)
		{
			free(temp);
			return (checker(ans, &stash));
		}
		flag = read(fd, temp, BUFFER_SIZE);
	}
    free_strings(&stash, temp, NULL); // Used the free function instead, sending ans as NULL cuz we don't wanna free
    return (ans);
}
