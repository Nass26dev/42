/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyousfi <nyousfi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:43:00 by nass              #+#    #+#             */
/*   Updated: 2025/01/24 17:28:21 by nyousfi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long get_current_time_ms()
{
    struct timeval tv;
	
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int main(int argc, char **argv)
{
    t_list *lst;

    lst = create_philosophers(argc, argv);
    free_lst(lst, 0);
    return 0;
}
