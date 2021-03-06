/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmathew <hmathew@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 18:23:14 by hmathew           #+#    #+#             */
/*   Updated: 2020/03/03 20:51:31 by hmathew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpush(t_list **list, t_list *new)
{
	t_list	*out;

	out = *list;
	if (out)
	{
		while (out->next)
			out = out->next;
		out->next = new;
	}
	else
		*list = new;
}
