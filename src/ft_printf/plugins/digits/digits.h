/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digits.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmathew <hmathew@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 17:13:10 by hmathew           #+#    #+#             */
/*   Updated: 2019/11/08 17:32:19 by hmathew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIGITS_H
# define DIGITS_H

# include "ft_printf.h"
# include "ft_printf_plugins.h"
# define HEX_U "0123456789ABCDEF"
# define HEX_L "0123456789abcdef"

typedef struct		s_base
{
	char	*str;
	int		len;
	int		is_signed;
}					t_base;

t_base				get_base(t_spec *param);
unsigned long long	get_arg_as_ull(t_spec *param);
long long			get_arg_as_ll(t_spec *param);
void				fill_sign_uint(t_print *dp, t_spec *param, int baselen);
void				fill_sign_int(t_print *dp, t_spec *param, int is_neg);

#endif
