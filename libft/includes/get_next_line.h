/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 02:04:34 by sclolus           #+#    #+#             */
/*   Updated: 2017/07/11 08:45:52 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1

# include <stdlib.h>
# include <unistd.h>

typedef struct	s_fd_data
{
	int		fd;
	char	buf[BUFF_SIZE + 1];
	char	*current;
}				t_fd_data;

#endif
