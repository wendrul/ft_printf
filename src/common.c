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

int  ft_max_of3(int a, int b, int c)
{
    int max;
    max = a;
    if (max < b)
        max = b;
    if (max < c)
        max = c;
    return (max);
}

static int     fill_of_char(char *ret, int quantity, char fill, int start)
{
    int i;

    i = 0;
    while (i < quantity)
    {
        ret[start + i] = fill;
        i++;
    }
    return (i);
}

t_buff_manager  big_conversion(t_buff_manager man, t_flag_mod flags, char *str)
{
    char    *to_print;
    int     actual_width;
    int     end_cursor;
    int     i;
    char    pad;

    pad = flags.zero_padding ? '0' : ' ';
    actual_width = ft_max_of3(ft_strlen(str), flags.width, flags.precision);
    if (!(to_print = (char*)malloc(sizeof(char) * (actual_width + 1))))
        return (man);
    to_print[actual_width]= '\0';
    fill_of_char(to_print, flags.width, pad, 0);
    if (flags.left_adjust)
        end_cursor = ft_max(ft_strlen(str), flags.precision);
    i = ft_strlen(str) - 1;
    while (i >= 0)
        to_print[--end_cursor] = str[i--];
    ft_putstrf_fd(to_print, man.fd);
    man.total_count += ft_strlen(to_print);
    free(to_print);
    man.buf_cur -= 1;
    return (man);
}

t_buff_manager  normal_conversion(t_buff_manager man, t_flag_mod flags, char *str)
{
    
    char    pad;
    int     actual_width;
    int     end_cursor;
    int     i;

    pad = flags.zero_padding ? '0' : ' ';
    actual_width = ft_max_of3(ft_strlen(str), flags.width, flags.precision);
    fill_of_char(man.buf, flags.width, pad, man.buf_cur);
    end_cursor = actual_width;
    if (flags.left_adjust)
        end_cursor = ft_max(ft_strlen(str), flags.precision);
    fill_of_char(man.buf, flags.precision, '0', man.buf_cur + end_cursor - flags.precision);
    i = ft_strlen(str) - 1;
    while (i >= 0)
        man.buf[man.buf_cur + --end_cursor] = str[i--];
    man.buf_cur += actual_width - 1;
    return (man);
}
