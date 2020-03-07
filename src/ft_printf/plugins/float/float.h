/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmathew <hmathew@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 20:23:25 by hmathew           #+#    #+#             */
/*   Updated: 2020/03/07 20:36:05 by hmathew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_FLOAT_H
# define FT_PRINTF_FLOAT_H

# include "ft_printf_plugins.h"

# define MAX_LEN_BNBR 1000

typedef struct	s_bnbr
{
	char	num[MAX_LEN_BNBR + 1];
	size_t	cap;
}				t_bnbr;

typedef struct	s_parts
{
	unsigned long int	mant : 64;
	unsigned int		exp : 15;
	unsigned int		sign : 1;
}				t_parts;
union			u_double
{
	long double	ld;
	t_parts		parts;
};

void			bnbr_sum(t_bnbr *n1, t_bnbr n2);
void			bnbr_mult_n(t_bnbr *r, t_bnbr n1, char n2, size_t shift);
t_bnbr			bnbr_new(char n);
t_bnbr			bnbr_mult(t_bnbr n1, t_bnbr n2);
t_bnbr			bnbr_power(size_t pow, t_bnbr n);
int				float_process(long double value, int isupcase, t_print *dp);

#endif
