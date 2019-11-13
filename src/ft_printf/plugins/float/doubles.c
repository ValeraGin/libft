/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmathew <hmathew@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:54:20 by hmathew           #+#    #+#             */
/*   Updated: 2019/11/11 20:56:09 by hmathew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "float.h"
#include <float.h>

char	*get_result_str(t_bnbr input, int pow, short bit)
{
	char	*res;
	size_t	i;

	i = 0;
	while (i < MAX_LEN_BNBR)
		input.num[i++] += '0';
	i = 0;
	while (input.num[i] == '0')
		i++;
	if (bit)
		i = MAX_LEN_BNBR - 64 - pow;
	res = ft_strdup(&input.num[i]);
	return (res);
}

char	*get_intpart(int pow, unsigned long int mant, int exp)
{
	t_bnbr	res;
	t_bnbr	add;

	res = bnbr_new(0);
	add = bnbr_new(1);
	if (exp <= 0)
		return (ft_memset(ft_strnew(2), '0', 1));
	while (pow-- > 0)
		bnbr_sum(&add, add);
	while (mant > 0)
	{
		if (mant & 1)
			bnbr_sum(&res, add);
		bnbr_sum(&add, add);
		mant >>= 1;
	}
	return (get_result_str(res, pow, 0));
}

char	*get_fractpart(int pow, unsigned long int mant)
{
	int		i;
	t_bnbr	five;
	t_bnbr	two;
	t_bnbr	res;

	res = bnbr_new(0);
	five = bnbr_new(5);
	two = bnbr_new(2);
	five = bnbr_power(64 + pow, five);
	i = 0;
	while (++i <= 64)
	{
		if (mant & 0x8000000000000000)
			bnbr_sum(&res, bnbr_mult(five,
				bnbr_power(64 - i + (pow == 0 ? 0 : 1), two)));
		mant <<= 1;
	}
	return (get_result_str(res, pow, 1));
}

int		check_double(union u_double *d, t_print *dp, int isupcase)
{
	if (d->parts.sign == 1 || d->ld < 0)
	{
		dp->sign = "-";
		dp->signlen = 1;
	}
	d->ld = (d->ld == LDBL_MIN || d->ld == DBL_MIN) ? 0 : d->ld;
	d->ld = (d->ld == -LDBL_MIN || d->ld == -DBL_MIN) ? -0 : d->ld;
	if (d->ld != d->ld)
	{
		dp->str = ft_strdup((isupcase) ? "NAN" : "nan");
		dp->strlen = 3;
		dp->signlen = 0;
	}
	else if (d->ld == 1.0 / 0.0 || d->ld == -1.0 / 0.0)
	{
		dp->str = ft_strdup((isupcase) ? "INF" : "inf");
		dp->strlen = 3;
	}
	else
		return (0);
	return (1);
}

int		float_process(long double value, int isupcase, t_print *dp)
{
	union u_double		d;
	int					exp;
	int					pow;
	unsigned long int	mant;

	d.ld = value;
	if (check_double(&d, dp, isupcase))
		return (1);
	exp = d.parts.exp == 0 ? 0 : d.parts.exp - 16382;
	pow = 0;
	if (exp > 0 && exp < 65)
		mant = d.parts.mant >> (64 - exp);
	else
		pow = exp <= 0 ? -exp + 1 : exp - 64;
	dp->str = get_intpart(pow, exp > 64 ? d.parts.mant : mant, exp);
	dp->str = ft_strjoinc_wf(dp->str, '.', 0, 1);
	if (exp < 64)
		dp->str = ft_strjoin_wf(dp->str,
			get_fractpart(pow, d.parts.mant << (FT_MAX(exp, 0))), 2);
	return (1);
}
