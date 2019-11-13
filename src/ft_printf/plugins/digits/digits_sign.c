/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digits_sign.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmathew <hmathew@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:58:36 by hmathew           #+#    #+#             */
/*   Updated: 2019/11/09 20:30:11 by hmathew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_plugins.h"

void	fill_sign_uint(t_print *dp, t_spec *spec, int baselen)
{
	if (spec->flags & PF_FLAG_SHARP)
	{
		dp->sign = ft_islower(spec->ch) ? "0x" : "0X";
		dp->sign_need_free = 0;
		dp->signlen = (baselen >= 8) + (baselen >= 16);
	}
}

void	fill_sign_int(t_print *dp, t_spec *spec, int is_neg)
{
	dp->sign = NULL;
	dp->signlen = 0;
	dp->sign_need_free = 0;
	if (is_neg)
		dp->sign = "-";
	else if (spec->flags & PF_FLAG_PLUS)
		dp->sign = "+";
	else if (spec->flags & PF_FLAG_SPACE)
		dp->sign = " ";
	dp->signlen = (dp->sign != NULL) * 1;
}
