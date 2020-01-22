/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-thom <ede-thom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 20:33:28 by ede-thom          #+#    #+#             */
/*   Updated: 2020/01/11 20:33:28 by ede-thom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     ft_printf(const char *format, ...)
{
    va_list     ap;
    char        print_buf[FT_PRINTF_BUFF_SIZE + 1];

    va_start(ap, format);
    print_buf[0] = '\0';
    print_buf[FT_PRINTF_BUFF_SIZE] = '\0';
    return (read_format(1, print_buf, format, ap));
}

int     ft_dprintf(int fd, const char *format, ...)
{
    va_list     ap;
    char        print_buf[FT_PRINTF_BUFF_SIZE + 1];

    va_start(ap, format);
    print_buf[0] = '\0';
    print_buf[FT_PRINTF_BUFF_SIZE] = '\0';
    return (read_format(fd, print_buf, format, ap));
}

int     ft_sprintf(char *str, const char *format, ...)
{
    va_list     ap;

    va_start(ap, format);
    str[0] = '\0';
    return (read_format(-2, str, format, ap));
}
