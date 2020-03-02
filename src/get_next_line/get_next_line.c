/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmathew <hmathew@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 16:06:34 by hmathew           #+#    #+#             */
/*   Updated: 2020/03/02 18:11:12 by hmathew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	int	gnl_get_line(char **stack, char **line)
{
	char	*str_chr;
	char	*stack_to_del;

	if (!(str_chr = ft_strchr(*stack, '\n')))
		return (GNL_LINEBAD);
	*str_chr = '\0';
	*line = ft_strdup(*stack);
	stack_to_del = *stack;
	*stack = ft_strdup(++str_chr);
	ft_memdel((void *)&stack_to_del);
	return (GNL_LINEOK);
}

static	int	gnl_read_fd(int fd, char *heap, char **stack, char **line)
{
	int		ret_read;
	char	*stack_to_del;

	while ((ret_read = read(fd, heap, BUFF_SIZE)) > 0)
	{
		heap[ret_read] = '\0';
		if (*stack)
		{
			stack_to_del = *stack;
			*stack = ft_strjoin(stack_to_del, heap);
			ft_memdel((void *)&stack_to_del);
		}
		else
		{
			stack_to_del = *stack;
			*stack = ft_strdup(heap);
			ft_memdel((void *)&stack_to_del);
		}
		if (gnl_get_line(stack, line))
			break ;
	}
	return (ret_read > 0 ? 1 : ret_read);
}

int			get_next_line(const int fd, char **line)
{
	static char	*stack[MAX_FD];
	char		*heap;
	int			ret_read;

	if (fd < 0 || fd >= MAX_FD || !line || (read(fd, stack[fd], 0) < 0)
		|| !(heap = (char *)malloc(sizeof(char) * BUFF_SIZE + 1)))
		return (GNL_ERROR);
	if (stack[fd])
		if (gnl_get_line(&stack[fd], line) == GNL_LINEOK)
		{
			ft_memdel((void *)&heap);
			return (GNL_OK);
		}
	ft_memset(heap, '\0', BUFF_SIZE + 1);
	ret_read = gnl_read_fd(fd, heap, &stack[fd], line);
	ft_memdel((void *)&heap);
	if (ret_read || !stack[fd])
	{
		if (!ret_read && *line)
			*line = NULL;
		return (ret_read);
	}
	*line = stack[fd];
	stack[fd] = NULL;
	return (GNL_OK);
}
