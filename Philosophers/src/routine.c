/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 10:49:50 by nyousfi           #+#    #+#             */
/*   Updated: 2025/06/04 15:21:54 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

bool	all_meals_reached(t_philo *philos)
{
	int	i;

	i = 0;
	if (philos[0].meal_reach == -1)
		return (false);
	while (i < philos[0].nb_philos)
	{
		if (philos[i].meals_eaten >= philos[i].meal_reach)
			i++;
		else
			return (false);
	}
	return (true);
}

void	*monitor_routine(void *arg)
{
	t_philo	*philos;
	int		i;
	int j;
	philos = (t_philo *)arg;
	while (1)
	{
		i = -1;
		while (++i < philos[0].nb_philos)
		{
			pthread_mutex_lock(philos->meal_mutex);
			if (get_current_time_ms() - philos[i].last_meal >= philos[i].t_die)
			{
				pthread_mutex_lock(philos[i].print_mutex);
				j = 0;
				while (j < philos[0].nb_philos)
				{
					philos[j].meal_reach = 0;
					j++;
				}
				pthread_mutex_unlock(philos->meal_mutex);
				printf("%s%ld%s", PURPLE, get_current_time_ms()
					- philos[i].start_time, RESET);
				printf(" %d %s%s%s\n", philos[i].id, RED, "is dead", RESET);
				pthread_mutex_unlock(philos[i].print_mutex);
				return (NULL);
			}
			pthread_mutex_unlock(philos->meal_mutex);
			usleep(50);
		}
		if (all_meals_reached(philos))
		{
			j = 0;
			while (j < philos[0].nb_philos)
			{
				philos[j].meal_reach = 0;
				j++;
			}
			return (NULL);
		}
	}
	return (NULL);
}

void	philo_routine(t_philo *philo)
{
	while (1)
	{
		if (check_routine_stop(philo))
			return ;
		pthread_mutex_lock(philo->left_fork);
		print_step(philo, YELLOW, "has taken a fork");
		if (check_if_is_one(philo))
			return ;
		pthread_mutex_lock(philo->right_fork);
		print_step(philo, ORANGE, "has taken a fork");
		print_step(philo, GREEN, "is eating");
		pthread_mutex_lock(philo->meal_mutex);
		philo->last_meal = get_current_time_ms();
		philo->meals_eaten++;
		pthread_mutex_unlock(philo->meal_mutex);
		usleep_loop(philo->t_eat);
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		print_step(philo, BLUE, "is sleeping");
		usleep_loop(philo->t_sleep);
		print_step(philo, CYAN, "is thinking");
		usleep(50);
	}
}

void	*launch_philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 != 0)
		usleep(20);
	pthread_mutex_lock(philo->meal_mutex);
	philo->start_time = get_current_time_ms();
	philo->last_meal = get_current_time_ms();
	pthread_mutex_unlock(philo->meal_mutex);
	philo_routine(philo);
	return (NULL);
}

bool	launch_routine(t_table *table)
{
	t_threads	threads;
	int			i;

	if (pthread_create(&threads.monitor, NULL, monitor_routine, table->philos))
		return (error_monitor_case(table, table->nb_philos));
	i = 0;
	while (i < table->nb_philos)
	{
		if (pthread_create(&threads.philos[i], NULL, launch_philo_routine,
				&table->philos[i]))
			return (error_philo_case(table, table->nb_philos, &threads, i));
		i++;
	}
	pthread_join(threads.monitor, NULL);
	// stop_routine(table, &threads);
	i = 0;
	while (i < table->nb_philos)
	{
		pthread_join(threads.philos[i], NULL);
		i++;
	}
	return (false);
}
