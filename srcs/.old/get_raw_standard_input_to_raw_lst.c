/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_raw_standard_input_to_raw_lst.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/29 15:13:39 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/06 09:41:07 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

static int		get_loop_nb(char *s)
{
	while (*s && *s != ' ')
		s++;
	s++;
	return (ft_atoi(s));
}

static int		handle_x_loop(int loop_nb, t_filler_raw **raw)
{
	char	*line;
	int		i;

	i = 0;
	while (i < loop_nb)
	{
		if ((get_next_line(0, &line) == -1))
			return (0);
		if (!(*raw = set_t_filler_raw(*raw, line)))
			return (0);
		i++;
	}
	return (1);
}

t_filler_raw	*get_raw_standard_input_to_raw_lst(void)
{
	char			*line;
	int				loop_nb;
	t_filler_raw	*raw;
	t_filler_raw	*tmp;//TO DELL

	raw = NULL;
	if ((get_next_line(0, &line) == -1))
		return (NULL);
	loop_nb = get_loop_nb(line);
	if (!(raw = set_t_filler_raw(raw, line)))
		return (NULL);
	if ((get_next_line(0, &line) == -1))
		return (NULL);
	free(line);
	handle_x_loop(loop_nb, &raw);
	if ((get_next_line(0, &line) == -1))
		return (NULL);
	if (!(raw = set_t_filler_raw(raw, line)))
		return (NULL);
	loop_nb = get_loop_nb(line);
	handle_x_loop(loop_nb, &raw);
	while (raw->prev)
		raw = raw->prev;
	tmp = raw;//TO DELL
	while (tmp)//TO DELL
	{
		ft_putendl_fd(tmp->s, 2);
		tmp = tmp->next;
	}
	return (raw);
}
