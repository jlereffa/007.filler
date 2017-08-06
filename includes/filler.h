/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 17:13:16 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/06 11:10:01 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

//
#include <fcntl.h>
# define DEB deb_i(__FILE__, __LINE__);
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

typedef struct s_filler_token t_filler_token;
struct 				s_filler_token
{
	int				x;
	int				y;
	t_filler_token	*prev;
	t_filler_token	*next;
};

typedef struct s_filler_var t_filler_var;
struct 				s_filler_var
{
	int				loop_nb;//Init first then ++ [OK]
	char			**plateau;//NULL first turn then reset [OK]
	int				plateau_height;//0 every turn [OK]
	int				plateau_lenght;//0 every turn [OK]
	char			**token_map;//NULL first turn then reset [OK]
	int				token_map_height;//0 every turn [OK]
	int				token_map_lenght;//0 every turn [OK]
	t_filler_token	*to_place;//NULL first turn then reset [OK]
	char			player_token;//init once then never touched again [OK]
	int				player_token_is_found;//0 every turn [OK]
	char			enemy_token;//init once then never touched again [OK]
	char			enemy_token_to_chase;//init once then may change once [OK]
	int				enemy_token_to_chase_coord_x;//0 every turn [OK]
	int				enemy_token_to_chase_coord_y;//0 every turn [OK]
	int				enemy_token_is_found;//0 every turn [OK]
	t_filler_token	*placed_tokens;//starts NULL once, then never reset [OK]
};

void				deb_e(char *s);//<= TO DEL
void				deb_i(char *file, int line);

int					determine_players_token(t_filler_var *v);//[OK]
//int					determine_and_give_answer(t_filler_var *v);

void				init_and_reset_var(t_filler_var *v);//[OK]

t_filler_raw		*get_raw_standard_input_to_raw_lst(void);
int					extract_values_from_raw_lst_to_var_lst(t_filler_var *v,
					t_filler_raw *raw);
t_filler_token		*fill_token_to_place(char **token_map,
					t_filler_token *to_place);
int					find_if_1_player_game(t_filler_var *v);

t_filler_raw		*set_t_filler_raw(t_filler_raw *raw, char *content);
t_filler_token		*set_t_filler_token(t_filler_token *token, int x, int y);

void				del_and_set_to_null_t_filler_raw(t_filler_raw **raw);
void				del_and_set_to_null_array_table(char ***array_table);
void				del_and_set_to_null_t_filler_token(t_filler_token **token);

#endif
