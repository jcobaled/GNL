/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcobaled <jcobaled@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 13:11:35 by jcobaled          #+#    #+#             */
/*   Updated: 2020/03/08 14:49:57 by jcobaled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_delete(char *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
	return (ptr);
}

static char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return ((char*)s);
		else
			s++;
	}
	if (*s == c)
		return ((char*)s);
	else
		return (NULL);
}

static int	ft_blanked(int ret, char **line)
{
	if (ret < 0)
		return (-1);
	*line = ft_strdup("");
	return (0);
}

static char	*ft_checkline(char *remain, char **line, int *ret)
{
	int		i;
	char	*change;

	i = 0;
	while (remain[i] != '\n' && remain[i] != '\0')
		i++;
	if (remain[i] == '\n')
	{
		*line = ft_substr(remain, i);
		change = ft_strdup(remain + (i + 1));
		free(remain);
		remain = change;
		if (remain[0] == '\0')
			remain = ft_delete(remain);
		*ret = 1;
	}
	else
	{
		*line = ft_strdup(remain);
		free(remain);
		remain = NULL;
		*ret = 0;
	}
	return (remain);
}

int			get_next_line(int fd, char **line)
{
	char		*buffer;
	int			ret;
	static char	*remain[4096];

	if (fd < 0 || line == NULL || BUFFER_SIZE < 1)
		return (-1);
	if (!(buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((ret = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		if (remain[fd] == NULL)
			remain[fd] = ft_strdup(buffer);
		else
			remain[fd] = ft_strjoin(remain[fd], buffer);
		if (ft_strchr(remain[fd], '\n'))
			break ;
	}
	free(buffer);
	if ((ret < 0) || (ret == 0 && remain[fd] == NULL))
		return (ft_blanked(ret, line));
	remain[fd] = ft_checkline(remain[fd], line, &ret);
	return (ret);
}
