/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcobaled <jcobaled@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 14:51:50 by jcobaled          #+#    #+#             */
/*   Updated: 2020/03/08 14:53:09 by jcobaled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int	i;

	i = 0;
	if (!dst || !src)
		return (0);
	while (src[i] != '\0')
		i++;
	while (dstsize > 1 && *src != '\0')
	{
		*dst = *src;
		dst++;
		src++;
		dstsize--;
	}
	if (dstsize != 0)
		*dst = '\0';
	return (i);
}

static size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t d;
	size_t s;
	size_t result;

	result = 0;
	d = 0;
	s = 0;
	while (dst[d] != '\0')
		d++;
	while (src[s] != '\0')
		s++;
	dst = dst + d;
	if (d <= dstsize)
		result = s + d;
	else
		return (dstsize + s);
	while (d + 1 < dstsize && *src != '\0')
	{
		*dst = *src;
		src++;
		dst++;
		d++;
	}
	*dst = '\0';
	return (result);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	int		cont;
	int		i;
	char	*ptr;

	i = 0;
	cont = 0;
	if (!s1 || !s2)
		return (NULL);
	while (s1[cont] != '\0')
		cont++;
	while (s2[i] != '\0')
	{
		cont++;
		i++;
	}
	if (!(ptr = malloc(cont + 1)))
		return (NULL);
	ft_strlcpy(ptr, s1, cont + 1);
	ft_strlcat(ptr, s2, cont + 1);
	free((void *)s1);
	return (ptr);
}

char			*ft_strdup(const char *s1)
{
	int		cont;
	int		i;
	char	*ptr;

	i = 0;
	cont = 0;
	while (s1[cont] != '\0')
		cont++;
	if (!(ptr = malloc(cont + 1)))
		return (NULL);
	while (cont > 0 && *s1 != '\0')
	{
		ptr[i] = *s1;
		i++;
		cont--;
		s1++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char			*ft_substr(char const *s, size_t len)
{
	char	*ptr;

	if (!(ptr = malloc(len + 1)))
		return (NULL);
	ft_strlcpy(ptr, s, len + 1);
	return (ptr);
}
