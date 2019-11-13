/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_specifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmathew <hmathew@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 21:27:07 by hmathew           #+#    #+#             */
/*   Updated: 2019/11/11 20:36:10 by hmathew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_parser.h"

int		parse_int(const char *str, size_t *i)
{
	int nbr;
	int nbrtemp;

	nbr = 0;
	nbrtemp = 0;
	while (ft_isdigit(str[*i]))
	{
		nbrtemp = nbr * 10 + (str[(*i)++] - '0');
		if (nbrtemp < nbr)
			return (PF_NO_INIT);
		nbr = nbrtemp;
	}
	return (nbr);
}

t_spec	*memalloc_specification(void)
{
	t_spec	*param;

	if ((param = (t_spec *)ft_memalloc(sizeof(t_spec))) == NULL)
		return (NULL);
	param->flags = 0;
	param->width = PF_NO_INIT;
	param->prec = PF_NO_INIT;
	param->mod = NONE;
	param->ch = '\0';
	param->str_l = 0;
	param->order_w = PF_NO_INIT;
	param->order_p = PF_NO_INIT;
	param->order_t = PF_NO_INIT;
	return (param);
}

t_spec	*parse_specification_as_string(const char *str, size_t *i)
{
	t_spec	*param;
	int		start;

	if (!(param = memalloc_specification()))
		return (PF_PARSE_ERROR);
	start = *i;
	while (str[*i] && str[*i] != '%')
		(*i)++;
	param->str = (char*)str + start;
	param->str_l = *i - start;
	return (param);
}

t_spec	*parse_specification(const char *str, size_t *i)
{
	t_spec			*param;
	int				j;
	t_parse_func	parse_funcs[COUNT_PARSE_FUNCTIONS];

	parse_funcs[0] = parse_flags;
	parse_funcs[1] = parse_width;
	parse_funcs[2] = parse_precision;
	parse_funcs[3] = parse_modifier;
	parse_funcs[4] = parse_char;
	if (!(param = memalloc_specification()))
		return (PF_PARSE_ERROR);
	j = 0;
	while (j < COUNT_PARSE_FUNCTIONS)
		if ((parse_funcs[j++](param, str, i)) == PF_PARSE_ERROR)
		{
			free(param);
			return (PF_PARSE_ERROR);
		}
	return (param);
}
