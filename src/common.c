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

#include "libftprintf.h"
#include <stdio.h>


t_buff_manager  ft_fflush(t_buff_manager man)
{
    man.total_count += man.buf_cur;
    if (man.buf[man.buf_cur] == '\n')
        man.total_count++;
    ft_putstrf_fd(man.buf, man.fd, man.buf_cur);
    man.buf_cur = -1;
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

t_fstring	ztr(char *str, long size)
{
	t_fstring string;

	string.str = str;
	string.size = size;
	return (string);
}

//todo make new normal_conversion that removes the need for big_conversion

t_buff_manager  conversion(t_buff_manager man, t_flag_mod flags, t_fstring str, t_fstring prefix)
{
    char pad;
    long actual_width;
    long i;
    long checkpoints[2];

    i = 0;
    checkpoints[0] = 0;
    checkpoints[1] = 0;
    actual_width = ft_max_of3(str.size, flags.width, flags.precision);
    pad = flags.zero_padding ? '0' : ' ';
    while (1)
    {
        if (man.fd != -2 && man.buf_cur >= man.buf_size)
            man = ft_fflush(man);
        if (flags.left_adjust)
        {
            if (i < prefix.size)
            {
                man.buf[man.buf_cur] = prefix.str[i];
            }
            else if (i < prefix.size + flags.precision - str.size)
            {
                man.buf[man.buf_cur] = '0';
                checkpoints[0] = i;
            }
            else if (i < prefix.size + ft_max(flags.precision, str.size))
                man.buf[man.buf_cur] = str.str[i - checkpoints[0]];
            else if (i < flags.width + prefix.size)  //if prefix is - do width++
                man.buf[man.buf_cur] = pad;
            else
                break;
        }
        else
        {
            if (i < flags.width - (ft_max(str.size, flags.precision) + prefix.size))
            {
                man.buf[man.buf_cur] = pad;
                checkpoints[0] = i;
                checkpoints[1] = i + prefix.size;
            }
            else if (i < checkpoints[0] + prefix.size)
                man.buf[man.buf_cur] = prefix.str[i - checkpoints[0]];
            else if (i < actual_width - str.size)
            {
                man.buf[man.buf_cur] = '0';
                checkpoints[1] = i;
            }
            else if (i < actual_width)
                man.buf[man.buf_cur] = str.str[i - checkpoints[1]];
            else
                break;
            
        }
        i++;
        man.buf_cur++;
    }
    if (actual_width != 0)
        man.buf_cur--;
    return (man);
}


//negative pointers?