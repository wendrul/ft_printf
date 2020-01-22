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

int     read_format(int fd, char *buf, const char *format, va_list ap)
{
    int     cnt;
    int     i;
    int     j;

    cnt = 0;
    i = -1;
    j = -1;
    while (format[++i])
    {
        if (fd != -2 && (format[i] == '\n' || j >= FT_PRINTF_BUFF_SIZE))
        {
            cnt += j;
            j = 0;
            ft_putstrf_fd(buf, fd);
        }
        if (format[i] == '%')
            i += read_flags(&format[i], &j, buf, fd, ap);
        else
            buf[++j] = format[i];
    }
    buf[j] = '\0';
    fd != -2 ? ft_putstrf_fd(buf, fd): (void)fd ;
    return (cnt + j);
}
