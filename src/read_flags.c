/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-thom <ede-thom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 20:41:59 by ede-thom          #+#    #+#             */
/*   Updated: 2020/01/11 20:41:59 by ede-thom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     read_flags(char *format, int *j, char *buf)
{
    int i;

    i = -1;
    while (!ft_iswhitespace(format[++i]))
    {
        
    }
    return (i);
}