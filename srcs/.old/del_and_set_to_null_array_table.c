/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_and_set_to_null_array_table.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 16:27:27 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/06 11:17:08 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	del_and_set_to_null_array_table(char ***array_table)
{
	int	i;

	i = 0;
	while ((*array_table)[i])
	{
		free((*array_table)[i]);
		i++;
	}
	free(*array_table);
	*array_table = NULL;
}
