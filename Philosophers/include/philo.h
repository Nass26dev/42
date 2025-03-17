/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:40:38 by nyousfi           #+#    #+#             */
/*   Updated: 2025/03/17 16:25:18 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_meal_node
{
	long	*last_meal;
	int id;
	struct s_meal_node *next;
}			t_meal_node;

typedef struct s_monitor
{
	bool *stop;
	struct timeval	start_time;
	long			time;
	int				nb_philos;
	t_meal_node		*meal_lst;
	long			time_to_die;
	pthread_mutex_t	*print_mutex;
}				t_monitor;

typedef struct s_philo
{
	int				id;
	int				nb_philos;
	int				max_meals;
	int				meals_eaten;
	bool			*stop;
	long			*last_meal_time;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	pthread_mutex_t	*print_mutex;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	struct timeval	start_time;
}					t_philo;

typedef struct s_args
{
	int				numbers_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				max_meals;
}					t_args;

t_args				recup_args(char **argv);
t_philo				*create_philos(t_args args, pthread_mutex_t *forks,
						pthread_mutex_t *print_mutex,
						struct timeval start_time);
pthread_mutex_t		*create_forks(t_args args);
void				*routine(void *arg);
pthread_t			*create_threads(t_args args, t_philo *philos);
void	lock_and_print(char *to_print, long int current_time, int id, pthread_mutex_t *print_mutex);
long	get_time_in_ms(struct timeval start_time);
pthread_t create_monitor(t_args args, t_philo *philos, pthread_mutex_t *print_mutex, struct timeval start_time);

#endif
