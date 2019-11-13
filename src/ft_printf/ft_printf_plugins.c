/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_plugins.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmathew <hmathew@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:25:01 by hmathew           #+#    #+#             */
/*   Updated: 2019/11/08 20:43:35 by hmathew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_plugins.h"

t_plugin	*get_plugins(void)
{
	static t_plugin	arr_funcs[MAX_SPEC];
	static int		is_init;

	if (!is_init)
	{
		is_init = 1;
		register_builtin_types();
	}
	return (arr_funcs);
}

int			register_ft_printf_function(int ch, t_print_function print_func,
													t_arginfo_func arginfo_func)
{
	t_plugin	*arr_funcs;

	arr_funcs = get_plugins();
	arr_funcs[ch].arginfo_func = arginfo_func;
	arr_funcs[ch].print_func = print_func;
	return (1);
}

int			print_specifier(t_buff *bi, t_spec *spec)
{
	t_plugin *arr_funcs;

	if (spec->str_l)
	{
		buffer_write(bi, spec->str, spec->str_l);
	}
	else
	{
		arr_funcs = get_plugins();
		if (arr_funcs[(int)spec->ch].print_func)
			arr_funcs[(int)spec->ch].print_func(bi, spec);
	}
	return (1);
}

int			get_arginfo(t_spec *spec)
{
	t_plugin *arr_funcs;

	arr_funcs = get_plugins();
	if (arr_funcs[(int)spec->ch].arginfo_func)
		return (arr_funcs[(int)spec->ch].arginfo_func(spec));
	return (0);
}
