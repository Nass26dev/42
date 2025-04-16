/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:12:16 by nyousfi           #+#    #+#             */
/*   Updated: 2025/04/09 12:28:39 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void print_error(char *error_msg, int message_length)
{
	write(STDERR_FILENO, error_msg, message_length);
	exit(EXIT_FAILURE);	
}

void free_ressources(t_table table, int nb, int exit_code, int step)
{
	int i;

	i = 0;
	while (i < nb)
	{
		pthread_mutex_destroy(&table.forks[i]);
		i++;
	}
	if (step == 2 || step == 3)
		pthread_mutex_destroy(&table.print_mutex);
	if (step == 3)
		pthread_mutex_destroy(&table.meal_mutex);
	exit(exit_code);
}

long get_current_time_ms(void)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void print_step(t_philo *philo, char *color, char *step)
{
	pthread_mutex_lock(philo->print_mutex);
	printf("%s%ld%s", PURPLE, get_current_time_ms() - philo->start_time, RESET);
	printf(" %d", philo->id);
	printf(" %s%s%s\n", color, step, RESET);
	pthread_mutex_unlock(philo->print_mutex);
}
