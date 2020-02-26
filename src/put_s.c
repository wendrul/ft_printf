/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-thom <ede-thom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 23:25:38 by ede-thom          #+#    #+#             */
/*   Updated: 2020/02/26 13:59:18 by ede-thom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_buff_manager  put_s(t_flag_mod flags, t_buff_manager man, va_list ap)
{
    char    *s;
    
    s = (char)va_arg(ap, char*);
    if (flags.width == -1)
        flags.width = va_arg(ap, int);
    if (flags.precision == -1)
        flags.precision= va_arg(ap, int);
    if (s == NULL)
        s = "(null)";
    if (ft_strlen(s) > man.buf_size - man.buf_cur || flags.width > man.buf_size - man.buf_cur)
       man = ft_fflush(man);
    if (ft_max(ft_strlen(s), flags.width) >= man.buf_size)
        big_handler(s, flags, man, ft_max(ft_strlen(s), flags.width));
    /*What happens when it strlen is bigger than buffer size*/
}