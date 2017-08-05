/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_values_from_raw_to_var_filler_lst.c        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/29 17:13:09 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/05 21:07:20 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

static void	extract_dimensions(int *map_height, int *map_lenght, char *s,
			t_filler_raw **raw)
{
	while (!(*s >= '0' && *s <= '9'))
		s++;
	*map_height = ft_atoi(s);
	while (*s >= '0' && *s <= '9')
		s++;
	s++;
	*map_lenght = ft_atoi(s);
	*raw = (*raw)->next;
}

static char	*extract_map_line_from_raw_s(char *src, int map_lenght,
			int *is_plateau)
{
	char	*s;
	char	*ptr;

	while (*src >= '0' && *src <= '9')
		src++;
	if (*is_plateau)
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

static char	**extract_map(char **map, t_filler_tmp *tmp,
			t_filler_raw **raw)
{
	int		i;

	i = -1;
	if (!(map = (char**)malloc(sizeof(char*) * *(tmp->map_height) + 1)))
		return (0);
	while (++i < *(tmp->map_height))
	{
		if (!(map[i] = extract_map_line_from_raw_s((*raw)->s,
			*(tmp->map_lenght), &(tmp->is_plateau))))
			return (NULL);
		*raw = (*raw)->next;
	}
	map[i] = NULL;
	return (map);
}

int			extract_values_from_raw_to_var_filler_lst(t_filler_var *v,
			t_filler_raw *raw)
{
	t_filler_tmp	tmp;

	extract_dimensions(&v->plateau_height, &v->plateau_lenght, raw->s, &raw);
	tmp.map_height = &v->plateau_height;
	tmp.map_lenght = &v->plateau_lenght;
	tmp.is_plateau = 1;
	if (!(v->plateau = extract_map(v->plateau, &tmp, &raw)))
		return (0);
	tmp.is_plateau = 0;
	extract_dimensions(&v->token_map_height, &v->token_map_lenght, raw->s, &raw);
	tmp.map_height = &v->token_map_height;
	tmp.map_lenght = &v->token_map_lenght;
	if (!(v->token_map = extract_map(v->token_map, &tmp, &raw)))
		return (0);
	if (!(v->token_to_place = fill_token_to_place(v->token_map, v->token_to_place)))
		return (0);
	return (1);
}
