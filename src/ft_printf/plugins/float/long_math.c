/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_math.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmathew <hmathew@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:40:23 by hmathew           #+#    #+#             */
/*   Updated: 2019/11/11 16:10:44 by hmathew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "float.h"

t_bnbr	bnbr_new(char n)
{
	t_bnbr	res;

	res.cap = MAX_LEN_BNBR - 1;
	ft_memset(res.num, 0, MAX_LEN_BNBR + 1);
	res.num[MAX_LEN_BNBR - 1] = n;
	return (res);
}

void	bnbr_sum(t_bnbr *n1, t_bnbr n2)
{
	unsigned long long	i;
	size_t				extr;

	i = MAX_LEN_BNBR;
	extr = 0;
	while (--i >= n1->cap || i >= n2.cap)
	{
		if ((n1->num[i] += n2.num[i] + extr) > 9)
		{
			n1->num[i] -= 10;
			extr = 1;
		}
		else
			extr = 0;
	}
	n1->cap = n1->cap <= n2.cap ? n1->cap : n2.cap;
	if (extr > 0)
	{
		n1->cap--;
		n1->num[i] = extr;
	}
}

void	bnbr_mult_n(t_bnbr *r, t_bnbr n1, char n2, size_t shift)
{
	size_t old;
	size_t new;
	size_t i;

	old = 0;
	i = MAX_LEN_BNBR - 1 - shift;
	while (i <= MAX_LEN_BNBR - 1)
		r->num[i++] = 0;
	i = MAX_LEN_BNBR;
	while (--i >= n1.cap)
	{
		new = (n1.num[i] * n2 + old) / 10;
		r->num[i - shift] = (n1.num[i] * n2 + old) % 10;
		old = new;
	}
	r->cap = n1.cap - shift;
	if (old > 0)
	{
		r->cap--;
		r->num[i - shift] = old;
	}
}

t_bnbr	bnbr_mult(t_bnbr n1, t_bnbr n2)
{
	t_bnbr	l1;
	t_bnbr	l2;
	size_t	i;
	size_t	shift;

	l1 = bnbr_new(0);
	l2 = bnbr_new(0);
	i = MAX_LEN_BNBR;
	shift = 0;
	while (--i >= n2.cap)
	{
		bnbr_mult_n(&l2, n1, n2.num[i], shift++);
		bnbr_sum(&l1, l2);
	}
	return (l1);
}

t_bnbr	bnbr_power(size_t pow, t_bnbr n)
{
	size_t	i;
	t_bnbr	res;

	i = 0;
	res = bnbr_new(n.num[MAX_LEN_BNBR - 1]);
	while (++i < pow)
	{
		res = bnbr_mult(res, n);
	}
	return (res);
}
