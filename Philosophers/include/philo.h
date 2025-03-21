/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nass <nass@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 12:59:00 by nass              #+#    #+#             */
/*   Updated: 2025/03/21 10:22:01 by nass             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# ifndef FORMAT
#  define FORMAT "Expected format : numbers_of_philosophers, time_to_die, time_to_eat, time_to_sleep, numbere_of_times_each_philosopher_must_eat (optionnal).\n"
# endif

typedef struct s_mutexes
{
	pthread_mutex_t *end_simulation_mutex;
	pthread_mutex_t *forks;
	pthread_mutex_t *print_mutex;
	pthread_mutex_t *start_mutexes;
	pthread_mutex_t *meals_eaten_mutexes;
	pthread_mutex_t *last_meal_time_mutexes;
}			t_mutexes;

typedef struct s_threads
{
	pthread_t *philos_threads;
	pthread_t monitor_thread;
}			t_threads;

typedef struct s_philo
{
    int id;
	pthread_mutex_t *start_mutex;
	pthread_mutex_t *last_meal_time_mutex;
	pthread_mutex_t *meals_eaten_mutex;
	pthread_mutex_t *end_simulation_mutex;
	bool *running;
    int meals_to_reach;
    int *meals_eaten;
    long *last_meal_time;
    long time_to_die;
    long time_to_eat;
    long time_to_sleep;
    long start_time;
	bool infinite_loop;
	bool *end_simulation;
    pthread_mutex_t	*print_mutex;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}               t_philo;

typedef struct s_args
{
	bool infinite_loop;
	int				numbers_of_philosophers;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	int				meals_to_reach;
}					t_args;

typedef struct s_monitor
{
	pthread_mutex_t *print_mutex;
	pthread_mutex_t *start_mutexes;
	pthread_mutex_t *last_meal_time_mutex;
	pthread_mutex_t *meals_eaten_mutex;
	pthread_mutex_t *end_simulation_mutex;
	long current_time;
	bool *running_lst;
	int	*meals_eaten_lst;
	long *last_meal_time_lst;
	bool *end_simulation;
	bool infinite_loop;
	long time_to_die;
	long time_to_eat;
	long time_to_sleep;
	int meals_to_reach;
	int numbers_of_philosophers;
	long start_time;
}			t_monitor;

typedef struct s_utils
{
	t_philo *philos;
	t_args args;
	t_monitor monitor;
	bool *running_lst;
	int *meals_eaten_lst;
	long *last_meals_time;
	bool *end_simulation;
}			t_utils;

void	create_utils(t_utils *utils_ptr, char **argv);
void create_mutexes(t_mutexes *mutexes_ptr, t_utils utils);
void create_philos(t_mutexes mutexes, t_utils *utils_ptr);
void get_start_time(t_utils *utils_ptr);
long get_time_in_ms(void);
void launch_simulation(t_utils utils, t_threads *threads_ptr);
void create_monitor(t_mutexes mutexes, t_utils *utils_ptr);

#endif