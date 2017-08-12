/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_solutions_values.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 15:15:07 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/12 17:25:34 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

static void	fill_solution_tab(int ***tab, t_filler_var *v)
{
	int	i;
	int	i_mod;
	int	j;
	int	j_mod;
	int	value;
	int	done;

	done = 0;
	value = 1;
	while (!done)
	{
DEB
		done = 1;
		i = -1;
		while (++i < v->map_height)
		{
			DEB
			j = -1;
			while (++j < v->map_lenght)
			{
				DEB
				if ((*tab)[i][j] == value)
				{
					DEB
					done = 0;
					i_mod = -2;
					while (++i_mod < 2)
					{
						DEB
						j_mod = -2;
						while (++j_mod < 2)
						{
							DEB
							if (i + i_mod >= 0 && j + j_mod >= 0 &&
								i + i_mod < v->map_height &&
								j + j_mod < v->map_lenght)
							{
								if ((*tab)[i + i_mod][j + j_mod] == 255)
									(*tab)[i + i_mod][j + j_mod] = value + 1;
								else if ((*tab)[i + i_mod][j + j_mod] == -value - 1)
									(*tab)[i + i_mod][j + j_mod] = 0;
							}
						}
					}
				}
				else if ((*tab)[i][j] == -value)
				{
					DEB
					done = 0;
					i_mod = -2;
					while (++i_mod < 2)
					{
						DEB
						j_mod = -2;
						while (++j_mod < 2)
						{
							DEB
							if (i + i_mod >= 0 && j + j_mod >= 0 &&
								i + i_mod < v->map_height &&
								j + j_mod < v->map_lenght)
							{
								DEB
								if ((*tab)[i + i_mod][j + j_mod] == 255)
									(*tab)[i + i_mod][j + j_mod] = -value -1;
								else if ((*tab)[i + i_mod][j + j_mod] == value + 1)
									(*tab)[i + i_mod][j + j_mod] = 0;
								DEB
							}
						}
					}
				}
				DEB
			}
		}
		DEB
		value++;
	}
}

static int	count_solution_points_value(int **tab, t_filler_var *v)
{
	int	i;
	int	j;
	int	ret;

	ret = 0;
	i = -1;
	while (++i < v->map_height)
	{
		j = -1;
		while (++j < v->map_lenght)
			ret += tab[i][j];
	}
	return (ret);
}

int			get_solutions_values(t_filler_solution *solution, t_filler_var *v)
{
	if (!solution)
		return (0);
	while (solution)
	{
		DEB
		fill_solution_tab(&solution->tab, v);
		DEB
		solution->value = count_solution_points_value(solution->tab, v);
		DEB
		solution = solution->next;
	}
	return (1);
}
