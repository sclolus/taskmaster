/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_current_prompt_len.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 06:23:45 by sclolus           #+#    #+#             */
/*   Updated: 2017/05/09 06:45:49 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

uint32_t	ft_get_current_prompt_len(void)
{
	return (ft_get_prompt_state_machine()[*ft_get_current_prompt()].len);
}

char		*ft_get_current_prompt_string(void)
{
	return (ft_get_prompt_state_machine()[*ft_get_current_prompt()].prompt);
}
