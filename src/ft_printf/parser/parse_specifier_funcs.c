/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_specifier_funcs.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmathew <hmathew@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:10:59 by hmathew           #+#    #+#             */
/*   Updated: 2019/11/09 12:25:13 by hmathew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_parser.h"

int	parse_flags(t_spec *param, const char *str, size_t *i)
{
	char	*s;
	char	*c;
	int		order;
	int		start;

	start = *i;
	order = parse_int(str, i);
	if (str[(*i)] == '$' && ++(*i))
		param->order_t = order - 1;
	else
		*i = start;
	s = PF_FLAG_STRING;
	while (str[*i] && (c = ft_strchr(s, str[*i])))
		param->flags |= 1 << (c - s + (++(*i) * 0));
	return (PF_PARSE_OK);
}

int	parse_width(t_spec *param, const char *str, size_t *i)
{
	if (str[*i] && str[*i] == '*' && ++(*i))
		param->flags |= PF_FLAG_WIDTH_WILDCARD;
	if (str[*i] && ft_isdigit(str[*i]))
	{
		param->width = parse_int(str, i);
		if ((param->flags & PF_FLAG_WIDTH_WILDCARD)
				&& str[(*i)] == '$' && ++(*i))
		{
			param->order_w = param->width - 1;
			param->width = PF_NO_INIT;
		}
	}
	return (PF_PARSE_OK);
}

int	parse_precision(t_spec *param, const char *str, size_t *i)
{
	if (str[*i] && str[*i] == '.' && ++(*i))
	{
		param->prec = 0;
		if (str[*i] == '*' && ++(*i))
		{
			param->flags |= PF_FLAG_PREC_WILDCARD;
		}
		if (ft_isdigit(str[*i]))
		{
			param->prec = parse_int(str, i);
			if ((param->flags & PF_FLAG_PREC_WILDCARD) &&
						str[(*i)] == '$' && ++(*i))
			{
				param->order_p = param->prec - 1;
				param->prec = PF_NO_INIT;
			}
		}
	}
	return (PF_PARSE_OK);
}

int	parse_modifier(t_spec *param, const char *str, size_t *i)
{
	if (str[*i] == 'l')
		param->mod = (str[*i + 1] == 'l') ? LL : L;
	else if (str[*i] == 'h')
		param->mod = (str[*i + 1] == 'h') ? HH : H;
	else if (str[*i] == 'j')
		param->mod = J;
	else if (str[*i] == 'z')
		param->mod = Z;
	else if (str[*i] == 'L')
		param->mod = LM;
	else
		return (PF_PARSE_OK);
	(param->mod == LL || param->mod == HH) ? (*i) += 2 : (*i)++;
	return (PF_PARSE_OK);
}

int	parse_char(t_spec *p, const char *str, size_t *i)
{
	t_plugin *arr_funcs;

	arr_funcs = get_plugins();
	if (str[*i] && (arr_funcs[(int)str[*i]].print_func != NULL))
	{
		p->ch = str[(*i)++];
		return (PF_PARSE_OK);
	}
	else
		return (PF_PARSE_ERROR);
}
