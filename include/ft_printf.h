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

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <string.h>
# include <unistd.h>

# define FT_PRINTF_BUFF_SIZE 4096
# define FT_PRINTF_PADDING 100

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

void            ft_putstrf_fd(char *str, int fd);
int             ft_iswhitespace(char c);
size_t          ft_strlen(const char *s);
int	        ft_indexof(char needle, const char *hay);

t_buff_manager  ft_fflush(t_buff_manager man);
int             ft_printf(const char *format, ...);
int             read_format(t_buff_manager man, const char *format, va_list ap);
void            ft_putstrf_fd(char *str, int fd);
t_buff_manager  read_flags(const char *format, t_buff_manager man, va_list ap, t_put_func *put_funcs);

t_buff_manager  put_c(t_flag_mod flags, t_buff_manager man, va_list ap);

#endif