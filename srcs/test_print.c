/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 20:38:10 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/10 21:51:01 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	test_print(t_filler_var *v)
{
	int		i;

	putf("is_player_one : ");
	ft_putnbr_fd(v->is_player_one, 2);
	putf("\nv->is_game_over : ");
	ft_putnbr_fd(v->is_game_over, 2);
	putf("\nv->map_height : ");
	ft_putnbr_fd(v->map_height, 2);
	putf("\nv->map_lenght : ");
	ft_putnbr_fd(v->map_lenght, 2);
	putf("\nmap : \n-\n");
	i = 0;
	while (v->map[i])
	{
		putf(v->map[i]);
		putf("\n");
		i++;
	}
	putf("-\n");
	putf("v->token_map_height : ");
	ft_putnbr_fd(v->token_map_height, 2);
	putf("\nv->token_map_lenght : ");
	ft_putnbr_fd(v->token_map_lenght, 2);
	putf("\ntoken_map : \n-\n");
	i = 0;
	while (v->token_map[i])
	{
		putf(v->token_map[i]);
		putf("\n");
		i++;
	}
	putf("-\n");
	exit (0);
}
