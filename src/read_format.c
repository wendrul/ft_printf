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
    t_buff_manager man;

    man.total_count = 0;
    man.form_cur = -1;
    man.buf_cur = -1;
    man.fd = fd;
    man.buf = buf;
    while (format[++man.form_cur])
    {
        if (fd != -2 && (format[man.form_cur] == '\n' || man.buf_cur >= FT_PRINTF_BUFF_SIZE))
        {
            man.total_count += man.buf_cur;
            man.buf_cur = 0;
            ft_putstrf_fd(buf, fd);
        }
        if (format[man.form_cur] == '%')
            man = read_flags(format, man, ap);
        else
            buf[++man.buf_cur] = format[man.buf_cur];
    }
    buf[man.buf_cur] = '\0';
    fd == -2 ? : ft_putstrf_fd(buf, fd);
    return (man.total_count + man.buf_cur);
}
