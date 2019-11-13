/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmathew <hmathew@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 18:53:10 by hmathew           #+#    #+#             */
/*   Updated: 2019/09/11 20:16:11 by hmathew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_base_and_get_size(char *base, int *size)
{
	int		i;
	int		z;

	i = 0;
	z = 0;
	if (!base || !base[1])
		return (0);
	while (base[i])
	{
		z = i + 1;
		if (!((base[i] >= '0' && base[i] <= '9') || (base[i] >= 'a' \
				&& base[i] <= 'z') || (base[i] >= 'A' && base[i] <= 'Z')))
			return (0);
		while (base[z])
			if (base[i] == base[z++])
				return (0);
		i += 1;
	}
	*size = i;
	return (1);
}

void		ft_putnbr_base_fd(int nbr, char *base, int fd)
{
	int			i;
	int			size;
	int			n[10];
	long long	nbrl;

	nbrl = nbr;
	i = 0;
	if (!check_base_and_get_size(base, &size))
		return ;
	if (nbr == 0)
		ft_putchar_fd(base[0], fd);
	if (nbrl < 0)
	{
		nbrl *= -1;
		ft_putchar_fd('-', fd);
	}
	while (nbrl)
	{
		n[i] = nbrl % size;
		nbrl /= size;
		i++;
	}
	while (i > 0)
		ft_putchar_fd(base[n[--i]], fd);
}
