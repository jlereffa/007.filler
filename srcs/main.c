/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 17:12:17 by jlereffa          #+#    #+#             */
/*   Updated: 2017/07/29 14:58:25 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

#include <stdio.h>

int	main(void)
{
	char	*line;
	int		fd;

	line = NULL;
	fd = open("trace", O_RDWR);
	printf("fd : {%d}\n", fd);
	while (get_next_line(0, &line))
	{
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
	}
	return (0);
}
