/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmathew <hmathew@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:22:41 by hmathew           #+#    #+#             */
/*   Updated: 2019/11/11 16:29:14 by hmathew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				get_argvalue_int(int type, union u_arg_value *ret,
																	va_list arg)
{
	if (type & PA_FLAG_CHAR)
	{
		if (type & PA_FLAG_UNSIGNED)
			(*ret).pa_u_int = (unsigned char)va_arg(arg, unsigned int);
		else
			(*ret).pa_int = (char)va_arg(arg, unsigned int);
	}
	else if (type & PA_FLAG_SHORT)
	{
		if (type & PA_FLAG_UNSIGNED)
			(*ret).pa_u_int = (unsigned short)va_arg(arg, unsigned int);
		else
			(*ret).pa_int = (short)va_arg(arg, unsigned int);
	}
	else if (type & PA_FLAG_LONG)
		(*ret).pa_u_long_int = va_arg(arg, unsigned long);
	else if (type & PA_FLAG_LONG_LONG)
		(*ret).pa_u_long_long_int = va_arg(arg, unsigned long long);
	else if (type & PA_FLAG_SIZE_T)
		(*ret).pa_size_t = va_arg(arg, size_t);
	else if (type & PA_FLAG_INTMAX)
		(*ret).pa_uintmax_t = va_arg(arg, uintmax_t);
	else
		(*ret).pa_u_int = va_arg(arg, unsigned int);
}

void				get_argvalue_double(int type, union u_arg_value *ret,
																	va_list arg)
{
	if (type & PA_FLAG_LONG_DOUBLE)
		(*ret).pa_long_double = va_arg(arg, long double);
	else
		(*ret).pa_double = va_arg(arg, double);
}

union u_arg_value	get_argvalue(int type, va_list arg)
{
	union u_arg_value	ret;
	int					main_type;

	main_type = ~PA_FLAG_MASK & type;
	ret.pa_long_double = 0;
	if (main_type == PF_PA_CHAR)
	{
		if (PA_FLAG_CHAR)
			ret.pa_char = (char)va_arg(arg, unsigned int);
		else
			ret.pa_u_char = (unsigned char)va_arg(arg, unsigned int);
	}
	else if (main_type == PF_PA_INT)
		get_argvalue_int(type, &ret, arg);
	else if (main_type == PF_PA_DOUBLE)
		get_argvalue_double(type, &ret, arg);
	else if (main_type == PF_PA_STRING)
		ret.pa_string = va_arg(arg, const char *);
	else if (main_type == PF_PA_WCHAR)
		ret.pa_wchar = va_arg(arg, wchar_t);
	else if (main_type == PF_PA_WSTRING)
		ret.pa_wstring = va_arg(arg, wchar_t *);
	else if (main_type == PF_PA_POINTER)
		ret.pa_pointer = va_arg(arg, void *);
	return (ret);
}
