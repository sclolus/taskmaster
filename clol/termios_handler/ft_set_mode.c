/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_mode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 17:23:28 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/09 17:30:03 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termios_handler.h"

int32_t		ft_set_l_mode(int mode)
{
	static struct termios	term;

	if (tcgetattr(0, &term) == -1)
		return (-1);
	term.c_lflag |= mode;
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		return (-1);
	return (0);
}

int32_t		ft_set_o_mode(int mode)
{
	static struct termios	term;

	if (tcgetattr(0, &term) == -1)
		return (-1);
	term.c_oflag |= mode;
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		return (-1);
	return (0);
}

int32_t		ft_set_i_mode(int mode)
{
	static struct termios	term;

	if (tcgetattr(0, &term) == -1)
		return (-1);
	term.c_iflag |= mode;
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		return (-1);
	return (0);
}

int32_t		ft_set_c_mode(int mode)
{
	static struct termios	term;

	if (tcgetattr(0, &term) == -1)
		return (-1);
	term.c_cflag |= mode;
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		return (-1);
	return (0);
}
