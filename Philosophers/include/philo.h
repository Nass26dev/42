/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 10:51:28 by nyousfi           #+#    #+#             */
/*   Updated: 2025/04/09 12:24:02 by nyousfi          ###   ########.fr       */
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

# define RESET   	"\033[0m"
# define RED     	"\033[31m"
# define GREEN   	"\033[32m"
# define YELLOW		"\033[0;33m"
# define ORANGE		"\033[38;5;208m"
# define CYAN		"\033[0;36m"
# define BLUE		"\033[0;34m"
# define PURPLE		"\033[0;35m"
# define t_mutex pthread_mutex_t
# define MAX_PHILOS 200

typedef struct s_philo
{
	int id;
	long t_die;
	long t_eat;
	long t_sleep;
	long meal_reach;
	long last_meal;
	long start_time;
	long meals_eaten;
	long nb_philos;
	t_mutex *left_fork;
	t_mutex *right_fork;
	t_mutex *print_mutex;
	t_mutex *meal_mutex;
	
}				t_philo;

typedef struct s_threads
{
	pthread_t philos[MAX_PHILOS];
	pthread_t monitor;
}				t_threads;

typedef struct s_table
{
	t_philo 		philos[MAX_PHILOS];
	t_mutex forks[MAX_PHILOS];
	t_mutex print_mutex;
	t_mutex meal_mutex;
	int nb_philos;
}				t_table;

// utils.c
void print_error(char *error_msg, int message_length);
void free_ressources(t_table table, int nb, int exit_code, int step);
long get_current_time_ms(void);
void print_step(t_philo *philo, char *color, char *step);
// create.c
void create_mutexes(t_table *table);
void create_philos(t_table *table, int argc, char **argv);
// create_utils.c
void check_args(int argc, char **argv, t_table *table);
long long	ft_atoll(const char *str);
// routine.c
void launch_routines(t_table *table);

#endif