/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nass <nass@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:27:51 by nass              #+#    #+#             */
/*   Updated: 2025/03/30 05:09:22 by nass             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
#include <limits.h>

#ifndef FORMAT_ERROR
#define FORMAT_ERROR "Expected format : numbers_of_philosophers, time_to_die, time_to_eat, time_to_sleep, numbere_of_times_each_philosopher_must_eat (optionnal)."
#endif

typedef struct s_mutexes
{
    pthread_mutex_t print_mutex;
    pthread_mutex_t *forks;
}               t_mutexes;

typedef struct s_philo
{
    int id;
    int meals_to_reach;
    int meal_eaten;
    long last_meal_time;
    long time_to_die;
    long time_to_eat;
    long time_to_sleep;
    long start_time;
    pthread_mutex_t print_mutex;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
}           t_philo;

typedef struct s_ent
{
    t_philo *philos;
}           t_ent;

typedef struct s_args
{
	int				numbers_of_philosophers;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	int				meals_to_reach;
}           t_args;

typedef struct s_threads
{
    pthread_t *philos;
}               t_threads;

typedef struct s_data
{
    t_args args;
    t_mutexes mutexes;
    t_ent ent;
    t_threads threads;
    long start_time;
}               t_data;

// data.c
void recup_args(int argc, char **argv, t_data *data_ptr);
void create_philos(t_data *data_ptr);
void create_mutexes(t_data *data_ptr);
void create_threads(t_data *data_ptr);
// data_utils.c
long long	ft_atoll(const char *str);
void print_and_exit(char *error_msg);
void init_philo(t_philo *new_philo, t_data data);
long get_time_in_ms(void);
// routine.c
void *philo_routine(void *arg);
// routine_utils.c
void	lock_and_print(char *to_print, long current_time, int id, pthread_mutex_t *print_mutex);
void eating_routine(t_philo *philo);

#endif