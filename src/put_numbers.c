/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-thom <ede-thom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 01:09:06 by ede-thom          #+#    #+#             */
/*   Updated: 2020/03/11 22:34:52 by ede-thom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_buff_manager  put_d(t_flag_mod flags, t_buff_manager man, va_list ap)
{
    int     nb;
    char    nb_ascii[NB_MAX_WIDTH];

    nb = va_arg(ap, int);
    if (flags.precision > 0)
        flags.zero_padding = 0;
    if (flags.width == -1)
        flags.width = va_arg(ap, int);
    if (flags.precision == -1)
        flags.precision= va_arg(ap, int);
    itoa_f(nb_ascii, nb, "0123456789");
    if (ft_max_of3(flags.width, flags.precision, NB_MAX_WIDTH) 
        > man.buf_size - man.buf_cur)
        man = ft_fflush(man);
    if (ft_max(flags.width, flags.precision) > man.buf_size)
        return (big_conversion(man, flags, nb_ascii));
    return (normal_conversion(man, flags, nb_ascii));
}

t_buff_manager  put_u(t_flag_mod flags, t_buff_manager man, va_list ap)
{
    unsigned int    nb;
    char            nb_ascii[NB_MAX_WIDTH];

    nb = va_arg(ap, unsigned int);
    if (flags.precision > 0)
        flags.zero_padding = 0;
    if (flags.width == -1)
        flags.width = va_arg(ap, int);
    if (flags.precision == -1)
        flags.precision= va_arg(ap, int);
    itoa_f(nb_ascii, nb, "0123456789");
    if (ft_max_of3(flags.width, flags.precision, NB_MAX_WIDTH) 
        > man.buf_size - man.buf_cur)
        man = ft_fflush(man);
    if (ft_max(flags.width, flags.precision) > man.buf_size)
        return (big_conversion(man, flags, nb_ascii));
    return (normal_conversion(man, flags, nb_ascii));
}

t_buff_manager  put_x(t_flag_mod flags, t_buff_manager man, va_list ap)
{
    unsigned int    nb;
    char            nb_ascii[NB_MAX_WIDTH];

    nb = va_arg(ap, unsigned int);
    if (flags.precision > 0)
        flags.zero_padding = 0;
    if (flags.width == -1)
        flags.width = va_arg(ap, int);
    if (flags.precision == -1)
        flags.precision= va_arg(ap, int);
    itoa_f(nb_ascii, nb, "0123456789abcdef");
    if (ft_max_of3(flags.width, flags.precision, NB_MAX_WIDTH) 
        > man.buf_size - man.buf_cur)
        man = ft_fflush(man);
    if (ft_max(flags.width, flags.precision) > man.buf_size)
        return (big_conversion(man, flags, nb_ascii));
    return (normal_conversion(man, flags, nb_ascii));
}

t_buff_manager  put_X(t_flag_mod flags, t_buff_manager man, va_list ap)
{
    unsigned int    nb;
    char            nb_ascii[NB_MAX_WIDTH];

    nb = va_arg(ap, unsigned int);
    if (flags.precision > 0)
        flags.zero_padding = 0;
    if (flags.width == -1)
        flags.width = va_arg(ap, int);
    if (flags.precision == -1)
        flags.precision= va_arg(ap, int);
    itoa_f(nb_ascii, nb, "0123456789ABCDEF");
    if (ft_max_of3(flags.width, flags.precision, NB_MAX_WIDTH) 
        > man.buf_size - man.buf_cur)
        man = ft_fflush(man);
    if (ft_max(flags.width, flags.precision) > man.buf_size)
        return (big_conversion(man, flags, nb_ascii));
    return (normal_conversion(man, flags, nb_ascii));
}

t_buff_manager put_p(t_flag_mod flags, t_buff_manager man, va_list ap)
{
    unsigned long int        nb;
    void            *ptr;
    char            ptr_ascii[2 + NB_MAX_WIDTH];

    ptr = va_arg(ap, void*);
    nb = (unsigned long int)ptr;
    if (flags.precision > 0)
        flags.zero_padding = 0;
    flags.precision += 2;
    ptr_ascii[0] = '0';
    ptr_ascii[1] = 'x';
    if (flags.width == -1)
        flags.width = va_arg(ap, int);
    if (flags.precision == -1)
        flags.precision= va_arg(ap, int);
    itoa_f(ptr_ascii + 2, nb, "0123456789abcdef");
    if (ft_max_of3(flags.width, flags.precision, NB_MAX_WIDTH) 
        > man.buf_size - man.buf_cur)
        man = ft_fflush(man);
    if (ft_max(flags.width, flags.precision) > man.buf_size)
        return (big_conversion(man, flags, ptr_ascii));
    return (normal_conversion(man, flags, ptr_ascii));
}
