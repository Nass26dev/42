/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:56:02 by nyousfi           #+#    #+#             */
/*   Updated: 2025/07/22 14:32:32 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	check_death(t_philo *philos, int i)
{
	pthread_mutex_lock(philos[i].time_mutex);
	if ((get_current_time_ms() - philos[i].last_meal) >= philos[i].times.die)
	{
		pthread_mutex_unlock(philos[i].time_mutex);
		pthread_mutex_lock(philos->print_mutex);
		stop_routine(philos);
		printf("%s%ld%s %d %s%s%s\n", PURPLE, get_current_time_ms()
			- philos[i].start_time, RESET, philos[i].id, RED, "died", RESET);
		pthread_mutex_unlock(philos->print_mutex);
		return (true);
	}
	pthread_mutex_unlock(philos[i].time_mutex);
	return (false);
}

void	*monitor_routine(void *arg)
{
	t_philo	*philos;
	int		i;

	philos = (t_philo *)arg;
	while (1)
	{
		i = -1;
		while (++i < philos[0].nb_philos)
		{
			if (check_death(philos, i))
				return (NULL);
		}
		if (all_meals_reached(philos))
		{
			stop_routine(philos);
			return (NULL);
		}
		usleep(1000);
	}
	return (NULL);
}

void	philo_routine(t_philo *philo)
{
	while (!check_routine_stop(philo))
	{
		if (is_one_philo(philo))
			return ;
		if (philo->nb_philos % 2 == 1)
			usleep_loop(philo->times.eat / 2, philo);
		takes_forks(philo);
		pthread_mutex_lock(philo->time_mutex);
		philo->last_meal = get_current_time_ms();
		pthread_mutex_unlock(philo->time_mutex);
		print_step(philo, GREEN, "is eating");
		pthread_mutex_lock(philo->meal_mutex);
		philo->meal_count++;
		pthread_mutex_unlock(philo->meal_mutex);
		usleep_loop(philo->times.eat, philo);
		drop_forks(philo);
		print_step(philo, BLUE, "is sleeping");
		usleep_loop(philo->times.sleep, philo);
		print_step(philo, CYAN, "is thinking");
	}
}

void	*launch_philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	print_step(philo, CYAN, "is thinking");
	if (philo->id % 2 == 0)
		usleep_loop(philo->times.eat / 2, philo);
	philo_routine(philo);
	return (NULL);
}

bool	launch_routines(t_data *data)
{
	t_threads	threads;
	int			i;

	memset(&threads, 0, sizeof(threads));
	if (pthread_create(&threads.monitor, NULL, monitor_routine, data->philo))
		return (error_monitor_case(data));
	i = 0;
	while (i < data->nb_philos)
	{
		if (pthread_create(&threads.philos[i], NULL, launch_philo_routine,
				&data->philo[i]))
			return (error_philo_case(data, data->nb_philos));
		i++;
	}
	pthread_join(threads.monitor, NULL);
	i = 0;
	while (i < data->nb_philos)
	{
		pthread_join(threads.philos[i], NULL);
		i++;
	}
	return (false);
}
