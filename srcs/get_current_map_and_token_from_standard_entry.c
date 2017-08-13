/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_current_map_and_token_from_standard_entry.c    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 19:42:23 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/13 14:12:33 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int	get_current_map_and_token_from_standard_entry(t_filler_var *v)
{
	int	ret;//tmp
	int	i;//

	ret = 1;
	//DEB
	if (!get_current_map_dimensions_and_jump_useless_line(v))
	{
		DEB
		ret = 0;
		//sleep(3);
	}
	if (ret && !get_current_map(v))
	{
		DEB
		ret = 0;
		//sleep(3);
	}
	if (ret && !get_current_token_map_dimensions(v))
	{
		DEB
		ret = 0;
	//	sleep(3);
	}
	if (ret && !get_current_token_map(v))
	{
		DEB
		ret = 0;
	//	sleep(3);
	}
	if (!ret)
		return (0);
	i = -1;
	sleep(2);
	while (v->map[++i])
	{
		putf(v->map[i]);
		putf("\n");
	}
	sleep(2);
//	DEB
	return (1);
}
