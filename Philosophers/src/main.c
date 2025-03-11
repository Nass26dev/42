/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:43:00 by nass              #+#    #+#             */
/*   Updated: 2025/03/11 09:49:28 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long	get_time_in_ms(struct timeval start_time)
{
	long current_temp;
	long start_temp;
	struct timeval tv;

	gettimeofday(&tv, NULL);
	current_temp = (tv.tv_sec * 1000 + (tv.tv_usec / 1000));
	start_temp = ((start_time.tv_sec * 1000) + (start_time.tv_usec / 1000));
	return (current_temp - start_temp);
}

void	lock_and_print(char *to_print, long int current_time, int id, pthread_mutex_t *print_mutex)
{
	pthread_mutex_lock(print_mutex);
	printf(to_print, current_time, id);
	pthread_mutex_unlock(print_mutex);
}

bool	is_dead(t_philo *philo)
{
	long current_time;
	long time_since_lm;
	long start_ms;
	
	current_time = get_time_in_ms(philo->start_time);
	time_since_lm = get_time_in_ms(philo->last_meal_time);
	if (time_since_lm > philo->time_to_die)
	{
		lock_and_print("%ld %d died\n", get_time_in_ms(philo->start_time), philo->id, philo->print_mutex);
		return (true);
	}
	return (false);
}

void *routine(void *arg)
{
	t_philo *philo = (t_philo *)arg;

	while (philo->meals_eaten < philo->max_meals)
	{
		if (is_dead(philo))
			break ;
		lock_and_print("%ld %d is thinking\n", get_time_in_ms(philo->start_time), philo->id, philo->print_mutex);
		usleep(1000 * 500);
		if (is_dead(philo))
			break ;
		pthread_mutex_lock(philo->left_fork);
		lock_and_print("%ld %d has taken a fork\n", get_time_in_ms(philo->start_time), philo->id, philo->print_mutex);
		
		pthread_mutex_lock(philo->right_fork);
		lock_and_print("%ld %d has taken a fork\n", get_time_in_ms(philo->start_time), philo->id, philo->print_mutex);
		
		lock_and_print("%ld %d is eating\n", get_time_in_ms(philo->start_time), philo->id, philo->print_mutex);
		philo->meals_eaten++;
		gettimeofday(&philo->last_meal_time, NULL);
		usleep(philo->time_to_eat * 1000);
		
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		
		if (is_dead(philo))
			break ;

		lock_and_print("%ld %d is sleeping\n", get_time_in_ms(philo->start_time), philo->id, philo->print_mutex);
		usleep(philo->time_to_sleep * 1000);
	}
	return (NULL);
}

void wait_threads(t_args args, pthread_t *threads)
{
	int i;

	i = 0;
	while (i < args.numbers_of_philosophers)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
}

void destroy_mutex(t_args args, pthread_mutex_t *forks, pthread_mutex_t *print_mutex)
{
	int i;

	i = 0;
	while (i < args.numbers_of_philosophers)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	pthread_mutex_destroy(print_mutex);
	free(forks);
}

int main(int argc, char **argv)
{
	pthread_t *threads;
	pthread_mutex_t *forks;
	t_philo *philos;
	t_args args;
	pthread_mutex_t print_mutex;
	struct timeval start_time;

	(void)argc;
	gettimeofday(&start_time, NULL);
	args = recup_args(argv);
	forks = create_forks(args);
	pthread_mutex_init(&print_mutex, NULL);
	philos = create_philos(args, forks, &print_mutex, start_time);
	threads = create_threads(args ,philos);
	wait_threads(args, threads);
	destroy_mutex(args, forks, &print_mutex);

	return (EXIT_SUCCESS);
}
