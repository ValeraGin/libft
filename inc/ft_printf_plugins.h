/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_plugins.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmathew <hmathew@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 15:47:55 by hmathew           #+#    #+#             */
/*   Updated: 2019/11/09 19:44:37 by hmathew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_PLUGINS_H
# define FT_PRINTF_PLUGINS_H

# include "ft_printf.h"

typedef struct	s_print
{
	char		*str;
	int			strlen;
	int			str_need_free;
	char		*sign;
	int			signlen;
	int			sign_need_free;
}				t_print;

int				register_builtin_types(void);

int				write_width(t_spec *param, t_buff *bi, t_print *dp);
int				write_width_sign(t_spec *param, t_buff *bi, t_print *dp);

int				print_string(t_buff *bi, t_spec *param);
int				arginfo_string(t_spec *param);
int				print_uint(t_buff *bi, t_spec *param);
int				arginfo_digits(t_spec *param);
int				print_percent(t_buff *bi, t_spec *param);
int				arginfo_percent(t_spec *param);
int				print_char(t_buff *bi, t_spec *param);
int				arginfo_char(t_spec *param);
int				print_float(t_buff *bi, t_spec *param);
int				arginfo_float(t_spec *param);

#endif
