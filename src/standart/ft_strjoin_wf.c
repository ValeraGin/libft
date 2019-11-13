/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_wf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmathew <hmathew@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 18:03:56 by hmathew           #+#    #+#             */
/*   Updated: 2019/11/08 18:47:12 by hmathew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strjoin_wf(char *s1, char *s2, int d)
{
	char *s;

	s = ft_strjoin(s1, s2);
	if (d == 2 || d == 0)
		free(s1);
	if (d == 2 || d == 1)
		free(s2);
	return (s);
}
