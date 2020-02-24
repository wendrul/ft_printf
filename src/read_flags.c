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

t_buff_manager     read_flags(const char *format, t_buff_manager man, va_list ap)
{
    int         func_number;
    t_flag_mod  flags;

    flags.left_adjust = 0;
    flags.zero_padding = 0;
    flags.precision = 0;
    while (!ft_iswhitespace(format[++man.form_cur]))
    {
        if ((func_number = ft_indexof(format[man.form_cur], "cspdiuxX%")) != -1)
            return (putter_func[func_number](ap, flags, man));    // should return the updated manager
    }
    return (man);
}

