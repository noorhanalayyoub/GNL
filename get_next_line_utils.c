int	totlength(char *str1, char *str2)
{
	int	length;
	int	index;

	length = 0;
	index = 0;
	while (str1[index])
	{
		index++;
		length++;
	}
	index = 0;
	while (str2[index])
	{
		index++;
		length++;
	}
	return (length);
}

void	copystring(int length, char *str1, char *str2, char *joinedstring)
{
	int	index;
	int	j;

	j = 0;
	index = 0;
	while (str1[j])
	{
		joinedstring[index] = str1[j];
		j++;
		index++;
	}
	j = 0;
	while (index < length && str2[j])
	{
		joinedstring[index] = str2[j];
		j++;
		index++;
	}
	joinedstring[length] = '\0';
}

char	*ft_strjoin(char *str1, char *str2)
{
	int		length;
	char	*joinedstring;

	if (!str1 || !str2)
		return (NULL);
	length = totlength(str1, str2);
	joinedstring = malloc((length + 1));
	if (!joinedstring)
		return (NULL);
	if (length == 0)
	{
		joinedstring[0] = '\0';
		return (joinedstring);
	}
	copystring(length, str1, str2, joinedstring);
	return (joinedstring);
}

char	*ft_strdup(char const *str)
{
	int		index;
	char	*newstring;

	index = 0;
	newstring = malloc(ft_strlen(str) + 1);
	if (str[0] == '\0')
		*newstring = '\0';
	while (str[index])
	{
		newstring[index] = str[index];
		index++;
	}
	newstring[index] = '\0';
	return (newstring);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	i;

	if (!s)
		return (NULL);
	if (start > (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	new_str = (char *)malloc(len + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_str[i] = s[start + i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
