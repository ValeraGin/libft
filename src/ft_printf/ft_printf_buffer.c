/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_buffer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmathew <hmathew@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 17:06:15 by hmathew           #+#    #+#             */
/*   Updated: 2019/11/08 15:09:48 by hmathew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_buff	*buffer_init(t_buff *bi, char *s, int need_mem, int size_buf)
{
	bi->fd = FD_NO_INIT;
	bi->current = 0;
	bi->size = size_buf;
	if ((bi->need_mem = need_mem))
	{
		if (bi->size < 0)
			return (NULL);
		if (!(bi->buff = (char*)malloc(sizeof(char) * bi->size)))
			return (NULL);
	}
	else
	{
		bi->buff = s;
	}
	return (bi);
}

int		rebuild_buffer(t_buff *bi, int new_size)
{
	char	*new;

	new = NULL;
	if (!(new = (char *)malloc(sizeof(char) * new_size)))
		return (0);
	ft_memcpy(new, bi->buff, bi->current);
	free(bi->buff);
	bi->buff = new;
	bi->size = new_size;
	return (1);
}

int		check_size(t_buff *bi, int len)
{
	int		new_size;

	if (bi->size != BUFF_SIZE_INFINITY_PF)
	{
		new_size = bi->size;
		while (len > (new_size - bi->current))
			new_size += BUFF_SIZE_PF;
		if (new_size != bi->size)
		{
			if (bi->fd != FD_NO_INIT)
			{
				write(bi->fd, bi->buff, bi->current);
				bi->current = 0;
			}
			else if (!rebuild_buffer(bi, new_size))
				return (0);
		}
	}
	return (1);
}

int		buffer_fill_char(t_buff *bi, const char c, int len)
{
	if (!check_size(bi, len))
		return (0);
	while (len--)
		bi->buff[bi->current++] = c;
	return (1);
}

int		buffer_write(t_buff *bi, const char *s, int len)
{
	if (!check_size(bi, len))
		return (0);
	while (len--)
		bi->buff[bi->current++] = *(s++);
	return (1);
}
