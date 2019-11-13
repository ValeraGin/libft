/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmathew <hmathew@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 23:17:13 by hmathew           #+#    #+#             */
/*   Updated: 2019/11/09 15:49:41 by hmathew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putwstr_fd(const wchar_t *wcs, int fd)
{
	int		len;

	len = 0;
	while (*wcs)
	{
		ft_putwchar_fd(*wcs, fd);
		len += ft_wclen(*wcs);
		wcs += 1;
	}
	return (len);
}
