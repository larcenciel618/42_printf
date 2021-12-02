/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahirose <kahirose@studnt.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:23:39 by kahirose          #+#    #+#             */
/*   Updated: 2021/12/01 17:17:58 by kahirose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	check_frmat(va_list ap, char frmat)
{
	if (frmat == 'c')
	{
		return (ft_putchar((char)va_arg(ap, int)));
	}
	if (frmat == 'd' || frmat == 'i' || frmat == 'u')
	{
		if (frmat == 'u')
			return (ft_putunbr((unsigned int)(va_arg(ap, unsigned int))));
		return (ft_putnbr(va_arg(ap, int)));
	}
	if (frmat == 's')
		return (ft_putstr(va_arg(ap, char *)));
	if (frmat == 'p')
		return (ft_putptr((uintptr_t)va_arg(ap, void *)));
	if (frmat == 'x' || frmat == 'X')
		return (ft_puthex((unsigned int)va_arg(ap, unsigned int), frmat));
	return (0);
}

bool	is_valid_frmat(char f)
{
	if (f == 'd' || f == 'c' || f == 's' || f == 'p'
		|| f == 'i' || f == 'u' || f == 'x' || f == 'X')
		return (true);
	else
		return (false);
}

size_t	check_overflow(size_t count, size_t i)
{
	if (i >= SIZE_MAX - count)
		return (SIZE_MAX);
	return (count + i);
}

int	print_and_alloc(va_list ap, const char *s)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0' && count <= INT_MAX)
	{
		if (s[i] == '%')
		{
			if (!s[i + 1])
				break ;
			if (is_valid_frmat(s[i + 1]))
				count = check_overflow(count, check_frmat(ap, s[i + 1]));
			else
				count += ft_putchar(s[i + 1]);
			i += 2;
		}
		else
			count += ft_putchar(s[i++]);
	}
	if (count > INT_MAX)
		return (-1);
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, s);
	count = print_and_alloc(ap, s);
	va_end(ap);
	return (count);
}

// #include <stdio.h>
// #include <limits.h>

// int main(void)
// {
// 	// long l = INT_MAX + INT_MAX;
// 	unsigned int l = UINT_MAX + 10;
// 	printf("%d\n", (int)l);
// 	int count;
// 	count = printf("%x\n", l);
// 	printf("count:%d\n", count);
// 	count = ft_printf("%x\n", l);
// 	printf("count:%d\n", count);
// 	return (0);
// }

// int main(int argc, char const *argv[])
// {
// 	int i = 1200000;

// 	printf("%x\n", i);
// 	printf("%d\n", i);

// 	ft_printf("%x\n", i);
// 	printf("%d\n", i);

// 	return 0;
// }
// int main(int argc, char const *argv[])
// {
// 	int result;
// 	int i = INT_MIN;
// 	char *s = "hello";
// 	char *s2 = "world";

// 	result = printf("%s%d%p%s\n", s, i, &i, s2);
// 	printf("result:%d\n", result);
// 	result = ft_printf("%s%d%p%s\n", s, i, &i, s2);
// 	printf("result:%d\n",result);
// 	return 0;
// }

// int	main(void)
// {
// 	char	c = 'a';
// 	int		i = 10;
// 	char	*str = "hello";
// 	char	*str2 = "world";
// 	int result;

// 	// printf("valid:%d\n", valid_frmat('y'));
// 	   result = printf("%s%s%%%%%ww%\n", str, str2, &i);
// 	printf("%d\n", result);
// 	result = ft_printf("%s%s%%%%%ww%\n", str, str2, &i);
// 	printf("%d\n", result);
// 	return (0);
// }

// int main(void)
// {
// 	int i, j;
// 	char c = 'a';
// 	char str[] = "hello";
// 	char str2[] = "world";

// 	   i = printf("%p:%s%s:%c%%  %%%\b%\n", str, str, str2, c);
// 	printf("\n");
// 	j = ft_printf("%p:%s%s:%c%%  %%%\b%\n", str, str, str2, c);
// 	printf("\n%d:%d\n", i, j);
// 	return (0);
// }

// int main(void)
// {
// 	int num;
// 	int i;

// 	num = 0;
// 	i = printf("%d:%d:%d\n", INT_MIN, num, INT_MAX);
// 	printf("%d\n", i);
// 	i = ft_printf("%d:%d:%d\n", INT_MIN, num, INT_MAX);
// 	printf("%d\n", i);
// 	return (0);
// }
