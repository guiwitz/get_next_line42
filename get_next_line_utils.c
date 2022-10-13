/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aissatakane <aissatakane@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:29:01 by aissatakane       #+#    #+#             */
/*   Updated: 2022/10/13 12:29:02 by aissatakane      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	size_t	size;
	int		i;
	char	*res;

	size = ft_strlen(s);
	i = 0;
	if (!s || size == 0)
		return (NULL);
	res = malloc(sizeof(char) * size + 1);
	if (!res)
	{
		free(res);
		return (NULL);
	}
	else
	{
		while (size > 0)
		{
			res[i] = s[i];
			i++;
			size --;
		}
		res[i] = '\0';
	}
	return (res);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*re;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s2 && s1)
		return (s1);
	else if (!s1 && s2)
		return (ft_strdup(s2));
	re = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!re || ((ft_strlen(s1) + ft_strlen(s2)) == 0))
	{
		free(re);
		return (NULL);
	}
	while (s1[j])
		re[i++] = s1[j++];
	j = 0;
	while (s2[j])
		re[i++] = s2[j++];
	re[i] = '\0';
	free(s1);
	return (re);
}

