/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-thom <ede-thom@42.edu.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 13:25:40 by ede-thom          #+#    #+#             */
/*   Updated: 2020/05/26 13:26:04 by ede-thom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

unsigned long int	ft_pow(unsigned long int nb, int pow)
{
	if (pow < 0)
		return (0);
	if (pow == 0)
		return (1);
	if (pow % 2 == 0)
		return (ft_pow(nb * nb, pow / 2));
	else
		return (nb * ft_pow(nb, pow - 1));
}

static int			what_pow(unsigned long int nb, int b)
{
	int			pow;

	pow = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		pow++;
		nb /= b;
	}
	return (pow);
}

static void			fill_ret(int size, char *ret, unsigned long int n, char *b)
{
	int		i;
	int		blen;

	blen = ft_strlen(b);
	ret[size] = '\0';
	i = 0;
	if (size - what_pow(n, blen) == 1 && size != 0)
	{
		size--;
		ret[i++] = '-';
	}
	while (size)
	{
		size--;
		ret[i] = b[n / ft_pow(blen, size)];
		n = n % ft_pow(blen, size);
		i++;
	}
}

void				itoa_f(char *ret, long int nb, char *base)
{
	unsigned long int	n;
	int					size;

	if (nb < 0)
	{
		n = -nb;
		size = 1;
	}
	else
	{
		n = nb;
		size = 0;
	}
	size += what_pow(n, ft_strlen(base));
	fill_ret(size, ret, n, base);
}
