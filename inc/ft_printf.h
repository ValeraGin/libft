/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmathew <hmathew@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 15:35:09 by hmathew           #+#    #+#             */
/*   Updated: 2019/11/11 20:49:27 by hmathew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <wchar.h>
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <sys/types.h>

# include "libft.h"
# include "ft_printf_buffer.h"
# include "ft_printf_spec.h"

# define MAX_SPEC 256

# define PF_RED			"\033[31m"
# define PF_GREEN		"\033[32m"
# define PF_YELLOW		"\033[33m"
# define PF_BLUE		"\033[34m"
# define PF_PURPLE		"\033[35m"
# define PF_CYAN		"\033[36m"
# define PF_EOC			"\033[36m"

typedef int	(*t_print_function)(t_buff *bi, t_spec *param);
typedef int	(*t_arginfo_func)(t_spec *param);
typedef struct		s_plugin
{
	t_print_function	print_func;
	t_arginfo_func		arginfo_func;
}					t_plugin;

int					ft_printf(const char *format, ...);
int					ft_dprintf(int fd, const char *format, ...);
int					ft_vdprintf(int fd, const char *format, va_list arg);
int					ft_sprintf(char *s, const char *format, ...);
int					ft_vsprintf(char *s, const char *format, va_list arg);
int					ft_snprintf(char *s, size_t n, const char *format, ...);

int					register_ft_printf_function(int ch,
						t_print_function p_func, t_arginfo_func arg_info_func);

int					printf_internal(t_buff *bi,
										const char *format, va_list args);
int					print_specifier(t_buff *bi, t_spec *param);

t_plugin			*get_plugins(void);
int					get_arginfo(t_spec *param);
union u_arg_value	get_argvalue(int type, va_list arg);

#endif
