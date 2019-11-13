/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmathew <hmathew@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 14:41:52 by hmathew           #+#    #+#             */
/*   Updated: 2019/11/11 16:27:31 by hmathew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_plugins.h"

int	print_wstring(const wchar_t *wstr, t_buff *bi, t_spec *spec)
{
	int		i_wc;
	t_print	dp;

	dp.str_need_free = 1;
	dp.strlen = 0;
	i_wc = 0;
	if (!(dp.str = (char *)malloc(sizeof(char) * ft_wcslen(wstr))))
		return (0);
	while (*(wstr))
	{
		dp.strlen += ft_wchar_utf8(*(wstr++), &(dp.str[dp.strlen]));
		if ((spec->prec != PF_NO_INIT) && (spec->prec == ++i_wc))
			break ;
	}
	return (write_width(spec, bi, &dp));
}

int	print_string(t_buff *bi, t_spec *spec)
{
	t_print	dp;

	if (spec->arg_val.pa_string == NULL)
	{
		dp.str = "(null)";
		dp.strlen = (spec->prec == PF_NO_INIT) ? 6 : FT_MIN(spec->prec, 6);
		dp.str_need_free = 0;
		write_width(spec, bi, &dp);
	}
	else if ((spec->arg_type & ~PA_FLAG_MASK) == PF_PA_STRING)
	{
		dp.str = (char*)spec->arg_val.pa_string;
		dp.strlen = ft_strlen(spec->arg_val.pa_string);
		dp.str_need_free = 0;
		if ((spec->prec != PF_NO_INIT) && (spec->prec < dp.strlen))
			dp.strlen = spec->prec;
		write_width(spec, bi, &dp);
	}
	else if ((spec->arg_type & ~PA_FLAG_MASK) == PF_PA_WSTRING)
		return (print_wstring(spec->arg_val.pa_wstring, bi, spec));
	return (0);
}

int	arginfo_string(t_spec *param)
{
	if ((param->mod == L) | (param->ch == 'S'))
		return (PF_PA_WSTRING);
	else
		return (PF_PA_STRING);
}
