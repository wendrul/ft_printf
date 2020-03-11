/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-thom <ede-thom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 01:46:42 by ede-thom          #+#    #+#             */
/*   Updated: 2020/03/11 23:51:16 by ede-thom         ###   ########.fr       */
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

static int	what_pow(unsigned long int nb, int b)
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

static void	fill_ret(int size, char *ret, unsigned long int n, char *base)
{
	int		i;
	int		b;

	b = ft_strlen(base);
	ret[size] = '\0';
	i = 0;
	if (size - what_pow(n, b) == 1 && size != 0)
	{
		size--;
		ret[i++] = '-';
	}
	while (size)
	{
		size--;
		ret[i] = base[n / ft_pow(b, size)];
		n = n % ft_pow(b, size);
		i++;
	}
}

void		itoa_f(char *ret, long int nb, char *base)
{
	unsigned long int	n;
	int				size;

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
