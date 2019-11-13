/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmathew <hmathew@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:35:51 by hmathew           #+#    #+#             */
/*   Updated: 2019/09/11 17:49:48 by hmathew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_itoa(int n)
{
	size_t		i;
	size_t		n_size;
	char		*str;
	long long	nl;

	i = 0;
	nl = n;
	n_size = ft_nbrlen(nl, 10);
	if (!(str = (char *)malloc(sizeof(char) * (n_size + 1))))
		return (NULL);
	str[n_size] = 0;
	if (nl < 0)
	{
		str[0] = '-';
		nl *= -1;
		i += 1;
	}
	while (i < n_size--)
	{
		str[n_size] = (nl % 10) + '0';
		nl /= 10;
	}
	return (str);
}
