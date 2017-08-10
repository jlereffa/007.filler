/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 17:37:14 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/10 19:40:42 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <libft.h>

//DEBUG
# include <stdio.h>

# define FD 2
# define DEB de(__FILE__, __LINE__);

void		de(char *line, int line);
//

typedef struct s_filler_var	t_filler_var;
struct		s_filler_var
{
	int		is_player_one;
	int		is_game_over;
	char	**map;
};

/*
**	Initialization Functions
*/

int			define_if_is_player_one(t_filler_var *v);

/*
**	Core Functions
*/



/*
**	Deletion Functions
*/

void		del_and_set_to_null_array_table(char ***array_table);

#endif
