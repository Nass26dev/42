/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 08:19:31 by nyousfi           #+#    #+#             */
/*   Updated: 2025/04/03 15:35:13 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "struct.h"
# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

// data.c
void		check_args(int argc, char **argv);
void		create_data(t_data *d_ptr, int argc, char **argv);
void		create_mutex(t_data *d_ptr);
void		create_philo_and_monitor(t_data *d_ptr);
// data_utils.c
void		print_and_exit(char *to_print);
long long	ft_atoll(const char *str);
long		get_time_ms(void);
void		init_philo(t_philo *new_philo, t_data data);
// routine.c
void		launch_simulation(t_data *d_ptr);
void		wait_and_stop_simulation(t_data *d_ptr);
// routine_utils.c
void		eating_routine(t_philo *philo);
void		lock_and_print_philo(char *to_print, t_philo *philo);
bool		check_stop(t_philo *philo);
bool		check_meals(t_monitor *monitor);

#endif