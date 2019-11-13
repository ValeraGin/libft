/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmathew <hmathew@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 18:35:38 by hmathew           #+#    #+#             */
/*   Updated: 2019/09/11 19:16:38 by hmathew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*cur_list;
	t_list	*nxt_list;

	cur_list = *alst;
	while (cur_list)
	{
		nxt_list = cur_list->next;
		del((cur_list->content), (cur_list->content_size));
		free(cur_list);
		cur_list = nxt_list;
	}
	*alst = NULL;
}
