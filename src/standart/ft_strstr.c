/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmathew <hmathew@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 19:50:24 by hmathew           #+#    #+#             */
/*   Updated: 2019/09/06 20:31:08 by hmathew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int i;
	int j;

	i = -1;
	if (!(s2[0]))
		return ((char *)s1);
	while (s1[++i])
	{
		if (s1[i] == s2[0])
		{
			j = 0;
			while (s2[j] && (s1[i + j] == s2[j]))
				j++;
			if (s2[j] == '\0')
				return ((char *)&(s1[i]));
		}
	}
	return (NULL);
}
