/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmathew <hmathew@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 14:41:52 by hmathew           #+#    #+#             */
/*   Updated: 2019/11/09 20:09:16 by hmathew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_plugins.h"

int		print_char(t_buff *bi, t_spec *spec)
{
	char	wchar_b[4];
	t_print dp;

	if ((spec->arg_type & ~PA_FLAG_MASK) == PF_PA_CHAR)
	{
		dp.str = (char*)&(spec->arg_val.pa_char);
		dp.strlen = 1;
		dp.str_need_free = 0;
		return (write_width(spec, bi, &dp));
	}
	else if ((spec->arg_type & ~PA_FLAG_MASK) == PF_PA_WCHAR)
	{
		dp.str = wchar_b;
		dp.strlen = ft_wchar_utf8(spec->arg_val.pa_wchar, dp.str);
		dp.str_need_free = 0;
		return (write_width(spec, bi, &dp));
	}
	return (1);
}

int		arginfo_char(t_spec *spec)
{
	if ((spec->mod == L) | (spec->ch == 'C'))
		return (PF_PA_WCHAR);
	else
		return (PF_PA_CHAR);
}
