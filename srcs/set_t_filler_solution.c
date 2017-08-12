/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_t_filler_solution.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 11:20:45 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/12 15:32:37 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

static void			place_token_on_current_position_on_map(
					int ***tab, t_filler_token *token, int x, int y)
{
	while (token)
	{
		(*tab)[x + token->x][y + token->y] = 1;
		token = token->next;
	}
}

static int			initialize_solution_tab(
					int ***tab, t_filler_var *v, int x, int y)
{
	int	i;
	int	j;

	i = -1;
//	DEB
	if (!(*tab = (int**)malloc(sizeof(int*) * v->map_height)))
		return (0);
//	DEB
	while (++i < v->map_height)
	{
		//DEB
		/*putf("i : {");
		ft_putnbr_fd(i, 2);
		putf("}\n");
		*/if (!((*tab)[i] = (int*)malloc(sizeof(int) * v->map_lenght)))
			return (0);
		j = -1;
//		DEB
		while (++j < v->map_lenght)
		{
	//		DEB
			/*putf("j : {");
			ft_putnbr_fd(j, 2);
			putf("}\n");
			*/if (v->map[i][j] == '.')
				(*tab)[i][j] = 255;
			else if (v->map[i][j] == 'P')
				(*tab)[i][j] = 1;
			else if (v->map[i][j] == 'T')
				(*tab)[i][j] = -1;
	//		DEB
		}
	}
	//DEB
	place_token_on_current_position_on_map(tab, v->token, x, y);
//	DEB
	return (1);
}

t_filler_solution	*set_t_filler_solution(
					t_filler_solution *solution, t_filler_var *v, int i, int j)
{
//	DEB
	if (!solution)
	{
//		DEB
		if (!(solution = (t_filler_solution*)malloc(sizeof(t_filler_solution))))
			return (NULL);
		solution->x_origin = i;
		solution->y_origin = j;
		solution->value = 0;
//		DEB
		if (!(initialize_solution_tab(&solution->tab, v, i, j)))
			return (NULL);
	//	DEB
		solution->prev = NULL;
		solution->next = NULL;
		//DEB
		return (solution);
	}
	//DEB
	while (solution->next)
	{
//		DEB
		solution = solution->next;
	}
	if (!(solution->next = set_t_filler_solution(solution->next, v, i, j)))
		return (NULL);
	solution->next->prev = solution;
	solution = solution->next;
//	DEB
	return (solution);
}
