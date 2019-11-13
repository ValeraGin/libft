/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmathew <hmathew@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 21:35:29 by hmathew           #+#    #+#             */
/*   Updated: 2019/11/11 22:10:29 by hmathew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_vdprintf(int fd, const char *format, va_list args)
{
	t_buff	bi;
	int		ret;

	buffer_init(&bi, NULL, 1, BUFF_SIZE_PF);
	bi.fd = fd;
	ret = printf_internal(&bi, format, args);
	write(fd, bi.buff, bi.current);
	free(bi.buff);
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	va_list	args;

	va_start(args, format);
	len = ft_vdprintf(STDOUT_FILENO, format, args);
	va_end(args);
	return (len);
}

int	ft_dprintf(int fd, const char *format, ...)
{
	int		len;
	va_list	args;

	va_start(args, format);
	len = ft_vdprintf(fd, format, args);
	va_end(args);
	return (len);
}
