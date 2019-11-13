/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmathew <hmathew@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 20:32:33 by hmathew           #+#    #+#             */
/*   Updated: 2019/09/06 21:13:56 by hmathew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t j;

	if (!(s2[0]))
		return ((char *)s1);
	i = -1;
	while (s1[++i] && (n > i))
	{
		if (s1[i] == s2[0])
		{
			j = 1;
			while ((n > i + j) && s2[j] && (s1[i + j] == s2[j]))
				j++;
			if (s2[j] == '\0')
				return ((char *)&(s1[i]));
		}
	}
	return (NULL);
}
