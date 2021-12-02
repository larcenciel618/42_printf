/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahirose <kahirose@studnt.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:22:09 by kahirose          #+#    #+#             */
/*   Updated: 2021/12/01 17:15:31 by kahirose         ###   ########.fr       */
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
