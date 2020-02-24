/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-thom <ede-thom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 20:25:09 by ede-thom          #+#    #+#             */
/*   Updated: 2020/02/24 20:25:09 by ede-thom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_buff_manager put_c(t_flag_mod flags, t_buff_manager man, va_list ap)
{
    (void)man;
    (void)flags;
    (void)ap;
    if (man.buf_cur >= man.buf_size)
        man = ft_fflush(man);
    ft_putstrf_fd(&va_arg(ap, char));
    return (man);
}
