/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_buffer.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmathew <hmathew@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 15:39:20 by hmathew           #+#    #+#             */
/*   Updated: 2019/11/11 21:46:10 by hmathew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BUFFER_H
# define FT_PRINTF_BUFFER_H

# define BUFF_SIZE_PF 128
# define BUFF_SIZE_INFINITY_PF -1
# define FD_NO_INIT -1

typedef struct	s_buff
{
	char			*buff;
	int				current;
	int				size;
	int				need_mem;
	int				fd;
}				t_buff;

t_buff			*buffer_init(t_buff *bi, char *s, int need_mem, int size_buf);
int				buffer_write(t_buff *bi, const char *s, int len);
int				buffer_fill_char(t_buff *bi, const char c, int len);

#endif
