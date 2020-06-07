/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-thom <ede-thom@42.edu.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 13:28:56 by ede-thom          #+#    #+#             */
/*   Updated: 2020/05/26 13:28:56 by ede-thom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_max_of3(int a, int b, int c)
{
	int max;

	max = a;
	if (max < b)
		max = b;
	if (max < c)
		max = c;
	return (max);
}

long		ft_min_positive(long a, long b)
{
	if (b < 0 && a < 0)
		return (0);
	if (a < 0)
		return (b);
	if (b < 0)
		return (a);
	if (a < b)
		return (a);
	else
		return (b);
}

t_fstring	ztr(char *str, long size)
{
	t_fstring string;

	string.str = str;
	string.size = size;
	return (string);
}
