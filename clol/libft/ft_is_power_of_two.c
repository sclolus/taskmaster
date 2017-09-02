/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_power_of_two.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 04:30:16 by sclolus           #+#    #+#             */
/*   Updated: 2017/04/19 20:27:33 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_is_power_of_two(unsigned long long nbr)
{
	return ((nbr & (nbr - 1)) == 0);
}