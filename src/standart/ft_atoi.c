/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmathew <hmathew@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 19:16:54 by hmathew           #+#    #+#             */
/*   Updated: 2019/09/18 19:52:05 by hmathew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int			sign;
	long long	nbr;
	long long	nbrtemp;

	while (ft_isspace(*str))
		str++;
	sign = 1;
	if ((*str == '-') || (*str == '+'))
		sign = (*str++ == '-') ? -1 : 1;
	nbr = 0;
	while (ft_isdigit(*str))
	{
		nbrtemp = nbr * 10 + (*str++ - '0');
		if (nbrtemp < nbr)
			return (0);
		nbr = nbrtemp;
	}
	return (nbr * sign);
}
