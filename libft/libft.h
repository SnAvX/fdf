/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plebiez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 12:30:49 by plebiez           #+#    #+#             */
/*   Updated: 2022/01/14 03:36:39 by paullebiez       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>

# define BUFFER_SIZE 2048

# define FT_ABS(X) (((X) < 0) ? (-(X)) : (X))

typedef struct		s_file
{
	int				fd;
	char			*str;
	struct s_file	*next;
}					t_file;

int					get_next_line(const int fd, char **line);

int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_atoi(const char *str);
int			ft_tolower(int c);
int			ft_toupper(int c);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
int			ft_putchar_fd_return(char c, int fd);
int			ft_putnbr_unsigned(unsigned int n);
int		    get_next_line(const int fd, char **line);
int         ft_wcounter(char *s, char c);
int			ft_atoi_base(const char *str, int base);
size_t		ft_strlen(const char *str);
size_t		ft_strlcpy(char *dest, char *src, size_t size);
size_t		ft_strlcat(char *dest, char *src, unsigned int size);
char		*ft_strjoin_f12(char *s1, char *s2);
char		*ft_itoa_base_more(unsigned long long int n, char *base);
char		*ft_itoa_base(unsigned int n, char *base);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strnstr(const char *s1, const char *s2, size_t len);
char		*ft_strdup(const char *src);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char *s1, char const *set);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		**ft_split(const char *s, char c);
char		*ft_strnew(size_t size);
char		*ft_strncpy(char *dst, const char *src, size_t len);
char	    *ft_strsubchr(const char *s, char c);
char	    *ft_strchrs(const char *s, int c);
void		*ft_memset(void *s, int c, size_t n);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memccpy(void *dest, const void *src, int c, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void	*ft_memalloc(size_t size);
char		*ft_itoa(int nb);

#endif
