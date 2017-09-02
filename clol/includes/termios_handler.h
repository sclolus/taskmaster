/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termios_handler.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 17:26:05 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/12 04:07:01 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMIOS_HANDLER_H
# define TERMIOS_HANDLER_H

# include <termios.h>
# include <stdint.h>

/*
** Modes :
** c_iflag
** c_oflag
** c_lflag
** c_cflag
*/

/*
** Setting modes
*/

int32_t		ft_set_l_mode(int mode);
int32_t		ft_set_o_mode(int mode);
int32_t		ft_set_i_mode(int mode);
int32_t		ft_set_c_mode(int mode);

/*
** Unsetting modes
*/

int32_t		ft_unset_l_mode(int mode);
int32_t		ft_unset_o_mode(int mode);
int32_t		ft_unset_i_mode(int mode);
int32_t		ft_unset_c_mode(int mode);

/*
** Resetting modes
*/

int32_t		ft_reset_l_mode(void);
int32_t		ft_reset_o_mode(void);
int32_t		ft_reset_i_mode(void);
int32_t		ft_reset_c_mode(void);

#endif
