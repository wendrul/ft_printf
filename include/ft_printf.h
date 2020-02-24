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

void    ft_putstrf_fd(char *str, int fd);
int     ft_iswhitespace(char c);
size_t  ft_strlen(const char *s);
int	ft_indexof(char needle, const char *hay);


int     ft_printf(const char *format, ...);
int     read_format(int fd, char *print_buf, const char *format, va_list ap);
void    ft_putstrf_fd(char *str, int fd);
int     read_flags(const char *format, int *j, char *buf, int fd, va_list ap);


typedef struct  s_flag_mod
{
        int     zero_padding;
        int     left_adjust;
        int     precision;
}               t_flag_mod;

typedef struct  s_buff_manager
{
        int     fd;
        char    *buf;
        int     buf_cur;
        int     form_cur;
        int     total_count;
}               t_buff_manager;

#endif