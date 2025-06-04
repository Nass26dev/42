/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:02:50 by nyousfi           #+#    #+#             */
/*   Updated: 2025/06/04 14:18:41 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define RESET "\033[0m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[0;33m"
# define ORANGE "\033[38;5;208m"
# define CYAN "\033[0;36m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define T_MUTEX pthread_mutex_t
# define MAX_PHILOS 200

typedef struct s_philo
{
	int			id;
	long		t_die;
	long		t_eat;
	long		t_sleep;
	long		meal_reach;
	long		last_meal;
	long		start_time;
	long		meals_eaten;
	long		nb_philos;
	T_MUTEX		*left_fork;
	T_MUTEX		*right_fork;
	T_MUTEX		*print_mutex;
	T_MUTEX		*meal_mutex;

}				t_philo;

typedef struct s_threads
{
	pthread_t	philos[MAX_PHILOS];
	pthread_t	monitor;
}				t_threads;

typedef struct s_table
{
	t_philo		philos[MAX_PHILOS];
	T_MUTEX		forks[MAX_PHILOS];
	T_MUTEX		print_mutex;
	T_MUTEX		meal_mutex;
	int			nb_philos;
}				t_table;

// create.c
bool			check_args(int argc, char **argv, t_table *table);
bool			create_mutexes(t_table *table);
void			create_philos(t_table *table, int argc, char **argv);
// error.c
bool			error_args_case(int error_step);
bool			error_forks_case(t_table *table, int nb_forks);
bool			error_print_mutex_case(t_table *table, int nb_forks);
bool			error_meal_mutex_case(t_table *table, int nb_forks);
// error_utils.c
bool			error_monitor_case(t_table *table, int nb_philos);
bool			error_philo_case(t_table *table, int nb, t_threads *threads,
					int nb_thr);

// routine.c
bool			launch_routine(t_table *table);
// routine_utils.c
void			usleep_loop(long time_to_sleep);
void			print_step(t_philo *philo, char *color, char *step);
void	stop_routine(t_philo *philo);
bool			check_routine_stop(t_philo *philo);
bool			check_if_is_one(t_philo *philo);
// utils.c
long			get_current_time_ms(void);
void			free_ressources(t_table *table);
#endif