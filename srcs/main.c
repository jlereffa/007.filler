/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 17:36:24 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/11 17:09:13 by Nerhak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int	main(void)
{
	t_filler_var	v;

	v.is_game_over = 0;
	v.is_first_loop = 1;
	if (!define_if_is_player_one(&v))
		return (0);
	while (!v.is_game_over)
	{
		init_and_reset_t_filler_var(&v);
		if (!get_current_map_and_token_from_standard_entry(&v) ||
			!extract_token_lst_from_token_map(&v) ||
			!try_to_find_solutions_through_algorithm(&v))
			return (0);
		test_print(&v);
	}
	return (0);
}
