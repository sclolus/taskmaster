/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset_mode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 17:29:07 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/09 17:30:00 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termios_handler.h"

int32_t		ft_reset_l_mode(void)
{
	static struct termios	term;

	if (tcgetattr(0, &term) == -1)
		return (-1);
	term.c_lflag = 0;
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		return (-1);
	return (0);
}

int32_t		ft_reset_o_mode(void)
{
	static struct termios	term;

	if (tcgetattr(0, &term) == -1)
		return (-1);
	term.c_oflag = 0;
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		return (-1);
	return (0);
}

int32_t		ft_reset_i_mode(void)
{
	static struct termios	term;

	if (tcgetattr(0, &term) == -1)
		return (-1);
	term.c_iflag = 0;
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		return (-1);
	return (0);
}

int32_t		ft_reset_c_mode(void)
{
	static struct termios	term;

	if (tcgetattr(0, &term) == -1)
		return (-1);
	term.c_cflag = 0;
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		return (-1);
	return (0);
}
