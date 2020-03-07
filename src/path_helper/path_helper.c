/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmathew <hmathew@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 17:38:50 by hmathew           #+#    #+#             */
/*   Updated: 2020/03/07 19:25:59 by hmathew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			check_file_ext(const char *filename, const char *ext)
{
	char *point;

	if ((point = ft_strrchr(filename, '.')) != NULL)
		if (ft_strcmp(point, ext) == 0)
			return (1);
	return (0);
}

char		*replace_file_ext(const char *filename, const char *new_ext)
{
	char *res;
	char *point;

	if ((point = ft_strrchr(filename, '.')) != NULL)
		res = ft_strnew(point - filename + ft_strlen(new_ext));
	else
		return (ft_strdup(filename));
	ft_strncpy(res, filename, point - filename);
	ft_strcpy(&(res[point - filename]), new_ext);
	return (res);
}
