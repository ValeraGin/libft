/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmathew <hmathew@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 22:28:56 by hmathew           #+#    #+#             */
/*   Updated: 2019/10/18 22:29:03 by hmathew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_power(int nb, int pow)
{
	return (!pow ? 1 : nb * ft_power(nb, pow - 1));
}
