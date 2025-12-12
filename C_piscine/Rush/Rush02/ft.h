/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 10:25:28 by nyousfi           #+#    #+#             */
/*   Updated: 2024/08/25 20:12:07 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int     ft_little_atoi(char c);
unsigned long long int     ft_atoi(char *str);
void    ft_putchar(char c);
void    ft_putstr(char *str);
int	ft_strlen(char *str);
char    *ft_itoa(unsigned long long int nb);
unsigned long long int  ft_recursive_power(unsigned long long int nb, unsigned long long int power);
char    *ft_dict_opener(char *path);
int     val_counter(char *content, int size);
int     size_evaluator(int fd);
void    index_base(char *nb_str, char *parse);
void    find_print(char *parsing_str, char *nb_str);
unsigned long long int     ft_strstr(char *str, char *to_find);
