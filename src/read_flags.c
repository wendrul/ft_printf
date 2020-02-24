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

#include "ft_printf.h"

int     flag_atoi(t_buff_manager man, int *cur)
{
    int nb;

    nb = 0;
    while (man.buf[*cur] <= '9' && man.buf[*cur] >= '0')
    {
        nb = nb * 10 + man.buf[*cur] - '0';
        (*cur)++;
    }
    return (nb);

}
#include <stdio.h>

t_buff_manager     read_flags(const char *format, t_buff_manager man, va_list ap, t_put_func *put_funcs)
{
    int         func_number;
    int         old_cursor;
    t_flag_mod  flags;

    flags.left_adjust = 0;
    flags.zero_padding = 0;
    flags.precision = 0;
    man.form_cur++;
    old_cursor = man.form_cur;
    if (format[man.form_cur] == '0' || format[man.form_cur] == '-')
    {
        flags.left_adjust = format[man.form_cur] == '-';
        flags.zero_padding = format[man.form_cur] == '0';
        man.form_cur++;
    }
    if (format[man.form_cur] == '0' || format[man.form_cur] == '-')
    {
        flags.left_adjust = format[man.form_cur] == '-';
        flags.zero_padding = format[man.form_cur] == '0';
        man.form_cur++;
    }
    flags.width = flag_atoi(man, &man.form_cur);
    if (format[man.form_cur] == '.')
    {
        if (format[man.form_cur + 1] == '*')
            flags.precision = -1;
        else
            flags.precision = flag_atoi(man, &man.form_cur);
    }
    if ((func_number = ft_indexof(format[man.form_cur], "cspdiuxX%")) != -1)
        return (put_funcs[func_number](flags, man, ap));    //should return the updated manager
    else
    {
        man.buf[old_cursor] = '%';
        man.form_cur = old_cursor;
        return (man);
    }
}
