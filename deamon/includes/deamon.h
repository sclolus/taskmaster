/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deamon.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 02:15:26 by sclolus           #+#    #+#             */
/*   Updated: 2017/08/20 05:26:23 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEAMON_H
# define DEAMON_H

# include "taskmaster.h"
# include "libft.h"
# include <stdio.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <unistd.h>

# define DEAMON_NAME "deamon"
# define MAX_PENDING_CONNECTION 128

# define OFFSETOF(type, member) ((uint64_t)(&((type*)0)->member))

/*
** DEBUG
*/ //

# define CHECK(x) do {ft_putendl_fd("_____", 2);ft_putendl_fd(#x, 2);ft_putendl_fd("_____", 2);} while (0);

/*
** Error Handling
*/
# define TM_ERR(x) DEAMON_NAME ": " x
#endif
