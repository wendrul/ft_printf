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