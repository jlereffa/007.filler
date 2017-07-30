/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_raw_standard_input_to_raw_lst.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/29 15:13:39 by jlereffa          #+#    #+#             */
/*   Updated: 2017/07/30 17:20:57 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

static int			find_s_into_other_s(char *s1, char *s2)
{
	if (!s1 || !s2)
		return (0);
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (0);
		s1++;
		s2++;
	}
	return (1);
}

static t_filler_raw	*handle_raw_lst(t_filler_raw *raw, char *content)
{
	if (!raw)
	{
		if (!(raw = (t_filler_raw*)malloc(sizeof(t_filler_raw))))
			return (NULL);
		raw->s = content;
		raw->prev = NULL;
		raw->next = NULL;
		return (raw);
	}
	while (raw->next)
		raw = raw->next;
	if (!(raw->next = handle_raw_lst(raw->next, content)))
		return (NULL);
	raw->next->prev = raw;
	raw = raw->next;
	return (raw);
}

t_filler_raw		*get_raw_standard_input_to_raw_lst(int fd)
{
	char			*line;
	t_filler_raw	*raw;

	line = NULL;
	raw = NULL;
	while (!find_s_into_other_s(line, "Plateau"))
		get_next_line(0, &line);
	raw = handle_raw_lst(raw, line);
	get_next_line(0, &line);
	while (get_next_line(0, &line))
	{
		raw = handle_raw_lst(raw, line);
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
	}
	while (raw->prev)
		raw = raw->prev;
	while (raw->next)
	{
		write(fd, "raw->content : {", 16);
		write(fd, raw->s, ft_strlen(raw->s));
		write(fd, "}\n", 2);
		raw = raw->next;
	}
	write(fd, "raw->content : {", 16);
	write(fd, raw->s, ft_strlen(raw->s));
	write(fd, "}\n", 2);
	while (raw->prev)
		raw = raw->prev;
	return (raw);
}
