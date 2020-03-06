/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-thom <ede-thom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 20:33:23 by ede-thom          #+#    #+#             */
/*   Updated: 2020/01/11 20:33:23 by ede-thom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    declare_put_functions(t_put_func *put_funcs)
{
    put_funcs[0] = put_c; /*c*/
    put_funcs[1] = put_s; /*s*/
    put_funcs[2] = NULL; /*p*/
    put_funcs[3] = NULL; /*d*/
    put_funcs[4] = NULL; /*i*/
    put_funcs[5] = NULL; /*u*/
    put_funcs[6] = NULL; /*x*/
    put_funcs[7] = NULL; /*X*/
    put_funcs[8] = NULL; /*%*/
}

int     read_format(t_buff_manager man, const char *format, va_list ap)
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
    ft_putstrf_fd(man.buf, man.fd);
    return (man.total_count + man.buf_cur);
}
