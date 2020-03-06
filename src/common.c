/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-thom <ede-thom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 20:20:46 by ede-thom          #+#    #+#             */
/*   Updated: 2020/02/24 20:20:46 by ede-thom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_buff_manager  ft_fflush(t_buff_manager man)
{
    if (man.buf[man.buf_cur] == '\n')
        man.buf_cur++;
    man.total_count += man.buf_cur;
    man.buf[man.buf_cur] = '\0';
    man.buf_cur = 0;
    ft_putstrf_fd(man.buf, man.fd);
    return (man);
}

t_buff_manager  big_conversion(t_buff_manager man, t_flag_mod flags, char *str)
{
    char    *to_print;
    int     size;
    int     i;
    char    pad;

    pad = ' ';
    if (flags.zero_padding)
        pad = '0';
    size = ft_max(ft_strlen(str), flags.width);
    if (!(to_print = (char*)malloc(sizeof(char) * (size + 1))))
        return (man);
    to_print[size]= '\0';
    i = -1;
    while (to_print[++i])
        to_print[i] = pad;
    if (flags.left_adjust)
        size = ft_strlen(str);
    i = ft_strlen(str);
    while (*str)
        to_print[size - i--] = *(str++);
    ft_putstrf_fd(to_print, man.fd);
    return (man);
}

t_buff_manager  normal_conversion(t_buff_manager man, t_flag_mod flags, char *str)
{
    int     i;
    char    pad;
    int     actual_width;
    int     end_cursor;

    i = 0;
    pad = ' ';
    if (flags.zero_padding)
        pad = '0';
    while (i < flags.width)
    {
        man.buf[man.buf_cur + i] = pad;
        i++;
    }
    actual_width = ft_max(flags.width, ft_strlen(str));
    end_cursor = actual_width;
    if (flags.left_adjust)
        end_cursor = ft_strlen(str);
    i = ft_strlen(str);
    while (*str)
    {
        man.buf[man.buf_cur + end_cursor - i--] = *(str++);
    }
    man.buf_cur += actual_width - 1;
    return (man);
}