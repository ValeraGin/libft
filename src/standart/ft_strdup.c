/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmathew <hmathew@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 20:21:51 by hmathew           #+#    #+#             */
/*   Updated: 2019/09/12 19:42:50 by hmathew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new;

	if (!(new = (char *)malloc(ft_strlen(s) + 1)))
	{
		errno = ENOMEM;
		return (NULL);
	}
	return (ft_strcpy(new, s));
}
