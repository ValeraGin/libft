/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmathew <hmathew@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:33:25 by hmathew           #+#    #+#             */
/*   Updated: 2019/11/11 22:10:13 by hmathew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_vsprintf(char *s, const char *format, va_list args)
{
	t_buff bi;

	buffer_init(&bi, s, 0, BUFF_SIZE_INFINITY_PF);
	return (printf_internal(&bi, format, args));
}

int	ft_sprintf(char *s, const char *format, ...)
{
	int		len;
	va_list	args;

	va_start(args, format);
	len = ft_vsprintf(s, format, args);
	va_end(args);
	return (len);
}
