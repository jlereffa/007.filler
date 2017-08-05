/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 17:13:16 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/05 17:38:59 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

//
#include <fcntl.h>
//

#include <libft.h>
#include <unistd.h>

# define E_COORD_X v->enemy_token_to_chase_coord_x
# define E_COORD_Y v->enemy_token_to_chase_coord_y

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
	int				loop_nb;
	char			**plateau;
	int				plateau_height;
	int				plateau_lenght;
	char			**piece;
	int				piece_height;
	int				piece_lenght;
	t_filler_piece	*t_piece;
	char			player_token;//
	char			enemy_token;//
	char			enemy_token_to_chase;//
	int				enemy_token_is_found;
	int				enemy_token_to_chase_coord_x;
	int				enemy_token_to_chase_coord_y;
	int				is_1_player_game;//
};

void				deb_e(char *s);//<= TO DEL

int					determine_ai_token(t_filler_var *v);
int					determine_and_give_answer(t_filler_var *v);

void				init_t_filler_var(t_filler_var *v);

t_filler_raw		*get_raw_standard_input_to_raw_lst();
int					extract_values_from_raw_to_var(t_filler_var *v,
					t_filler_raw *raw);
t_filler_piece		*fill_t_piece(char **piece, t_filler_piece *t_piece);

void				del_and_set_to_null_raw(t_filler_raw **raw);
void				del_and_set_to_null_map(char ***map);
void				del_and_set_to_null_t_piece(t_filler_piece **t_piece);

#endif
