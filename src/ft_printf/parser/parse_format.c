/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmathew <hmathew@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:54:35 by hmathew           #+#    #+#             */
/*   Updated: 2019/11/11 20:41:00 by hmathew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_parser.h"

int	fill_type(int *argtypes, int *order_p, size_t *order, int argtype)
{
	if ((*order_p) != PF_NO_INIT && ((*order) == (size_t)PF_NO_INIT))
	{
		if (argtypes[(*order_p)] == 0)
			argtypes[(*order_p)] = argtype;
		else
			return (0);
	}
	else if ((*order_p) == PF_NO_INIT)
	{
		if (argtypes[++(*order)] == 0)
		{
			argtypes[(*order)] = argtype;
			*order_p = (*order);
		}
		else
			return (0);
	}
	else
		return (0);
	return (1);
}

int	fill_types_spec(int *argtypes, t_spec *param, size_t *order)
{
	if (param->flags & PF_FLAG_WIDTH_WILDCARD)
		if (!fill_type(argtypes, &(param->order_w), order, PF_PA_INT))
			return (0);
	if (param->flags & PF_FLAG_PREC_WILDCARD)
		if (!fill_type(argtypes, &(param->order_p), order, PF_PA_INT))
			return (0);
	param->arg_type = get_arginfo(param);
	if (param->arg_type)
		if (!fill_type(argtypes, &(param->order_t), order, param->arg_type))
			return (0);
	return (1);
}

int	format_parser(const char *format, t_specs *specs_w_arg)
{
	t_spec		*param;
	size_t		i;
	size_t		order;

	i = 0;
	specs_w_arg->specs_count = 0;
	order = PF_NO_INIT;
	while (format[i])
	{
		if ((format[i] == '%') && (++i))
			param = parse_specification(format, &i);
		else
			param = parse_specification_as_string(format, &i);
		if (param == PF_PARSE_ERROR)
			return (0);
		else
			specs_w_arg->specs[specs_w_arg->specs_count++] = param;
		if (!(param->str_l))
			if (!fill_types_spec(specs_w_arg->argtypes, param, &order))
				return (0);
	}
	return (1);
}
