/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_letters.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-thom <ede-thom@42.edu.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 23:25:38 by ede-thom          #+#    #+#             */
/*   Updated: 2020/06/07 09:26:23 by ede-thom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_buff_manager	put_s(t_flag_mod flags, t_buff_manager man, va_list ap)
{
	char *s;
	long len;
	
	if (flags.width == -1)
		flags.width = va_arg(ap, int);
	if (flags.precision == -1)
		flags.precision = va_arg(ap, int);
	s = (char*)va_arg(ap, char*);
	if (s == NULL)
		s = "(null)";
	len = ft_min_positive(ft_strlen(s), flags.precision);
	flags.precision = 0;
	return (conversion(man, flags, ztr(s, len), ztr("", 0)));
}

t_buff_manager	put_c(t_flag_mod flags, t_buff_manager man, va_list ap)
{
	char c[2];

	flags.precision = 0;
	if (flags.width == -1)
		flags.width = va_arg(ap, int);
	if (flags.precision == -1)
		flags.precision = va_arg(ap, int);
	c[1] = '\0';
	c[0] = (char)va_arg(ap, int);
	return (conversion(man, flags, ztr(c, 1), ztr("", 0)));
}

t_buff_manager	put_percent(t_flag_mod flags, t_buff_manager man, va_list ap)
{
	char c[2];

	flags.precision = 0;
	if (flags.width == -1)
		flags.width = va_arg(ap, int);
	if (flags.precision == -1)
		flags.precision = va_arg(ap, int);
	c[1] = '\0';
	c[0] = '%';
	return (conversion(man, flags, ztr(c, 1), ztr("", 0)));
}
