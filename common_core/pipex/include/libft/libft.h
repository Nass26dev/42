/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:28:13 by nyousfi           #+#    #+#             */
/*   Updated: 2025/01/24 11:27:04 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <fcntl.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t num_elements, size_t element_size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
char	*ft_itoa(int n);
char	*reverse_str(char *str);
int		int_len(int n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(const char *s, char c);
char	*allocate_cpy(char *str, char sep);
int		find_word(char *str, char c);
int		count_words(char const *s, char c);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(char *src);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
char	*ft_strncat(char *dest, char *src, size_t nb);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(char *s1, char *s2, unsigned int n);
char	*ft_strnstr(char *str, char *to_find, size_t len);
char	*ft_strrchr(const char *str, int c);
char	*ft_strtrim(char const *s1, char const *set);
int		end_index(char *s1, char *set);
int		start_index(char *s1, char *set);
int		char_is_sepa(char c, char *sep);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);
void	free_split(char **split, int i);
int		ft_printf(const char *str, ...);
char	*get_next_line(int fd);

#endif
