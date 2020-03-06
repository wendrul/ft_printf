/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-thom <ede-thom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 20:25:09 by ede-thom          #+#    #+#             */
/*   Updated: 2020/02/24 20:25:09 by ede-thom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_buff_manager  put_c2( t_buff_manager man, t_flag_mod flags, char c)
{
    int     i;
    char    pad;

    i = 0;
    pad = ' ';
    if (flags.zero_padding)
        pad = '0';
    while (i < flags.width)
    {
        man.buf[man.buf_cur + i] = pad;
        i++;
    }
    if (flags.left_adjust || flags.width == 0)
        man.buf[man.buf_cur] = c;
    else
        man.buf[man.buf_cur + i - 1] = c;
    man.buf_cur += i;
    return (man);
}

t_buff_manager  put_c(t_flag_mod flags, t_buff_manager man, va_list ap)
{
    char c[2];

    c[1] = '\0';
    c[0] = (char)va_arg(ap, int);
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
