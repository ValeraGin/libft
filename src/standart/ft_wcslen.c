/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcslen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmathew <hmathew@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 23:23:34 by hmathew           #+#    #+#             */
/*   Updated: 2019/11/09 15:48:28 by hmathew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wcslen(const wchar_t *wcs)
{
	size_t	len;

	len = 0;
	while (*wcs)
	{
		len += ft_wclen(*wcs);
		wcs += 1;
	}
	return (len);
}
