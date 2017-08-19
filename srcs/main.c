/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 17:36:24 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/18 15:14:19 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int	main(void)
{
	int				error;//
	t_filler_var	v;

	v.is_first_loop = 1;
	error = 0;//
	if (!define_if_is_player_one(&v))
		return (0);
	while (1)
	{
		init_and_reset_t_filler_var(&v);
		if (!error && !get_current_map_and_token_from_standard_entry(&v))
		{
			DEB
			error = 1;
		}
		if (!error && !extract_token_lst_from_token_map(&v))
		{
			DEB
			error = 1;
		}
		if (!error && !find_solutions_through_algorithm(&v))
		{
			DEB
			error = 1;
		}
		if (error)
		{
			write(1, "0 0\n", 4);
			return (0);
		}
	}
	exit(0);
	return (0);
}
