/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmathew <hmathew@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 14:41:52 by hmathew           #+#    #+#             */
/*   Updated: 2019/11/09 20:08:15 by hmathew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_plugins.h"

int		print_percent(t_buff *bi, t_spec *spec)
{
	t_print dp;

	dp.str = "%";
	dp.strlen = 1;
	dp.str_need_free = 0;
	write_width(spec, bi, &dp);
	return (1);
}

int		arginfo_percent(t_spec *spec)
{
	(void)spec;
	return (0);
}
