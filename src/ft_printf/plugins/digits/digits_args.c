/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digits_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmathew <hmathew@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:57:26 by hmathew           #+#    #+#             */
/*   Updated: 2019/11/11 20:54:10 by hmathew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long	get_arg_as_ull(t_spec *spec)
{
	int	type_m;

	type_m = ~PA_FLAG_MASK & spec->arg_type;
	if (type_m == PF_PA_POINTER)
		return ((unsigned long long)spec->arg_val.pa_pointer);
	else if (type_m == PF_PA_CHAR)
		return (spec->arg_val.pa_u_int);
	else if (type_m == PF_PA_INT)
	{
		if (spec->arg_type & PA_FLAG_LONG)
			return (spec->arg_val.pa_u_long_int);
		else if (spec->arg_type & PA_FLAG_LONG_LONG)
			return (spec->arg_val.pa_u_long_long_int);
		else if (spec->arg_type & PA_FLAG_SIZE_T)
			return (spec->arg_val.pa_size_t);
		else if (spec->arg_type & PA_FLAG_INTMAX)
			return (spec->arg_val.pa_uintmax_t);
	}
	return (spec->arg_val.pa_u_int);
}

long long			get_arg_as_ll(t_spec *spec)
{
	int	type_m;

	type_m = ~PA_FLAG_MASK & spec->arg_type;
	if (type_m == PF_PA_CHAR)
		return (spec->arg_val.pa_int);
	else if (type_m == PF_PA_INT)
	{
		if (spec->arg_type & PA_FLAG_LONG)
			return (spec->arg_val.pa_long_int);
		else if (spec->arg_type & PA_FLAG_LONG_LONG)
			return (spec->arg_val.pa_long_long_int);
		else if (spec->arg_type & PA_FLAG_SIZE_T)
			return (spec->arg_val.pa_size_t);
		else if (spec->arg_type & PA_FLAG_INTMAX)
			return (spec->arg_val.pa_intmax_t);
	}
	return (spec->arg_val.pa_int);
}
