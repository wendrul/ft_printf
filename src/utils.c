/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 20:36:20 by ede-thom          #+#    #+#             */
/*   Updated: 2020/05/08 22:35:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putstrf_fd(char *str, int fd, size_t size)
{
	if (str != NULL && fd != -2)
		write(fd, str, size + 1);
}

int		ft_iswhitespace(char c)
{
	return (c == '\f' || c == '\t' ||
		c == '\n' || c == '\r' ||
		c == '\v' || c == ' ');
}

size_t	ft_strlen(char const *str)
{
	register char *cur;

	cur = (char *)str;
	while (*cur)
		cur++;
	return (cur - str);
}

int		ft_indexof(char needle, const char *hay)
{
	int i;

	i = -1;
	while (hay[++i])
		if (hay[i] == needle)
			return (i);
	return (-1);
}

int		ft_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}
