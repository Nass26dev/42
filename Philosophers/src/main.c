/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nass <nass@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 06:36:19 by nass              #+#    #+#             */
/*   Updated: 2025/03/29 07:16:03 by nass             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int main(int argc, char **argv)
{
    t_data data;
    
    recup_args(argc, argv, &data);
    create_mutexes(&data);
    data.start_time = get_time_in_ms();
    create_philos(&data);
    create_threads(&data);
}
