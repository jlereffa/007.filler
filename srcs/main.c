/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 17:12:17 by jlereffa          #+#    #+#             */
/*   Updated: 2017/07/30 14:55:26 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

#include <stdio.h>

int	main(void)
{
	int				fd;
	t_filler_raw	*raw;
	t_filler_var	v;

	if ((fd = open("trace", O_RDWR)) < 0)
		return (write(1, "fd error\n", 9));
	raw = get_raw_standard_input_to_raw_lst(fd);
	init_t_filler_var(&v);
	if (!(extract_values_from_raw_to_var(&v, raw)))
		return (0);
	del_raw(&raw);
	return (0);
}
