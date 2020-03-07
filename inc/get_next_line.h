/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmathew <hmathew@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 16:06:37 by hmathew           #+#    #+#             */
/*   Updated: 2020/03/07 15:05:42 by hmathew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE	100
# define MAX_FD		1025

# define GNL_ERROR -1
# define GNL_FINISHED 0
# define GNL_OK 1

# define GNL_LINEOK 1
# define GNL_LINEBAD 0

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

int	get_next_line(const int fd, char **line);

#endif
