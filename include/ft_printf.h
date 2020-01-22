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
# include "libft.h"

# define FT_PRINTF_BUFF_SIZE 4096

int     ft_printf(const char *format, ...);
int     read_format(int fd, char *print_buf, const char *format, va_list ap);
void    ft_putstrf_fd(char *str, int fd);

typedef struct  s_flag_mod
{
    
}               t_flag_mod;

#endif