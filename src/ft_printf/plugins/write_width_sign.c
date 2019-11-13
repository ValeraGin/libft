/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_width_sign.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmathew <hmathew@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:06:03 by hmathew           #+#    #+#             */
/*   Updated: 2019/11/11 16:29:37 by hmathew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_plugins.h"

char	get_space_char(t_spec *spec, t_print *dp)
{
	return ((spec->flags & PF_FLAG_ZERO)
	&&
	(spec->prec == PF_NO_INIT || !ft_strchr("diouxs", ft_tolower(spec->ch)))
	&&
	!(ft_tolower(dp->str[0]) == 'n' || ft_tolower(dp->str[0]) == 'i'))
	? '0' : ' ';
}

int		write_width_sign(t_spec *spec, t_buff *bi, t_print *dp)
{
	int		len_p;
	char	c;

	c = get_space_char(spec, dp);
	len_p = spec->width - dp->strlen - dp->signlen;
	if (len_p > 0)
	{
		if (c == '0')
			buffer_write(bi, dp->sign, dp->signlen);
		if (!(spec->flags & PF_FLAG_MINUS))
			buffer_fill_char(bi, c, len_p);
		if (c == ' ')
			buffer_write(bi, dp->sign, dp->signlen);
		buffer_write(bi, dp->str, dp->strlen);
		if ((spec->flags & PF_FLAG_MINUS))
			buffer_fill_char(bi, ' ', len_p);
	}
	else
	{
		buffer_write(bi, dp->sign, dp->signlen);
		buffer_write(bi, dp->str, dp->strlen);
	}
	(dp->sign_need_free) ? ft_memdel((void**)&(dp->sign)) : (void)0;
	(dp->str_need_free) ? ft_memdel((void**)&(dp->str)) : (void)0;
	return (1);
}

int		write_width(t_spec *spec, t_buff *bi, t_print *dp)
{
	dp->sign = NULL;
	dp->signlen = 0;
	dp->sign_need_free = 0;
	return (write_width_sign(spec, bi, dp));
}
