/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parser.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmathew <hmathew@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 15:43:20 by hmathew           #+#    #+#             */
/*   Updated: 2019/11/08 20:14:47 by hmathew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_PARSER_H
# define FT_PRINTF_PARSER_H

# define COUNT_PARSE_FUNCTIONS 5

# include "ft_printf.h"

int		format_parser(const char *format, t_specs *specs_w_arg);
t_spec	*parse_specification(const char *str, size_t *i);
t_spec	*parse_specification_as_string(const char *str, size_t *i);

typedef int	(*t_parse_func)(t_spec *, const char *, size_t *);
int		parse_flags(t_spec *param, const char *str, size_t *i);
int		parse_width(t_spec *param, const char *str, size_t *i);
int		parse_precision(t_spec *param, const char *str, size_t *i);
int		parse_modifier(t_spec *param, const char *str, size_t *i);
int		parse_char(t_spec *param, const char *str, size_t *i);

int		parse_int(const char *str, size_t *i);

#endif
