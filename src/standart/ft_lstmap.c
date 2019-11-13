/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmathew <hmathew@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 18:35:30 by hmathew           #+#    #+#             */
/*   Updated: 2019/09/11 19:17:01 by hmathew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*head_newlst;
	t_list	*cur_newlst;

	if (!lst)
		return (NULL);
	cur_newlst = f(lst);
	head_newlst = cur_newlst;
	while (lst->next)
	{
		lst = lst->next;
		cur_newlst->next = f(lst);
		cur_newlst = cur_newlst->next;
	}
	return (head_newlst);
}
