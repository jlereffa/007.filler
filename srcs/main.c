/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 17:12:17 by jlereffa          #+#    #+#             */
/*   Updated: 2017/07/29 17:01:18 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

#include <stdio.h>

int	main(void)
{
	int				fd;
	t_filler_raw	*raw;
	t_filler_var	var;

	if ((fd = open("trace", O_RDWR)) < 0)
		return (write(1, "fd error\n", 9));
	raw = get_raw_standard_input_to_raw_lst(fd);
	init_t_filler_var(&var);
	return (0);
}
