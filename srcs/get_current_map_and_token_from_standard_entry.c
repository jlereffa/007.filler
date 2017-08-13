/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_current_map_and_token_from_standard_entry.c    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 19:42:23 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/13 11:19:22 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int	get_current_map_and_token_from_standard_entry(t_filler_var *v)
{
	if (!get_current_map_dimensions_and_jump_useless_line(v) ||
		!(get_current_map(v)) ||
		!(get_current_token_map_dimensions(v)) ||
		!(get_current_token_map(v)))
		return (0);
	return (1);
}
