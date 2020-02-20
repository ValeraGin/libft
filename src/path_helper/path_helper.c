/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmathew <hmathew@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 17:38:50 by hmathew           #+#    #+#             */
/*   Updated: 2020/02/20 14:05:36 by hmathew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			check_file_ext(char *filename, const char *ext)
{
	char *point;

	if ((point = ft_strrchr(filename, '.')) != NULL)
		if (strcmp(point, ext) == 0)
			return (1);
	return (0);
}

char		*replace_file_ext(char *filename, const char *new_ext)
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
