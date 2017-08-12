/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_and_set_to_null_int_array_table.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 16:27:27 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/12 13:48:54 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	del_and_set_to_null_int_array_table(int ***tab, int i_max)
{
	int	i;

	i = 0;
	while (i < i_max)
	{
		free((*tab)[i]);
		i++;
	}
	*tab = NULL;
}
