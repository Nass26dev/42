/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:14:52 by nyousfi           #+#    #+#             */
/*   Updated: 2025/07/22 14:32:27 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# ifndef RESET
#  define RESET "\033[0m"
# endif
# ifndef RED
#  define RED "\033[31m"
# endif
# ifndef GREEN
#  define GREEN "\033[32m"
# endif
# ifndef YELLOW
#  define YELLOW "\033[0;33m"
# endif
# ifndef ORANGE
#  define ORANGE "\033[38;5;208m"
# endif
# ifndef CYAN
#  define CYAN "\033[0;36m"
# endif
# ifndef BLUE
#  define BLUE "\033[0;34m"
# endif
# ifndef PURPLE
#  define PURPLE "\033[0;35m"
# endif
# ifndef T_MUTEX
#  define T_MUTEX pthread_mutex_t
# endif
# ifndef MAX_PHILOS
#  define MAX_PHILOS 200
# endif

typedef struct s_times
{
	long		die;
	long		eat;
	long		sleep;
}				t_times;

typedef struct s_philo
{
	int			id;
	t_times		times;
	long		meal_required;
	long		last_meal;
	long		meal_count;
	long		start_time;
	long		nb_philos;
	bool		*is_dead;
	bool		*l_fork;
	bool		*r_fork;
	T_MUTEX		*left_fork;
	T_MUTEX		*right_fork;
	T_MUTEX		*print_mutex;
	T_MUTEX		*dead_mutex;
	T_MUTEX		*philo_mutex;
	T_MUTEX		*meal_mutex;
	T_MUTEX		*time_mutex;
}				t_philo;

typedef struct s_threads
{
	pthread_t	philos[MAX_PHILOS + 2];
	pthread_t	monitor;
}				t_threads;

typedef struct s_data
{
	t_philo		philo[MAX_PHILOS];
	T_MUTEX		forks[MAX_PHILOS];
	T_MUTEX		print_mutex;
	T_MUTEX		dead_mutex;
	T_MUTEX		meal_mutex;
	T_MUTEX		time_mutex;
	T_MUTEX		philo_mutex;
	bool		bool_forks[MAX_PHILOS];
	bool		is_dead;
	int			nb_philos;
}				t_data;

// args.c
long long		ft_atoll(const char *str);
bool			check_args(int argc, char **argv, t_data *data);
// create_error.c
bool			error_forks_case(t_data *data, int nb_forks);
bool			error_philo_mutex_case(t_data *data);
bool			error_dead_case(t_data *data);
bool			error_meal_case(t_data *data);
bool			error_time_case(t_data *data);
// eror.c
bool			error_args_case(int error_step);
// mutexes.c
bool			create_mutexes(t_data *data);
// philos.c
void			create_philos(t_data *data, int argc, char **argv);
// free.c
void			free_ressources(t_data *data);
// time.c
void			assign_times(t_data *data);
long			get_current_time_ms(void);
// routines.c
bool			launch_routines(t_data *data);
// philo_routine.c
void			drop_forks(t_philo *philo);
void			try_to_take_right_fork(t_philo *philo);
void			try_to_take_left_fork(t_philo *philo);
bool			check_routine_stop(t_philo *philo);
bool			is_one_philo(t_philo *philo);
// routine_utils.c
void			print_step(t_philo *philo, char *color, char *step);
void			usleep_loop(long time_to_sleep, t_philo *philo);
void			print_for_forks(t_philo *philo);
void			takes_forks(t_philo *philo);
// monitor_routine.c
bool			all_meals_reached(t_philo *philos);
void			stop_routine(t_philo *philos);
// threads_errors.c
bool			error_monitor_case(t_data *data);
bool			error_philo_case(t_data *data, int nb_philos);
#endif