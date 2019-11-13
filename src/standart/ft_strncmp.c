/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmathew <hmathew@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 20:49:15 by hmathew           #+#    #+#             */
/*   Updated: 2019/09/11 19:29:31 by hmathew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*u_s1;
	unsigned char	*u_s2;

	if (n == 0)
		return (0);
	u_s1 = (unsigned char *)s1;
	u_s2 = (unsigned char *)s2;
	while ((*u_s1 && (*u_s1 == *u_s2)) && --n)
	{
		if (*u_s1 != *u_s2)
			return (*u_s1 - *u_s2);
		u_s1 += 1;
		u_s2 += 1;
	}
	return (*u_s1 - *u_s2);
}
