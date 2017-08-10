/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   de.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlereffa <jlereffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 17:29:41 by jlereffa          #+#    #+#             */
/*   Updated: 2017/08/10 19:36:38 by jlereffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	de(char *file, int line)
{
	ft_putstr_fd("\033[1;31mFILE : {\033[1;33m", FD);
	ft_putstr_fd(file, FD);
	ft_putstr_fd("\033[1;31m} | LINE : {\033[1;33m", FD);
	ft_putnbr_fd(line, FD);
	ft_putstr_fd("\033[1;31m}\n\033[0m", FD);
}
