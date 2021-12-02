/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahirose <kahirose@studnt.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:21:16 by kahirose          #+#    #+#             */
/*   Updated: 2021/12/01 15:11:43 by kahirose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

short	ft_putnbr(int n)
{
	short	esc;
	short	count;

	count = 0;
	if (n == INT_MIN)
	{
		write (1, "-", 1);
		esc = n % 10 * -1 + '0';
		count = ft_putnbr (n / 10 * -1) + 1;
		write (1, &esc, 1);
		return (count + 1);
	}
	else if (n < 0)
	{
		write (1, "-", 1);
		n *= -1;
		if (n >= 10)
			count = ft_putnbr (n / 10);
		count += 1;
	}
	else if (n >= 10)
		count = ft_putnbr(n / 10);
	n = n % 10 + '0';
	write (1, &n, 1);
	return (count + 1);
}
