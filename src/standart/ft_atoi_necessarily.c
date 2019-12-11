/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_necessarily.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmathew <hmathew@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 20:23:41 by hmathew           #+#    #+#             */
/*   Updated: 2019/12/11 20:24:22 by hmathew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi_necessarily(const char *str, int *ret)
{
	int sign;
	int nbr;
	int nbrtemp;

	while (ft_isspace(*str))
		str++;
	sign = 1;
	if ((*str == '-') || (*str == '+'))
		sign = (*str++ == '-') ? -1 : 1;
	nbr = 0;
	if (!ft_isdigit(*str))
		return (0);
	while (ft_isdigit(*str))
	{
		nbrtemp = nbr * 10 + (*str++ - '0');
		if (nbrtemp < nbr)
			return (0);
		nbr = nbrtemp;
	}
	if (*str)
		return (0);
	*ret = nbr * sign;
	return (1);
}
