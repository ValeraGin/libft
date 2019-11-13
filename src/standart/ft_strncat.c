/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmathew <hmathew@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 17:31:36 by hmathew           #+#    #+#             */
/*   Updated: 2019/09/06 18:29:51 by hmathew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	int		len;
	int		i;

	len = ft_strlen(dest);
	i = -1;
	while (src[++i] && n-- > 0)
		dest[len + i] = src[i];
	dest[len + i] = '\0';
	return (dest);
}
