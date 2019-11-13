/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digits.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmathew <hmathew@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 17:15:55 by hmathew           #+#    #+#             */
/*   Updated: 2019/11/09 20:35:50 by hmathew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_plugins.h"
#include "digits.h"

void				fill_uint(unsigned long long value, t_print *dp,
														int prec, t_base *base)
{
	int					i;
	int					diff;
	unsigned long long	nc;

	i = ((prec != 0) || (value > 0));
	nc = value;
	while (nc /= base->len)
		++i;
	diff = (i < prec) ? prec - i : 0;
	dp->strlen = i + diff;
	while (i + diff != 0)
	{
		dp->str[--i + diff] = base->str[value % base->len];
		value /= base->len;
	}
}

void				init_dp(t_print *dp, char *str)
{
	dp->str = str;
	dp->strlen = 0;
	dp->str_need_free = 0;
	dp->sign = NULL;
	dp->signlen = 0;
	dp->sign_need_free = 1;
}

unsigned long long	get_value(t_spec *spec, int is_signed, int *is_neg)
{
	long long int		svalue;
	unsigned long long	value;

	if (is_signed)
	{
		svalue = get_arg_as_ll(spec);
		*is_neg = (svalue < 0);
		value = (*is_neg) ? -svalue : svalue;
	}
	else
		value = get_arg_as_ull(spec);
	return (value);
}

int					print_uint(t_buff *bi, t_spec *spec)
{
	unsigned long long	value;
	int					is_neg;
	t_print				dp;
	char				str[64];
	t_base				base;

	init_dp(&dp, str);
	base = get_base(spec);
	value = get_value(spec, base.is_signed, &is_neg);
	fill_uint(value, &dp, spec->prec, &base);
	if (base.is_signed)
		fill_sign_int(&dp, spec, is_neg);
	else if (
	((!(base.len == 8 && dp.str[0] == '0')) ||
		(base.len == 8 && spec->prec == 0))
	&&
	(!(value == 0 && base.len == 16 && !(spec->arg_type == PF_PA_POINTER))))
		fill_sign_uint(&dp, spec, base.len);
	return (write_width_sign(spec, bi, &dp));
}

int					arginfo_digits(t_spec *spec)
{
	int s;

	if (spec->ch == 'D')
		spec->mod = L;
	if (ft_tolower(spec->ch) == 'p')
	{
		spec->flags |= PF_FLAG_SHARP;
		return (PF_PA_POINTER);
	}
	s = 0;
	if (ft_tolower(spec->ch) != 'd' && ft_tolower(spec->ch) != 'i')
		s = PA_FLAG_UNSIGNED;
	return (PF_PA_INT | PA_FLAG_SIZE_START << (int)spec->mod | s);
}
