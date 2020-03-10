/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcobaled <jcobaled@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 19:20:23 by jcobaled          #+#    #+#             */
/*   Updated: 2020/03/08 19:25:32 by jcobaled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int fd;
	char *line;
	int	i;

	fd = open("test", O_RDONLY);
	i = 0;
	while (get_next_line(fd, &line))
	{
		printf("%di%s\n", i, line);
		free(line);
		line = NULL;
		i++;
	}
	system("leaks a.out");
	return (0);

}
