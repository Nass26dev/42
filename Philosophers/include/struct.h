/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 08:37:47 by nyousfi           #+#    #+#             */
/*   Updated: 2025/04/03 17:47:20 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <pthread.h>
# include <stdbool.h>
# include <sys/time.h>

typedef struct s_args
{
	long			numbers_of_philos;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			meals_to_reach;
}					t_args;

typedef struct s_mutexes
{
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*meal_mutex;
	pthread_mutex_t	stop_mutex;
}					t_mutexes;

typedef struct s_philo
{
	long			id;
	long			*meal_eaten;
	long			meals_to_reach;
	long			*last_meal_time;
	long			time_to_eat;
	long			time_to_sleep;
	long			start_time;
	bool			*stop_simulation;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	*meal_mutex;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	stop_mutex;
}					t_philo;

typedef struct s_monitor
{
	long			meals_to_reach;
	long			*meal_eaten;
	long			*last_meal_time;
	long			time_to_die;
	long			start_time;
	long			nb_philos;
	bool			*end_simulation;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	stop_mutex;
	pthread_mutex_t	*meal_mutex;
}					t_monitor;

typedef struct s_threads
{
	pthread_t		*philo_t;
	pthread_t		monitor_t;
}					t_threads;

typedef struct s_data
{
	t_args			a;
	t_mutexes		mu;
	t_philo			*p;
	t_monitor		mo;
	t_threads		t;
	long			*meal_eaten;
	long			*last_meal_time;
	bool			*end_simulation;
	long			start_time;
}					t_data;

#endif