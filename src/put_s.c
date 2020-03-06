/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 23:25:38 by ede-thom          #+#    #+#             */
/*   Updated: 2020/03/06 20:38:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_buff_manager  put_s(t_flag_mod flags, t_buff_manager man, va_list ap)
{
    char    *s;
    
    flags.zero_padding = 0;
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