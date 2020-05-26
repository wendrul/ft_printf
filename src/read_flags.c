/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-thom <ede-thom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 20:41:59 by ede-thom          #+#    #+#             */
/*   Updated: 2020/01/11 20:41:59 by ede-thom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int				flag_atoi(const char *format, int *cur)
{
	int nb;

	if (format[*cur] == '*')
	{
		(*cur)++;
		return (-1);
	}
	nb = 0;
	while (format[*cur] <= '9' && format[*cur] >= '0')
	{
		nb = nb * 10 + format[*cur] - '0';
		(*cur)++;
	}
	return (nb);
}

int				init_read_flags(t_flag_mod *flags, t_buff_manager *man)
{
	flags->left_adjust = 0;
	flags->zero_padding = 0;
	flags->precision = -2;
	flags->width = -2;
	man->buf_cur++;
	man->form_cur++;
	return (man->form_cur);
}

t_buff_manager	read_flags
	(const char *format, t_buff_manager man, va_list ap, t_put_func *put_funcs)
{
	int			func_number;
	int			old_cursor;
	t_flag_mod	flags;

	old_cursor = init_read_flags(&flags, &man);
	while (format[man.form_cur] == '0' || format[man.form_cur] == '-')
	{
		flags.left_adjust = format[man.form_cur] == '-' || flags.left_adjust;
		flags.zero_padding = format[man.form_cur] == '0' && !flags.left_adjust;
		man.form_cur++;
	}
	flags.width = flag_atoi(format, &man.form_cur);
	if (format[man.form_cur] == '.')
	{
		man.form_cur++;
		flags.precision = flag_atoi(format, &man.form_cur);
	}
	if ((func_number = ft_indexof(format[man.form_cur], "cspdiuxX%")) != -1)
		return (put_funcs[func_number](flags, man, ap));
	else
	{
		man.buf[man.buf_cur] = '%';
		man.form_cur = old_cursor;
		return (man);
	}
}
