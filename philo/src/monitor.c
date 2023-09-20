/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:39:24 by pducloux          #+#    #+#             */
/*   Updated: 2023/09/07 19:41:15 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <sys/types.h>

void	monitor(t_philo_data *d)
{
	int		i;
	int64_t	remaining_eat;

	while (!is_philo_finished(d))
	{
		i = 0;
		while (i < d->nphilos)
		{
			if (is_philosopher_dead(d->philosophers + i++))
			{
				set_philo_finished(d);
				philosopher_die(d->philosophers + i - 1);
				return ;
			}
		}
		pthread_mutex_lock(&(d->max_eat_mutex.m));
		remaining_eat = d->max_eat;
		pthread_mutex_unlock(&(d->max_eat_mutex.m));
		if (!remaining_eat)
			set_philo_finished(d);
		usleep(5000);
	}
}
