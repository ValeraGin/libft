/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar_utf8.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmathew <hmathew@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:32:22 by hmathew           #+#    #+#             */
/*   Updated: 2019/11/09 15:08:10 by hmathew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wchar_utf8(wchar_t wc, char *s)
{
	int		len;

	len = 0;
	if (wc <= 0xFF)
		s[len++] = wc;
	else if (wc < 0x0800)
	{
		s[len++] = ((wc >> 6) & 0x1F) | 0xC0;
		s[len++] = ((wc >> 0) & 0x3F) | 0x80;
	}
	else if (wc < 0x010000)
	{
		s[len++] = ((wc >> 12) & 0x0F) | 0xE0;
		s[len++] = ((wc >> 6) & 0x3F) | 0x80;
		s[len++] = ((wc >> 0) & 0x3F) | 0x80;
	}
	else if (wc < 0x110000)
	{
		s[len++] = ((wc >> 18) & 0x07) | 0xF0;
		s[len++] = ((wc >> 12) & 0x3F) | 0x80;
		s[len++] = ((wc >> 6) & 0x3F) | 0x80;
		s[len++] = ((wc >> 0) & 0x3F) | 0x80;
	}
	return (len);
}
