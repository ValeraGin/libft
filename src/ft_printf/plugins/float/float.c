/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmathew <hmathew@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:03:52 by hmathew           #+#    #+#             */
/*   Updated: 2020/02/27 18:42:57 by hmathew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <float.h>
#include "ft_printf.h"
#include "ft_printf_plugins.h"
#include "float.h"

int		big_then_5(char *str, int last)
{
	if ((*str) == '.')
		str++;
	if ((*str) > '5')
		return (1);
	else if ((*str) == '5')
	{
		while (*(++str) == '0' && (*str))
			;
		if (*str)
			return (1);
		if (!*str)
			return (last % 2);
	}
	return (0);
}

char	*add_one(char *str, int i)
{
	if (i >= 0)
	{
		if (str[i] == '.')
			return (add_one(str, i - 1));
		else if (str[i] == '9')
		{
			str[i] = '0';
			return (add_one(str, i - 1));
		}
		else
		{
			str[i] += 1;
			return (str);
		}
	}
	else
		return (ft_strjoinc_wf(str, '1', 1, 1));
}

char	*build_float(long double value, int prec, t_print *dp, int needdot)
{
	char	*str;
	char	*newstr;
	int		i;
	int		last;

	float_process(value, 0, dp);
	str = dp->str;
	if (ft_isdigit(str[0]) && (!(str = ft_strjoinc_wf(str, '0', 0, 2))))
		return (0);
	i = 0;
	while (str[i] && str[i] != '.')
		i++;
	if (!str[i++])
		return (str);
	i += (prec == 0) ? !(needdot > 0) * -1 : prec;
	newstr = str;
	last = (str[i - 2] == '.') ? str[i - 2] - '0' : str[i - 1] - '0';
	if (big_then_5(&(str[i]), last))
		newstr = add_one(str, i - 1);
	str = ft_strndup(newstr, i + (newstr != str));
	ft_memdel((void**)&newstr);
	return (str);
}

int		print_float(t_buff *bi, t_spec *spec)
{
	long double	value;
	t_print		dp;

	if (spec->arg_type & PA_FLAG_LONG_DOUBLE)
		value = spec->arg_val.pa_long_double;
	else
		value = spec->arg_val.pa_double;
	dp.sign = NULL;
	dp.signlen =
	dp.sign_need_free = 0;
	dp.str = build_float(value, spec->prec, &dp, spec->flags & PF_FLAG_SHARP);
	dp.strlen = ft_strlen(dp.str);
	dp.str_need_free = 1;
	if (dp.signlen > 0)
		dp.sign = "-";
	else if (spec->flags & PF_FLAG_PLUS)
		dp.sign = "+";
	else if (spec->flags & PF_FLAG_SPACE)
		dp.sign = " ";
	dp.signlen = (dp.sign != NULL) * 1;
	if (ft_tolower(dp.str[0]) == 'n')
		dp.signlen = 0;
	write_width_sign(spec, bi, &dp);
	return (1);
}

int		arginfo_float(t_spec *spec)
{
	if (spec->prec == PF_NO_INIT)
		spec->prec = 6;
	return (PF_PA_DOUBLE | ((spec->mod == LM) ? PA_FLAG_LONG_DOUBLE : 0));
}
