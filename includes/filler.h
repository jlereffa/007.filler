/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 17:37:14 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/10 21:56:57 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <libft.h>

typedef struct s_filler_var	t_filler_var;
struct		s_filler_var
{
	int		is_player_one;
	int		is_game_over;
	char	**map;
	int		map_height;
	int		map_lenght;
	char	**token_map;
	int		token_map_height;
	int		token_map_lenght;
};

//[DEBUG]
# define FD 2
# define DEB de(__FILE__, __LINE__);

void		de(char *file, int line);
void		putf(char *s);
void		test_print(t_filler_var *v);
//[/DEBUG]

/*
**	Initialization Functions
*/

int			define_if_is_player_one(t_filler_var *v);

/*
**	Core Functions
*/

int			get_current_map_and_token_from_standard_entry(t_filler_var *v);
int			get_current_map_dimensions_and_jump_useless_line(t_filler_var *v);
int			get_current_map(t_filler_var *v);
int			get_current_token_map_dimensions(t_filler_var *v);
int			get_current_token_map(t_filler_var *v);

/*
**	Deletion Functions
*/

void		del_and_set_to_null_array_table(char ***array_table);

#endif
