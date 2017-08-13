/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_current_map_and_token_from_standard_entry.c    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 19:42:23 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/13 12:44:00 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int	get_current_map_and_token_from_standard_entry(t_filler_var *v)
{
	int	ret;//tmp

	ret = 1;
	//DEB
	if (!get_current_map_dimensions_and_jump_useless_line(v))
	{
	//	DEB
		ret = 0;
		sleep(3);
	}
	if (ret && !get_current_map(v))
	{
		//DEB
		ret = 0;
		sleep(3);
	}
	if (ret && !get_current_token_map_dimensions(v))
	{
	//	DEB
		ret = 0;
		sleep(3);
	}
	if (ret && !get_current_token_map(v))
	{
	//	DEB
		ret = 0;
		sleep(3);
	}
	if (!ret)
		return (0);
//	DEB
	return (1);
}
