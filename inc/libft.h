/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmathew <hmathew@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 23:24:33 by hmathew           #+#    #+#             */
/*   Updated: 2020/03/07 14:31:34 by hmathew          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdint.h>
# include <wchar.h>
# include <unistd.h>

# include <ft_printf.h>
# include <get_next_line.h>

# include <macro.hh>

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

size_t			ft_strlen(const char *s);

int				ft_isupper(int c);
int				ft_islower(int c);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
int				ft_isspace(int c);
int				ft_atoi(const char *str);
int				ft_atoi_necessarily(const char *str, int *ret);
char			*ft_strdup(const char *s);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
void			ft_bzero(void *s, size_t n);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *s1, const char *s2);
char			*ft_strnstr(const char *s1, const char *s2, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);

void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char(*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strjoinc_wf(char *s, char c, int char_before, int needfree);
char			*ft_strjoin_wf(char *s1, char *s2, int d);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_itoa(int n);
void			ft_strclr(char *s);
char			*ft_strndup(const char *src, size_t n);

void			ft_putchar_fd(char c, int fd);
void			ft_putnchar_fd(char c, int n, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_base_fd(int nbr, char *base, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);

size_t			ft_nbrlen(int nbr, int base);

void			ft_lstdel_func(void *p, size_t s);
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstpush(t_list **list, t_list *new);
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			ft_lstrev(t_list **list);

int				ft_power(int nb, int pow);

int				ft_putunbr_fd(uintmax_t n, int fd);

int				ft_wchar_utf8(const wchar_t wc, char *s);
int				ft_wclen(const wchar_t wchar);
int				ft_putwchar(const wchar_t wc);
int				ft_putwchar_fd(const wchar_t wc, int fd);
int				ft_putwstr(const wchar_t *ws);
int				ft_putwstr_fd(const wchar_t *ws, int fd);
size_t			ft_wcslen(const wchar_t *wcs);
wchar_t			*ft_wcsdup(const wchar_t *src);
wchar_t			*ft_wcscpy(wchar_t *dst, const wchar_t *src);
wchar_t			*ft_wcsnew(size_t size);
wchar_t			*ft_wcsncpy(wchar_t *dst, const wchar_t *src, size_t n);

char			*ft_strrev(char *str);
char			*ft_str_to_lowcase(char *str);

int				ft_abs(int n);

void			*ft_realloc(void *ptr, size_t size);

int				check_file_ext(const char *filename, const char *ext);
char			*replace_file_ext(const char *filename, const char *new_ext);

#endif
