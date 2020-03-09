/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-thom <ede-thom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 01:09:06 by ede-thom          #+#    #+#             */
/*   Updated: 2020/03/09 11:51:57 by ede-thom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_buff_manager  put_d(t_flag_mod flags, t_buff_manager man, va_list ap)
{
    int     nb;
    char    nb_ascii[NB_CHARACTER_MAX_WIDTH];

    nb = va_arg(ap, int);
    if (flags.width == -1)
        flags.width = va_arg(ap, int);
    if (flags.precision == -1)
        flags.precision= va_arg(ap, int);
    itoa_f(nb_ascii, nb, "0123456789");
    if (flags.width > man.buf_size)
        return (big_conversion(man, flags, nb_ascii));
    return (normal_conversion(man, flags, nb_ascii));
}

t_buff_manager  put_u(t_flag_mod flags, t_buff_manager man, va_list ap)
{
    long int     nb;
    char    nb_ascii[NB_CHARACTER_MAX_WIDTH];

    nb = va_arg(ap, unsigned int);
    if (flags.width == -1)
        flags.width = va_arg(ap, int);
    if (flags.precision == -1)
        flags.precision= va_arg(ap, int);
    itoa_f(nb_ascii, nb, "0123456789");
    if (flags.width > man.buf_size)
        return (big_conversion(man, flags, nb_ascii));
    return (normal_conversion(man, flags, nb_ascii));
}

t_buff_manager  put_x(t_flag_mod flags, t_buff_manager man, va_list ap)
{
    int     nb;
    char    nb_ascii[NB_CHARACTER_MAX_WIDTH];

    nb = va_arg(ap, int);
    if (flags.width == -1)
        flags.width = va_arg(ap, int);
    if (flags.precision == -1)
        flags.precision= va_arg(ap, int);
    itoa_f(nb_ascii, nb, "0123456789abcdef");
    if (flags.width > man.buf_size)
        return (big_conversion(man, flags, nb_ascii));
    return (normal_conversion(man, flags, nb_ascii));
}

t_buff_manager  put_X(t_flag_mod flags, t_buff_manager man, va_list ap)
{
    int     nb;
    char    nb_ascii[NB_CHARACTER_MAX_WIDTH];

    nb = va_arg(ap, int);
    if (flags.width == -1)
        flags.width = va_arg(ap, int);
    if (flags.precision == -1)
        flags.precision= va_arg(ap, int);
    itoa_f(nb_ascii, nb, "0123456789ABCDEF");
    if (flags.width > man.buf_size)
        return (big_conversion(man, flags, nb_ascii));
    return (normal_conversion(man, flags, nb_ascii));
}