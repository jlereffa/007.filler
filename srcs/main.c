/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 17:12:17 by jlereffa          #+#    #+#             */
/*   Updated: 2017/07/31 18:14:25 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

#include <stdio.h>

int			main(void)
{
	int				fd;
	t_filler_raw	*raw;
	t_filler_var	v;

	if ((fd = open("trace", O_RDWR)) < 0)
		return (write(1, "fd error\n", 9));

	v.loop_nb = -1;
	v.is_1_player_game = 0;
	determine_ai_token(&v, fd);
	//while (1)
	//{
	deb_fd("0_0", fd);
	init_t_filler_var(&v);
	deb_fd("0_1", fd);
	raw = get_raw_standard_input_to_raw_lst(fd);
	deb_fd("0_2", fd);
	if (!(extract_values_from_raw_to_var(&v, raw)))
		return (0);
	deb_fd("0_3", fd);
	del_and_set_to_null_raw(&raw);
	deb_fd("0_4", fd);
	if (!(v.t_piece = fill_t_piece(v.piece, v.t_piece)))
		return (0);
	deb_fd("0_5", fd);
	write(fd, "X Y\n", ft_strlen("X Y\n"));
	//}
	return (0);
}
