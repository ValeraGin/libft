/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmathew <hmathew@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 21:48:34 by hmathew           #+#    #+#             */
/*   Updated: 2019/11/09 14:33:43 by hmathew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_putwchar_fd(wchar_t wc, int fd)
{
	int		len;
	char	convertion[4];

	len = ft_wchar_utf8(wc, convertion);
	write(fd, convertion, len);
	return (len);
}
