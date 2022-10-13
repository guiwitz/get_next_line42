/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akane <akane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:29:09 by aissatakane       #+#    #+#             */
/*   Updated: 2022/10/13 17:14:12 by akane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_nl(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_str(int fd, char *str, char *buffer)
{
	int	len;

	len = 0;
	if (!check_nl(str))
		len = read(fd, buffer, BUFFER_SIZE);
	while (!check_nl(str) && len != 0)
	{
		if (len == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[len] = 0;
		str = ft_strjoin(str, buffer);
		if (check_nl(str))
			break ;
		if (!str)
		{
			free(buffer);
			return (NULL);
		}
		len = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (str);
}

char	*get_line(char *str)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	res = malloc(sizeof(char) * (i + 2));
	if (!res)
	{
		free(res);
		return (NULL);
	}
	while (i >= 0)
	{
		res[j] = str[j];
		j++;
		i--;
	}
	res[j] = '\0';
	return (res);
}

char	*get_newstr(char *str, size_t len)
{
	size_t	i;
	size_t	j;
	char	*res;

	i = len;
	j = ft_strlen(str);
	if (!str || len == 0)
		return (NULL);
	if (j == i)
	{
		free (str);
		return (NULL);
	}
	res = malloc(sizeof(char) * (j - i + 1));
	if (!res)
	{
		free (res);
		return (NULL);
	}
	j = 0;
	while (res && str[i])
		res[j++] = str[i++];
	res[j] = '\0';
	free(str);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*str = NULL;
	char		*line;
	char		*buffer;

	line = NULL;
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer || BUFFER_SIZE <= 0 || fd < 0)
	{
		free (buffer);
		return (NULL);
	}
	str = get_str(fd, str, buffer);
	if (!str)
		return (NULL);
	line = get_line(str);
	str = get_newstr(str, ft_strlen(line));
	if (!line)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
