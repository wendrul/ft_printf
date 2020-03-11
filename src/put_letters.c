/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_letters.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-thom <ede-thom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 23:25:38 by ede-thom          #+#    #+#             */
/*   Updated: 2020/03/11 23:51:18 by ede-thom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_buff_manager  put_s(t_flag_mod flags, t_buff_manager man, va_list ap)
{
    char    *s;
    
    flags.zero_padding = 0;
    flags.precision = 0;
    s = (char*)va_arg(ap, char*);
    if (flags.width == -1)
        flags.width = va_arg(ap, int);
    if (flags.precision == -1)
        flags.precision= va_arg(ap, int);
    if (s == NULL)
        s = "(null)";
    if ((int)ft_strlen(s) > man.buf_size - man.buf_cur || flags.width > man.buf_size - man.buf_cur)
       man = ft_fflush(man);
    if (ft_max(ft_strlen(s), flags.width) >= man.buf_size)
        return (big_conversion(man, flags, s));
    return (normal_conversion(man, flags, s));
}

t_buff_manager  put_c(t_flag_mod flags, t_buff_manager man, va_list ap)
{
    char c[2];

    c[1] = '\0';
    c[0] = (char)va_arg(ap, int);
    flags.precision = 0;
    if (flags.width == -1)
        flags.width = va_arg(ap, int);
    if (flags.precision == -1)
        flags.precision= va_arg(ap, int);
    if (man.buf_cur > man.buf_size - 1 || flags.width > man.buf_size - man.buf_cur)
       man = ft_fflush(man);
    if (flags.width > man.buf_size)
        return (big_conversion(man, flags, c));
    return (normal_conversion(man, flags, c));
}

t_buff_manager  put_percent(t_flag_mod flags, t_buff_manager man, va_list ap)
{
    char c[2];
    c[1] = '\0';
    c[0] = '%';
    flags.precision = 0;
    if (flags.width == -1)
        flags.width = va_arg(ap, int);
    if (flags.precision == -1)
        flags.precision= va_arg(ap, int);
    if (man.buf_cur > man.buf_size - 1 || flags.width > man.buf_size - man.buf_cur)
       man = ft_fflush(man);
    if (flags.width > man.buf_size)
        return (big_conversion(man, flags, c));
    return (normal_conversion(man, flags, c));
}