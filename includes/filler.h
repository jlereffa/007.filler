/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 17:13:16 by jlereffa          #+#    #+#             */
/*   Updated: 2017/07/29 16:57:18 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

//
#include <fcntl.h>
//

#include <libft.h>
#include <unistd.h>

typedef struct s_filler_raw t_filler_raw;
struct 				s_filler_raw
{
	char			*s;
	t_filler_raw	*prev;
	t_filler_raw	*next;
};

typedef struct s_filler_piece t_fillit_piece;
struct 				s_filler_piece
{
	int				x;
	int				y;
	t_fillit_piece	*prev;
	t_fillit_piece	*next;
};

typedef struct s_filler_var t_filler_var;
struct 				s_filler_var
{
	char			**tab;
	int				tab_height;
	int				tab_lenght;
	char			**piece;
	int				piece_height;
	int				piece_lenght;
	t_fillit_piece	*piece;
};

t_filler_raw		*get_raw_standard_input_to_raw_lst(int fd);
int					find_s_into_other_s(char *s1, char *s2);

t_filler_raw		*handle_raw_lst(t_filler_raw *raw, char *content);

#endif
