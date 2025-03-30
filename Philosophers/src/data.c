/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nass <nass@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 06:37:30 by nass              #+#    #+#             */
/*   Updated: 2025/03/29 07:17:21 by nass             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void recup_args(int argc, char **argv, t_data *data_ptr)
{
    long long tmp;
    
    if (argc != 5 && argc != 6)
        print_and_exit(FORMAT_ERROR);
    tmp = ft_atoll(argv[1]);
    if (tmp > INT_MAX)
        print_and_exit("numbers of philosophers must be < INT_MAX");
    data_ptr->args.numbers_of_philosophers = tmp;
    tmp = ft_atoll(argv[2]);
    if (tmp > LONG_MAX)
        print_and_exit("time to die must be < LONG_MAX");
    data_ptr->args.time_to_die = tmp;
    tmp = ft_atoll(argv[3]);
    if (tmp > LONG_MAX)
        print_and_exit("time to eat must be < LONG_MAX");
    data_ptr->args.time_to_eat = tmp;
    tmp = ft_atoll(argv[4]);
    if (tmp > LONG_MAX)
        print_and_exit("time to sleep must be < LONG_MAX");
    data_ptr->args.time_to_sleep = tmp;
    if (argc == 6)
    {
        tmp = ft_atoll(argv[5]);
        if (tmp > INT_MAX)
            print_and_exit("meals to reach must be < INT_MAX");
        data_ptr->args.meals_to_reach = tmp;
    }
    else
        data_ptr->args.meals_to_reach = -1;
}

void create_mutexes(t_data *data_ptr)
{
    int id;

    id = 0;
    data_ptr->mutexes.forks = malloc(sizeof(pthread_mutex_t) * data_ptr->args.numbers_of_philosophers);
    while (id < data_ptr->args.numbers_of_philosophers)
    {
        pthread_mutex_init(&data_ptr->mutexes.forks[id], NULL);
        id++;
    }
    pthread_mutex_init(&data_ptr->mutexes.print_mutex, NULL);
}

void create_philos(t_data *data_ptr)
{
    int id;
    
    id = 0;
    data_ptr->ent.philos = malloc(sizeof(t_philo) * data_ptr->args.numbers_of_philosophers);
    while (id < data_ptr->args.numbers_of_philosophers)
    {
        init_philo(&data_ptr->ent.philos[id], *data_ptr);
        id++;
    }
}

void create_threads(t_data *data_ptr)
{
    int id;

    id = 0;
    data_ptr->threads.philos = malloc(sizeof(pthread_t) * data_ptr->args.numbers_of_philosophers);
    while (id < data_ptr->args.numbers_of_philosophers)
    {
        pthread_create(&data_ptr->threads.philos[id], NULL, philo_routine, (void *)&data_ptr->ent.philos[id]);
        id++;
    }
    id = 0;
    while (id < data_ptr->args.numbers_of_philosophers)
    {
        pthread_join(data_ptr->threads.philos[id], NULL);
        id++;
    }
}
