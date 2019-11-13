/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinc_wf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmathew <hmathew@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 18:05:27 by hmathew           #+#    #+#             */
/*   Updated: 2019/11/08 19:35:47 by hmathew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoinc_wf(char *s, char c, int char_before, int needfree)
{
	char	*new_str;
	size_t	i;
	size_t	len;

	if (!s || !c)
		return (NULL);
	len = ft_strlen(s) + 1;
	if (!(new_str = ft_strnew(len)))
		return (NULL);
	*(new_str) = char_before ? c : *s;
	i = char_before;
	while (i < len - 1 + char_before)
	{
		*(new_str + i) = *(s + i - char_before);
		i += 1;
	}
	*(new_str + i) = !char_before ? c : *(s + i);
	if (needfree)
		free(s);
	return (new_str);
}
