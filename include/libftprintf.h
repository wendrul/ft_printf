/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-thom <ede-thom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 20:33:35 by ede-thom          #+#    #+#             */
/*   Updated: 2020/01/11 20:33:35 by ede-thom         ###   ########.fr       */
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

typedef struct  s_flag_mod
{
        int     zero_padding;
        int     left_adjust;
        int     precision;
        int     width;
}               t_flag_mod;

typedef struct  s_buff_manager
{
        int     fd;
        char    *buf;
        int     buf_cur;  /*buffer cursor*/
        int     form_cur; /*format cursor*/
        int     total_count; /*total characters printed*/
        int     buf_size;
}               t_buff_manager;

typedef t_buff_manager (*t_put_func)(t_flag_mod, t_buff_manager, va_list ap);

void            ft_putstrf_fd(char *str, int fd, size_t size);
int             ft_iswhitespace(char c);
size_t          ft_strlen(const char *s);
int	        ft_indexof(char needle, const char *hay);
int		ft_max(int a, int b);
int             ft_max_of3(int a, int b, int c);
void            itoa_f(char *ret, long int nb, char *base);

int             ft_printf(const char *format, ...);
int             read_format(t_buff_manager man, const char *format, va_list ap);
t_buff_manager  read_flags(const char *format, t_buff_manager man, va_list ap, t_put_func *put_funcs);
t_buff_manager  big_conversion(t_buff_manager man, t_flag_mod flags, char *str, size_t str_size);
t_buff_manager  normal_conversion(t_buff_manager man, t_flag_mod flags, char *str, size_t str_size);
t_buff_manager  ft_fflush(t_buff_manager man);

t_buff_manager  put_c(t_flag_mod flags, t_buff_manager man, va_list ap);
t_buff_manager  put_s(t_flag_mod flags, t_buff_manager man, va_list ap);
t_buff_manager  put_p(t_flag_mod flags, t_buff_manager man, va_list ap);
t_buff_manager  put_d(t_flag_mod flags, t_buff_manager man, va_list ap);
t_buff_manager  put_u(t_flag_mod flags, t_buff_manager man, va_list ap);
t_buff_manager  put_x(t_flag_mod flags, t_buff_manager man, va_list ap);
t_buff_manager  put_X(t_flag_mod flags, t_buff_manager man, va_list ap);
t_buff_manager  put_percent(t_flag_mod flags, t_buff_manager man, va_list ap);

#endif