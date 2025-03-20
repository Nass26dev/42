/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nass <nass@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 12:59:00 by nass              #+#    #+#             */
/*   Updated: 2025/03/20 15:31:27 by nass             ###   ########.fr       */
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
	pthread_mutex_t *forks;
	pthread_mutex_t *print_mutex;
}			t_mutexes;

typedef struct s_threads
{
	pthread_t *philos_threads;
}			t_threads;

typedef struct s_philo
{
    int id;
    int meals_to_reach;
    int meals_eaten;
    long last_meal_time;
    long time_to_die;
    long time_to_eat;
    long time_to_sleep;
    long start_time;
	bool infinite_loop;
    pthread_mutex_t	*print_mutex;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}               t_philo;

typedef struct s_args
{
	bool infinite_loop;
	int				numbers_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals_to_reach;
}					t_args;

typedef struct s_utils
{
	t_philo *philos;
	t_args args;
}			t_utils;

void	recup_args(t_utils *utils_ptr, char **argv);
void create_mutexes(t_mutexes *mutexes_ptr, t_utils utils);
void create_philos(t_mutexes mutexes, t_utils *utils_ptr);
void get_start_time(t_utils *utils_ptr);
long get_time_in_ms(void);
void launch_simulation(t_utils utils, t_threads *threads_ptr);

#endif