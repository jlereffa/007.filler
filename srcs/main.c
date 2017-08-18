/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 17:36:24 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/18 12:41:48 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int	main(void)
{
	t_filler_var	v;

	v.is_first_loop = 1;
	if (!define_if_is_player_one(&v))
		return (0);
	while (1)
	{
		init_and_reset_t_filler_var(&v);
		if (!get_current_map_and_token_from_standard_entry(&v) ||
			!extract_token_lst_from_token_map(&v) ||
			!find_solutions_through_algorithm(&v))
		{
			write(1, "0 0\n", 4);
			return (0);
		}
	}
	exit(0);
	return (0);
}
