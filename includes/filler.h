/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 17:13:16 by jlereffa          #+#    #+#             */
/*   Updated: 2017/07/30 17:21:07 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

//
#include <fcntl.h>
//

#include <libft.h>
#include <unistd.h>

typedef struct s_filler_tmp t_filler_tmp;
struct 				s_filler_tmp
{
	int				*map_height;
	int				*map_lenght;
	int				is_plateau;
};

typedef struct s_filler_raw t_filler_raw;
struct 				s_filler_raw
{
	char			*s;
	t_filler_raw	*prev;
	t_filler_raw	*next;
};

typedef struct s_filler_piece t_filler_piece;
struct 				s_filler_piece
{
	int				x;
	int				y;
	t_filler_piece	*prev;
	t_filler_piece	*next;
};

typedef struct s_filler_var t_filler_var;
struct 				s_filler_var
{
	char			**plateau;
	int				plateau_height;
	int				plateau_lenght;
	char			**piece;
	int				piece_height;
	int				piece_lenght;
	t_filler_piece	*t_piece;
	char			player_token;
	char			player_token_to_overwrite;
	char			ennemy_token;
	char			ennemy_token_to_overwrite;
};

t_filler_raw		*get_raw_standard_input_to_raw_lst(int fd);

void				init_t_filler_var(t_filler_var *v);

int					extract_values_from_raw_to_var(t_filler_var *v,
					t_filler_raw *raw);

void				del_raw(t_filler_raw **raw);

t_filler_piece		*fill_t_piece(char **piece, t_filler_piece *t_piece);

#endif
