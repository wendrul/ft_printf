/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-thom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 12:13:03 by ede-thom          #+#    #+#             */
/*   Updated: 2020/03/09 12:14:05 by ede-thom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf(const char *format, ...)
{
    va_list         ap;
    char            print_buf[FT_PRINTF_BUFF_SIZE + 1];
    t_buff_manager  man;

    va_start(ap, format);
    print_buf[0] = '\0';
    print_buf[FT_PRINTF_BUFF_SIZE] = '\0';
    man.total_count = 0;
    man.form_cur = -1;
    man.buf_cur = -1;
    man.fd = 1;
    man.buf = print_buf;
    man.buf_size = FT_PRINTF_BUFF_SIZE;
    return (read_format(man, format, ap));
}

int		ft_dprintf(int fd, const char *format, ...)
{
    va_list         ap;
    char            print_buf[FT_PRINTF_BUFF_SIZE + 1];
    t_buff_manager  man;

    va_start(ap, format);
    print_buf[0] = '\0';
    print_buf[FT_PRINTF_BUFF_SIZE] = '\0';
    man.total_count = 0;
    man.form_cur = -1;
    man.buf_cur = -1;
    man.fd = fd;
    man.buf = print_buf;
    man.buf_size = FT_PRINTF_BUFF_SIZE;
    return (read_format(man, format, ap));
}

int		ft_sprintf(char *str, int size, const char *format, ...)
{
    va_list     ap;
    t_buff_manager man;

    va_start(ap, format);
    str[0] = '\0';
    man.total_count = 0;
    man.form_cur = -1;
    man.buf_cur = -1;
    man.fd = -2;
    man.buf = str;
    man.buf_size = size;
    return (read_format(man, format, ap));
}
