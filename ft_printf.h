/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahirose <kahirose@studnt.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 02:52:18 by kahirose          #+#    #+#             */
/*   Updated: 2021/12/09 02:52:20 by kahirose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include	<stdarg.h>
# include	<unistd.h>
# include	<stdint.h>
# include	<limits.h>
# include 	<stdbool.h>

int		ft_printf(const char *s, ...);
short	ft_putchar(char c);
short	ft_putnbr(int n);
size_t	ft_putstr(char *s);
short	ft_putptr(uintptr_t p);
short	ft_puthex(unsigned int p, char frmat);
short	ft_putunbr(unsigned int nbr);

#endif
