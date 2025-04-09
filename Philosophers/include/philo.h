/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 08:31:07 by nyousfi           #+#    #+#             */
/*   Updated: 2025/04/09 10:30:11 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>
#include <stdbool.h>
#include <limits.h>
#include <unistd.h>

typedef struct s_philo
{
	long id;
	long time_to_eat;
	long time_to_sleep;
	long start_time;
	long *meal_eaten;
	long *last_meal_time;
	bool *stop_simulation;
	pthread_mutex_t *print_mutex;
	pthread_mutex_t *left_fork;
	pthread_mutex_t *right_fork;
	pthread_mutex_t *stop_mutex;
	pthread_mutex_t *meal_mutex;
}				t_philo;

typedef struct s_mutexes
{
	pthread_mutex_t print_mutex;
	pthread_mutex_t *forks;
	pthread_mutex_t stop_mutex;
	pthread_mutex_t *meal_mutex;
}				t_mutexes;

typedef struct s_args
{
	long			numbers_of_philos;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			meals_to_reach;
}				t_args;

typedef struct s_utils
{
	long *meal_eaten;
	long *last_meal_time;
	bool *stop_simulation;
}				t_utils;

typedef struct s_monitor
{
	long meals_to_reach;
	long *meal_eaten;
	long *last_meal_time;
	long time_to_die;
	long start_time;
	long nb_philos;
	bool *stop_simulation;
	pthread_mutex_t *print_mutex;
	pthread_mutex_t *stop_mutex;
	pthread_mutex_t *meal_mutexes;
}				t_monitor;

typedef struct s_threads
{
	pthread_t *philos_threads;
	pthread_t monitor_thread;
}				t_threads;

typedef struct s_data
{
	t_args args;
	t_mutexes mutexes;
	t_utils utils;
	t_philo *philos;
	t_monitor monitor;
	t_threads threads;
}				t_data;

// args.c
void recup_args(int argc, char **argv, t_args *args);
// mutexes.c
void create_mutexes(t_data *data);
// mutex_errors.c
void forks_init_error(long nb, t_data data);
void print_mutex_init_error(t_data data);
void stop_mutex_init_error(t_data data);
void meal_mutex_init_error(long nb, t_data data);
// malloc_errors.c
void last_meal_time_malloc_error(t_data data);
void meal_eaten_malloc_error(t_data data);
void philos_threads_malloc_error(t_data data);
void philos_malloc_error(t_data data);
void meal_mutex_malloc_error(t_data data);
// thread_error.c
void monitor_thread_error(t_data data);
void philo_thread_error(long nb, t_data data);
// routine.c
void launch_routine(t_data *data);
// philo_and_monitor.c
void create_philos_and_monitor(t_data *data);
// data.c
void fill_data_with_utils(t_data *data);
// time.c
void add_start_time(t_data *data);
long get_time_in_ms();

#endif