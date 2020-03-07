/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_spec.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmathew <hmathew@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 15:50:50 by hmathew           #+#    #+#             */
/*   Updated: 2020/03/07 15:03:13 by hmathew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_SPEC_H
# define FT_PRINTF_SPEC_H

# define PF_FLAG_STRING "#0-+ '"
# define PF_PARSE_ERROR 0
# define PF_PARSE_OK 1
# define PF_NO_INIT -1

# define PA_FLAG_MASK 0xff00

enum
{
	PA_FLAG_UNSIGNED = (1 << 8),
	PA_FLAG_SIZE_START = (1 << 9),
	PA_FLAG_CHAR = (1 << 10),
	PA_FLAG_SHORT = (1 << 11),
	PA_FLAG_LONG = (1 << 12),
	PA_FLAG_LONG_LONG = (1 << 13),
	PA_FLAG_LONG_DOUBLE = (1 << 14),
	PA_FLAG_SIZE_T = (1 << 15),
	PA_FLAG_INTMAX = (1 << 16),
	PA_FLAG_PTR = (1 << 17),
};

enum
{
	PF_FLAG_SHARP = (1 << 0),
	PF_FLAG_ZERO = (1 << 1),
	PF_FLAG_MINUS = (1 << 2),
	PF_FLAG_PLUS = (1 << 3),
	PF_FLAG_SPACE = (1 << 4),
	PF_FLAG_APOSTROPHE = (1 << 5),
	PF_FLAG_WIDTH_WILDCARD = (1 << 6),
	PF_FLAG_PREC_WILDCARD = (1 << 7),
};

enum
{
	PF_PA_INT = 1,
	PF_PA_CHAR,
	PF_PA_WCHAR,
	PF_PA_STRING,
	PF_PA_WSTRING,
	PF_PA_POINTER,
	PF_PA_FLOAT,
	PF_PA_DOUBLE,
	PF_PA_LAST
};

union			u_arg_value
{
	wchar_t					pa_wchar;
	char					pa_char;
	int						pa_int;
	long int				pa_long_int;
	long long int			pa_long_long_int;
	intmax_t				pa_intmax_t;
	char					pa_u_char;
	unsigned int			pa_u_int;
	unsigned long int		pa_u_long_int;
	unsigned long long int	pa_u_long_long_int;
	size_t					pa_size_t;
	uintmax_t				pa_uintmax_t;
	double					pa_double;
	long double				pa_long_double;
	const char				*pa_string;
	const wchar_t			*pa_wstring;
	void					*pa_pointer;
};

typedef enum	e_mod
{
	NONE = 0,
	HH = 1,
	H = 2,
	L = 3,
	LL = 4,
	J = 5,
	Z = 6,
	LM = 7,
}				t_mod;

typedef struct	s_spec
{
	int					flags;
	int					width;
	int					prec;
	t_mod				mod;
	char				ch;

	int					order_t;
	int					order_w;
	int					order_p;

	union u_arg_value	arg_val;
	int					arg_type;

	char				*str;
	int					str_l;
}				t_spec;

typedef struct	s_specs
{
	t_spec					*specs[128];
	union u_arg_value		argvalues[128];
	int						argtypes[128];
	size_t					specs_count;
}				t_specs;

#endif
