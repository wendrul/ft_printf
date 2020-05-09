/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 01:09:06 by ede-thom          #+#    #+#             */
/*   Updated: 2020/05/09 17:36:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

t_buff_manager  put_d(t_flag_mod flags, t_buff_manager man, va_list ap)
{
    int         sign;
    long        nb;
    char        n[NB_MAX_WIDTH];
    char        *p;

    nb = va_arg(ap, int);
    sign = 1;
    if (nb < 0)
    {
        nb = -nb;
        sign = -1;
    }
    if (flags.precision > 0)
        flags.zero_padding = 0;
    if (flags.width == -1)
        flags.width = va_arg(ap, int);
    if (flags.precision == -1)
        flags.precision= va_arg(ap, int);
    itoa_f(n, nb, "0123456789");
    p = n;
    if (flags.precision == 0)
        p = "";
    if (sign == -1)
        return (conversion(man, flags, ztr(p, ft_strlen(p)), ztr("-", 1)));
    return (conversion(man, flags, ztr(p, ft_strlen(p)), ztr("", 0)));
}

t_buff_manager  put_u(t_flag_mod flags, t_buff_manager man, va_list ap)
{
    unsigned int    nb;
    char            n[NB_MAX_WIDTH];
    char            *p;

    nb = va_arg(ap, unsigned int);
    if (flags.precision > 0)
        flags.zero_padding = 0;
    if (flags.width == -1)
        flags.width = va_arg(ap, int);
    if (flags.precision == -1)
        flags.precision= va_arg(ap, int);
    itoa_f(n, nb, "0123456789");
    p = n;
    if (flags.precision == 0)
        p = "";
    return (conversion(man, flags, ztr(p, ft_strlen(p)), ztr("", 0)));
}

t_buff_manager  put_x(t_flag_mod flags, t_buff_manager man, va_list ap)
{
    unsigned int    nb;
    char            n[NB_MAX_WIDTH];
    char            *p;

    nb = va_arg(ap, unsigned int);
    if (flags.precision > 0)
        flags.zero_padding = 0;
    if (flags.width == -1)
        flags.width = va_arg(ap, int);
    if (flags.precision == -1)
        flags.precision= va_arg(ap, int);
    itoa_f(n, nb, "0123456789abcdef");
    p = n;
    if (flags.precision == 0)
        p = "";
    return (conversion(man, flags, ztr(p, ft_strlen(p)), ztr("", 0)));
}

t_buff_manager  put_X(t_flag_mod flags, t_buff_manager man, va_list ap)
{
    unsigned int    nb;
    char            n[NB_MAX_WIDTH];
    char            *p;

    nb = va_arg(ap, unsigned int);
    if (flags.precision > 0)
        flags.zero_padding = 0;
    if (flags.width == -1)
        flags.width = va_arg(ap, int);
    if (flags.precision == -1)
        flags.precision= va_arg(ap, int);
    itoa_f(n, nb, "0123456789ABCDEF");
    p = n;
    if (flags.precision == 0)
        p = "";
    return (conversion(man, flags, ztr(p, ft_strlen(p)), ztr("", 0)));
}

t_buff_manager put_p(t_flag_mod flags, t_buff_manager man, va_list ap)
{
    unsigned long int        nb;
    void            *ptr;
    char            p[NB_MAX_WIDTH];
    char            *n;

    ptr = va_arg(ap, void*);
    nb = (unsigned long int)ptr;
    if (flags.precision > 0)
        flags.zero_padding = 0;
    if (flags.width == -1)
        flags.width = va_arg(ap, int);
    if (flags.precision == -1)
        flags.precision= va_arg(ap, int);
    itoa_f(p, nb, "0123456789abcdef");
    n = p;
    if (flags.precision == 0)
        n = "";
    return (conversion(man, flags, ztr(n, ft_strlen(n)), ztr("0x", 2)));
}
