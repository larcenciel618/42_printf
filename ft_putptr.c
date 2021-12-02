/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahirose <kahirose@studnt.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 07:07:38 by kahirose          #+#    #+#             */
/*   Updated: 2021/11/30 14:05:31 by kahirose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

short	ft_writeptr(uintptr_t p)
{
	short	count;

	count = 0;
	if (p != 0)
	{
		count = ft_writeptr(p / 16);
		p %= 16;
		if (p >= 10)
		{
			p += 'a' - 10;
			write(1, &p, 1);
		}
		else
		{
			p += '0';
			write(1, &p, 1);
		}
	}
	else
	{
		write(1, "0x", 2);
		count += 1;
	}
	return (count + 1);
}

short	ft_putptr(uintptr_t p)
{
	short	count;

	count = 3;
	if (p == 0)
	{
		write(1, "0x0", 3);
		return (count);
	}
	return (ft_writeptr(p));
}
