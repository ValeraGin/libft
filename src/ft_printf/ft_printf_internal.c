/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_internal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmathew <hmathew@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 18:12:54 by hmathew           #+#    #+#             */
/*   Updated: 2019/11/11 22:10:03 by hmathew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_parser.h"

int	fill_values(t_specs *specs, va_list args)
{
	size_t		i;

	i = -1;
	while (specs->argtypes[++i])
		specs->argvalues[i] = get_argvalue(specs->argtypes[i], args);
	return (1);
}

int	fill_wildcard_order(t_spec *spec, t_specs *specs)
{
	int value;

	if (spec->flags & PF_FLAG_WIDTH_WILDCARD)
	{
		value = specs->argvalues[spec->order_w].pa_int;
		if (value >= 0)
			(spec->width == PF_NO_INIT) ? spec->width = value : 0;
		else
		{
			spec->flags |= PF_FLAG_MINUS;
			spec->width = -value;
		}
	}
	if (spec->flags & PF_FLAG_PREC_WILDCARD)
	{
		value = specs->argvalues[spec->order_p].pa_int;
		if (value >= 0)
		{
			if (spec->prec != PF_NO_INIT)
				spec->prec = value;
		}
		else
			spec->prec = PF_NO_INIT;
	}
	return (1);
}

int	print_specs(t_buff *bi, t_specs *specs)
{
	size_t	i;
	t_spec	*spec;

	i = -1;
	while (++i < specs->specs_count)
	{
		spec = specs->specs[i];
		if (!(spec->str_l))
		{
			if (!fill_wildcard_order(spec, specs))
				return (0);
			spec->arg_val = specs->argvalues[spec->order_t];
		}
		if (!print_specifier(bi, spec))
			return (0);
	}
	return (1);
}

int	free_specs(t_specs *specs, int ret)
{
	int i;

	i = -1;
	while (++i < (int)specs->specs_count)
		free(specs->specs[i]);
	return (ret);
}

int	printf_internal(t_buff *bi, const char *format, va_list args)
{
	t_specs	specs;
	int		i;

	ft_memset(specs.argtypes, 0, sizeof(specs.argtypes) / sizeof(char));
	ft_memset(specs.argvalues, 0, sizeof(specs.argvalues) / sizeof(char));
	ft_memset(specs.specs, 0, sizeof(specs.specs) / sizeof(char));
	specs.specs_count = 0;
	i = 3;
	if (format_parser(format, &specs) && --i)
		if (fill_values(&specs, args) && --i)
			(print_specs(bi, &specs) && --i);
	return (free_specs(&specs, bi->current));
}
