/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-thom <ede-thom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 20:20:46 by ede-thom          #+#    #+#             */
/*   Updated: 2020/06/09 20:29:55 by ede-thom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_buff_manager	ft_fflush(t_buff_manager man)
{
	man.total_count += man.buf_cur;
	if (man.buf[man.buf_cur] == '\n')
		man.total_count++;
	ft_putstrf_fd(man.buf, man.fd, man.buf_cur);
	man.buf_cur = -1;
	return (man);
}

int				left_adjust(t_poub a, t_buff_manager *man, long checkpoints[2])
{
	if (a.i < a.p.size)
	{
		man->buf[man->buf_cur] = a.p.str[a.i];
		checkpoints[0] = a.i + 1;
	}
	else if (a.i < a.p.size + a.fl.precision - a.s.size)
	{
		man->buf[man->buf_cur] = '0';
		checkpoints[0] = a.i + 1;
	}
	else if (a.i < a.p.size + ft_max(a.fl.precision, a.s.size))
		man->buf[man->buf_cur] = a.s.str[a.i - checkpoints[0]];
	else if (a.i < a.fl.width)
		man->buf[man->buf_cur] = a.pad;
	else
		return (1);
	return (0);
}

int				right_adjust(t_poub a, t_buff_manager *man, long checkpoints[2])
{
	if (a.i < a.fl.width
		- (ft_max(a.s.size, a.fl.precision) + a.p.size))
	{
		man->buf[man->buf_cur] = a.pad;
		checkpoints[0] = a.i + 1;
		checkpoints[1] = a.i + 1 + a.p.size;
	}
	else if (a.i < checkpoints[0] + a.p.size && a.p.str[0])
		man->buf[man->buf_cur] = a.p.str[a.i - checkpoints[0]];
	else if (a.i < a.awidth - a.s.size)
	{
		man->buf[man->buf_cur] = '0';
		checkpoints[1] = a.i + 1;
	}
	else if (a.i < a.awidth)
		man->buf[man->buf_cur] = a.s.str[a.i - checkpoints[1]];
	else
		return (1);
	return (0);
}

t_buff_manager	conversion2(t_poub a)
{
	while (1)
	{
		if (a.man.fd != -2 && a.man.buf_cur >= a.man.buf_size)
			a.man = ft_fflush(a.man);
		if (a.fl.left_adjust)
		{
			if (left_adjust(a, &a.man, a.cp))
				break ;
		}
		else
		{
			if (a.p.str[0] == '-' && a.pad == '0')
			{
				a.p.str++;
				a.man.buf[a.man.buf_cur] = '-';
			}
			else if (right_adjust(a, &a.man, a.cp))
				break ;
		}
		a.i++;
		a.man.buf_cur++;
	}
	a.man.buf_cur--;
	return (a.man);
}

t_buff_manager	conversion
	(t_buff_manager man, t_flag_mod flags, t_fstring str, t_fstring prefix)
{
	t_poub	a;

	a.fl = flags;
	a.man = man;
	a.s = str;
	a.p = prefix;
	a.i = 0;
	a.cp[0] = 0;
	a.cp[1] = prefix.size;
	a.awidth = ft_max_of3(
		str.size + prefix.size, flags.width, flags.precision + prefix.size);
	a.pad = flags.zero_padding ? '0' : ' ';
	return (conversion2(a));
}
