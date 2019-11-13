/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digits_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmathew <hmathew@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:00:00 by hmathew           #+#    #+#             */
/*   Updated: 2019/11/09 15:54:42 by hmathew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "digits.h"

t_base	get_base(t_spec *spec)
{
	t_base	ret;
	char	c;

	ret.str = (ft_islower(spec->ch) ? HEX_L : HEX_U);
	c = ft_tolower(spec->ch);
	ret.is_signed = 0;
	if (c == 'b')
		ret.len = 2;
	else if (c == 'o')
		ret.len = 8;
	else if (c == 'u' || c == 'd' || c == 'i')
	{
		ret.is_signed = (c == 'd' || c == 'i');
		ret.len = 10;
	}
	else
		ret.len = 16;
	return (ret);
}
