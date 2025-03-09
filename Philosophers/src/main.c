/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nass <nass@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:43:00 by nass              #+#    #+#             */
/*   Updated: 2025/03/09 01:31:01 by nass             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void *routine(void *arg)
{
	t_philo *philo = (t_philo *)arg;

	while (philo->meals_eaten < philo->max_meals)
	{
		pthread_mutex_lock(philo->write_mutex);
		printf("Philosophe %d pense...\n", philo->id);
		pthread_mutex_unlock(philo->write_mutex);
		usleep(1000 * 500);
		
		pthread_mutex_lock(philo->left_fork);
		pthread_mutex_lock(philo->write_mutex);
		printf("Philosophe %d prend sa fourchette gauche.\n", philo->id);
		pthread_mutex_unlock(philo->write_mutex);
		pthread_mutex_lock(philo->right_fork);
		pthread_mutex_lock(philo->write_mutex);
		printf("Philosophe %d prend sa fourchette droite et commence a manger.\n", philo->id);
		pthread_mutex_unlock(philo->write_mutex);

		philo->meals_eaten++;
		usleep(philo->time_to_eat * 1000);

		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_lock(philo->write_mutex);
		printf("Philosophe %d repose ses fourchettes.\n", philo->id);
		pthread_mutex_unlock(philo->write_mutex);
		pthread_mutex_lock(philo->write_mutex);
		printf("Philosophe %d dors.\n", philo->id);
		pthread_mutex_unlock(philo->write_mutex);
		usleep(philo->time_to_sleep * 1000);
	}
	printf("Philosophe %d a terminé son repas.\n", philo->id);
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

void destroy_mutex(t_args args, pthread_mutex_t *forks, pthread_mutex_t *write_mutex)
{
	int i;

	i = 0;
	while (i < args.numbers_of_philosophers)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	pthread_mutex_destroy(write_mutex);
	free(forks);
}

int main(int argc, char **argv)
{
	pthread_t *threads;
	pthread_mutex_t *forks;
	t_philo *philos;
	t_args args;
	pthread_mutex_t write_mutex;
	struct timeval start_time;

	(void)argc;
	gettimeofday(&start_time, NULL);
	args = recup_args(argv);
	forks = create_forks(args);
	pthread_mutex_init(&write_mutex, NULL);
	philos = create_philos(args, forks, &write_mutex, start_time);
	threads = create_threads(args ,philos);
	wait_threads(args, threads);
	destroy_mutex(args, forks, &write_mutex);

	return (EXIT_SUCCESS);
}
