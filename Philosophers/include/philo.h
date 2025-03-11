/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:40:38 by nass              #+#    #+#             */
/*   Updated: 2025/03/11 09:37:41 by nyousfi          ###   ########.fr       */
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
#include <stdint.h>

typedef struct s_philo {
	int				id;
	int				max_meals;
	int				meals_eaten;
	struct timeval	last_meal_time;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	pthread_mutex_t *print_mutex;
	pthread_mutex_t *left_fork;
	pthread_mutex_t *right_fork;
	struct timeval	start_time;
} 		t_philo;

typedef struct s_args
{
	int 	numbers_of_philosophers;
	int 	time_to_die;
	int		time_to_eat;
	int 	time_to_sleep;
	int		max_meals;
}		t_args;

t_args recup_args(char **argv);
t_philo *create_philos(t_args args, pthread_mutex_t *forks, pthread_mutex_t *print_mutex, struct timeval start_time);
pthread_mutex_t *create_forks(t_args args);
void *routine(void *arg);
pthread_t *create_threads(t_args args, t_philo *philos);

#endif
