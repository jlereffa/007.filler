/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_values_from_raw_to_var.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/29 17:13:09 by jlereffa          #+#    #+#             */
/*   Updated: 2017/07/29 17:49:47 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

static void	extract_dimensions(int *height, int *lenght, char *s)
{
	while (!(*s >= '0' && *s <= '9'))
		s++;
	*height = ft_atoi(s);
	while (*s >= '0' && *s <= '9')
		s++;
	s++;
	*lenght = ft_atoi(s);
	ft_putnbr_fd(*height, 3);
	write(3, "\n", 1);
	ft_putnbr_fd(*lenght, 3);
	write(3, "\n", 1);
}

static char	*extract_map_line_from_raw_s(char *src, int map_lenght)
{
	char	*s;
	char	*ptr;

	while (*src >= '0' && *src <= '9')
		src++;
	src++;
	if (!(s = (char*)malloc(sizeof(char) * map_lenght + 1)))
		return (0);
	ptr = s;
	while (*src)
	{
		*s = *src;
		s++;
		src++;
	}
	*s = '\0';
	return (ptr);
}

static int	extract_plateau(char **map, int map_height, int map_lenght,
			t_filler_raw **raw)
{
	int		i;

	i = -1;
	*raw = *raw->next;
	if (!(map = (char**)malloc(sizeof(char*) * map_height + 1)))
		return (0);
	while (++i < map_height)
	{
		if (!(map[i] = extract_map_line_from_raw_s(*raw->s, map_lenght)))
			return (0);
		*raw = *raw->next;
	}
	map[i] = NULL;
	i = -1;
	while (++i < map_height)
	{
		write(3, map[i], ft_strlen(map[i]));
		write(3, "\n", 1);
	}
	return (1);
}

int	extract_values_from_raw_to_var(t_filler_var *v, t_filler_raw *raw)
{
	extract_dimensions(&v->map_height, &v->map_lenght, raw->s);
	if (!(extract_plateau(v->map, v->map_height, v->map_lenght, &raw)))
		return (0);
	extract_dimensions(&v->piece_height, &v->piece_lenght, raw->s);
	return (1);
}
