/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:28:13 by nyousfi           #+#    #+#             */
/*   Updated: 2025/02/19 14:43:44 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <fcntl.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// get_next_line
# ifndef BUFFER_SIZE_GNL
#  define BUFFER_SIZE_GNL 100
# endif

# ifndef NB_FD_MAX_GNL
#  define NB_FD_MAX_GNL 1024
# endif

typedef struct s_gnl_list
{
	char				buffer[BUFFER_SIZE_GNL + 1];
	struct s_gnl_list	*next;
}						t_gnl_list;
// ft_printf
typedef struct s_cpf
{
	size_t				i;
	size_t				nb;
	ssize_t				error;
}						t_cpf;

long int				ft_atol(const char *str);
int						ft_isalpha(int c);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
int						ft_intlen(int n);
int						ft_isalnum(int c);
int						ft_isascii(int c);
int						ft_isdigit(int c);
int						ft_isprint(int c);
int						ft_strncmp(char *s1, char *s2, unsigned int n);
int						ft_tolower(int c);
int						ft_toupper(int c);
int						ft_printf(const char *str, ...);
char					*ft_itoa(int n);
char					*ft_revstr(char *str);
char					**ft_split(const char *s, char c);
char					*ft_strchr(const char *str, int c);
char					*ft_strdup(char *src);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strncat(char *dest, char *src, size_t nb);
char					*ft_strmapi(char const *s, char (*f)(unsigned int,
								char));
char					*ft_strnstr(char *str, char *to_find, size_t len);
char					*ft_strrchr(const char *str, int c);
char					*ft_strtrim(char const *s1, char const *set);
char					*ft_substr(char const *s, unsigned int start,
							size_t len);
char					*get_next_line(int fd);
char					*ft_revstr(char *str);
void					ft_bzero(void *s, size_t n);
void					*ft_calloc(size_t num_elements, size_t element_size);
void					*ft_memchr(const void *s, int c, size_t n);
void					*ft_memcpy(void *dest, const void *src, size_t n);
void					*ft_memmove(void *dest, const void *src, size_t n);
void					*ft_memset(void *s, int c, size_t n);
void					ft_putchar_fd(char c, int fd);
void					ft_putendl_fd(char *s, int fd);
void					ft_putnbr_fd(int n, int fd);
void					ft_putstr_fd(char *s, int fd);
void					free_split(char **split);
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
size_t					ft_strlen(const char *s);
size_t					ft_strlcat(char *dest, const char *src, size_t size);
size_t					ft_strlcpy(char *dest, const char *src, size_t size);

#endif
