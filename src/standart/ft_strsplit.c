/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmathew <hmathew@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 22:37:34 by hmathew           #+#    #+#             */
/*   Updated: 2019/11/29 17:48:01 by hmathew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_wordcount(const char *s, char c)
{
	unsigned int	i;
	size_t			wc;

	i = 0;
	wc = 0;
	while (s[i])
	{
		if (s[i] != c)
			wc += 1;
		while (s[i] != c && s[i + 1])
			i += 1;
		i += 1;
	}
	return (wc);
}

static size_t	ft_wordlen(const char *s, char c)
{
	unsigned int	i;
	size_t			len;

	i = 0;
	len = 0;
	while (s[i] == c)
		i += 1;
	while (s[i] != c && s[i++])
		len += 1;
	return (len);
}

static void		*ft_error_malloc(char **w, size_t *i)
{
	while (*i)
		free(w[*(i--)]);
	free(w);
	return (NULL);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	si;
	char	**w;

	i = -1;
	si = 0;
	if (!s)
		return (NULL);
	if (!(w = (char **)malloc(sizeof(char *) * (ft_wordcount(s, c) + 1))))
		return (NULL);
	while (++i < ft_wordcount(s, c))
	{
		if (!(w[i] = ((char *)malloc(sizeof(char) *
			(ft_wordlen(&s[si], c) + 1)))))
			return (ft_error_malloc(w, &i));
		j = 0;
		while (s[si] == c)
			si++;
		while (s[si] != c && s[si])
			w[i][j++] = s[si++];
		w[i][j] = '\0';
	}
	w[i] = NULL;
	return (w);
}
