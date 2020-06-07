/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-thom <ede-thom@42.edu.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 12:18:09 by ede-thom          #+#    #+#             */
/*   Updated: 2020/05/25 12:18:09 by ede-thom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>

# define FT_PRINTF_BUFF_SIZE 4096
# define FT_PRINTF_PADDING 100
# define NB_MAX_WIDTH 12

typedef struct	s_flag_mod
{
	int			zero_padding;
	int			left_adjust;
	int			precision;
	int			width;
}				t_flag_mod;

typedef struct	s_buff_manager
{
	int			fd;
	char		*buf;
	int			buf_cur;
	int			form_cur;
	int			total_count;
	int			buf_size;
}				t_buff_manager;

typedef struct	s_fstring
{
	long	size;
	char	*str;
}				t_fstring;

typedef struct	s_norm_contain
{
	t_fstring	str1;
	t_fstring	str2;
	long		index;
	char		chr;
}				t_norm_contain;

typedef	struct	s_poub
{
	char			pad;
	long			awidth;
	long			i;
	long			cp[2];
	t_buff_manager	man;
	t_flag_mod		fl;
	t_fstring		s;
	t_fstring		p;
}				t_poub;

typedef t_buff_manager	(*t_put_func)(t_flag_mod, t_buff_manager, va_list);

t_fstring		ztr(char *str, long size);

void			ft_putstrf_fd(char *str, int fd, size_t size);
int				ft_iswhitespace(char c);
size_t			ft_strlen(const char *s);
int				ft_indexof(char needle, const char *hay);
int				ft_max(int a, int b);
long			ft_min_positive(long a, long b);
int				ft_max_of3(int a, int b, int c);

void			itoa_f(char *ret, long int nb, char *base);
long			ft_arg_abs(long n);

int				ft_printf(const char *format, ...);
int				read_format(t_buff_manager man, const char *format, va_list ap);
t_buff_manager	read_flags
(const char *format, t_buff_manager man, va_list ap, t_put_func *put_funcs);
t_buff_manager	conversion
(t_buff_manager man, t_flag_mod flags, t_fstring str, t_fstring prefix);
t_buff_manager	ft_fflush(t_buff_manager man);

t_buff_manager	put_c(t_flag_mod flags, t_buff_manager man, va_list ap);
t_buff_manager	put_s(t_flag_mod flags, t_buff_manager man, va_list ap);
t_buff_manager	put_p(t_flag_mod flags, t_buff_manager man, va_list ap);
t_buff_manager	put_d(t_flag_mod flags, t_buff_manager man, va_list ap);
t_buff_manager	put_u(t_flag_mod flags, t_buff_manager man, va_list ap);
t_buff_manager	put_x(t_flag_mod flags, t_buff_manager man, va_list ap);
t_buff_manager	put_up_x(t_flag_mod flags, t_buff_manager man, va_list ap);
t_buff_manager	put_percent(t_flag_mod flags, t_buff_manager man, va_list ap);

#endif
