/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_plugins.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmathew <hmathew@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 14:49:21 by hmathew           #+#    #+#             */
/*   Updated: 2019/11/08 20:43:46 by hmathew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_plugins.h"

int	register_builtin_types(void)
{
	const char *digits;

	digits = "dDiIbBoOxXuUp";
	while (*digits)
		register_ft_printf_function(*(digits++), print_uint, arginfo_digits);
	register_ft_printf_function('%', print_percent, arginfo_percent);
	register_ft_printf_function('c', print_char, arginfo_char);
	register_ft_printf_function('C', print_char, arginfo_char);
	register_ft_printf_function('s', print_string, arginfo_string);
	register_ft_printf_function('S', print_string, arginfo_string);
	register_ft_printf_function('f', print_float, arginfo_float);
	return (1);
}
