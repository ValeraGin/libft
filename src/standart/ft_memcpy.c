/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmathew <hmathew@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 23:22:09 by hmathew           #+#    #+#             */
/*   Updated: 2019/09/10 17:42:11 by hmathew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dst_p;

	if (!dst && !src)
		return (NULL);
	dst_p = (unsigned char *)dst;
	while (n--)
		*dst_p++ = *(unsigned char *)src++;
	return (dst);
}
