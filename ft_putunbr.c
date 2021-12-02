/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahirose <kahirose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 04:50:54 by kahirose          #+#    #+#             */
/*   Updated: 2021/11/20 06:02:19 by kahirose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

short	ft_putunbr(unsigned int unbr)
{
	char	nbr;
	short	count;

	count = 0;
	if (unbr >= 10)
		count = ft_putunbr(unbr / 10);
	nbr = (unbr % 10) + '0';
	write (1, &nbr, 1);
	return (count + 1);
}
