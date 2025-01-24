/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:40:38 by nass              #+#    #+#             */
/*   Updated: 2025/01/24 17:23:36 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <sys/time.h>
#include <stdbool.h>

typedef struct s_philosopher {
	int				id;
	bool			is_max_meals;
	int				max_meals;
	int				meals_eaten;
	int				last_meal_time;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				into_sleep;
	pthread_mutex_t *left_fork;
	pthread_mutex_t *right_fork;
	pthread_t		thread;
} 		t_philosopher;

typedef struct s_list
{
	t_philosopher	philo;
	struct s_list 	*next;
}		t_list;

typedef struct s_args
{
	int 	numbers_of_philosophers;
	int 	time_to_die;
	int		time_to_eat;
	int 	time_to_sleep;
	int		max_meals;
	bool	is_max_meals;
}		t_args;

t_list		*create_philosophers(int argc, char **argv);
void		free_lst(t_list *lst, int exit_code);
long int	ft_atol(const char *str);
long get_current_time_ms();

#endif
