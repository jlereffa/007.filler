/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_and_set_to_null_map.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 16:27:27 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/02 14:52:52 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	del_and_set_to_null_map(char ***map)
{
	int	i;

	i = 0;
	while (*(map[i]))
	{
		free(*(map[i]));
		i++;
	}
	free(*map);
	*map = NULL;
}
