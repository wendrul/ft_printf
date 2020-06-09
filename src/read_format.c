/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-thom <ede-thom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 20:33:23 by ede-thom          #+#    #+#             */
/*   Updated: 2020/06/09 20:32:23 by ede-thom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	declare_put_functions(t_put_func *put_funcs)
{
	put_funcs[0] = put_c;
	put_funcs[1] = put_s;
	put_funcs[2] = put_p;
	put_funcs[3] = put_d;
	put_funcs[4] = put_d;
	put_funcs[5] = put_u;
	put_funcs[6] = put_x;
	put_funcs[7] = put_up_x;
	put_funcs[8] = put_percent;
}

int		read_format(t_buff_manager man, const char *format, va_list ap)
{
	t_put_func put_functions[9];

	declare_put_functions(put_functions);
	while (format[++man.form_cur])
	{
		if (man.fd != -2
				&& (man.buf[man.buf_cur] == '\n'
				|| man.buf_cur >= man.buf_size))
		{
			man = ft_fflush(man);
		}
		if (format[man.form_cur] == '%')
			man = read_flags(format, man, ap, put_functions);
		else
		{
			man.buf_cur++;
			man.buf[man.buf_cur] = format[man.form_cur];
		}
	}
	man.buf[man.buf_cur + 1] = '\0';
	ft_putstrf_fd(man.buf, man.fd, man.buf_cur);
	return (man.total_count + man.buf_cur + 1);
}
