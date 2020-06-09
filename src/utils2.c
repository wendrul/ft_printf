/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-thom <ede-thom@42.edu.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 13:28:56 by ede-thom          #+#    #+#             */
/*   Updated: 2020/05/26 13:28:56 by ede-thom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_max_of3(int a, int b, int c)
{
	int max;

	max = a;
	if (max < b)
		max = b;
	if (max < c)
		max = c;
	return (max);
}

long		ft_min_positive(long a, long b)
{
	if (b < 0 && a < 0)
		return (0);
	if (a < 0)
		return (b);
	if (b < 0)
		return (a);
	if (a < b)
		return (a);
	else
		return (b);
}

t_fstring	ztr(char *str, long size)
{
	t_fstring string;

	string.str = str;
	string.size = size;
	return (string);
}

long		ft_arg_abs(long n)
{
	if (n < 0)
		return -n;
	return n;
}

void		read_star_flag(t_flag_mod *flags_ptr, va_list ap)
{
	t_flag_mod flags;

	flags = *flags_ptr;
	if (flags.width == -1)
		flags.width = va_arg(ap, int);
	if (flags.precision == -1)
		flags.precision = va_arg(ap, int);
	if (flags.width < 0)
	{
		flags.left_adjust = 1;
		flags.zero_padding = 0;
		flags.width = -flags.width;
	}
	*flags_ptr = flags;
}
