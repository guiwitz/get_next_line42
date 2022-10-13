/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aissatakane <aissatakane@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:28:25 by aissatakane       #+#    #+#             */
/*   Updated: 2022/10/13 12:41:25 by aissatakane      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
			return (NULL);
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
		return (NULL);
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
	j = 0;
	if (!str || len == 0)
		return (NULL);
	if (ft_strlen(str) == i)
	{
		free (str);
		return (NULL);
	}
	res = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!res)
	{
		free (res);
		return (NULL);
	}
	while (res && str[i])
		res[j++] = str[i++];
	res[j] = '\0';
	free(str);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*str[1024];
	char		*line;
	char		*buffer;

	line = NULL;
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer || BUFFER_SIZE <= 0 || fd < 0)
	{
		free (buffer);
		return (NULL);
	}
	str[fd] = get_str(fd, str[fd], buffer);
	if (!str[fd])
		return (NULL);
	line = get_line(str[fd]);
	str[fd] = get_newstr(str[fd], ft_strlen(line));
	if (!line)
		return (NULL);
	return (line);
}
