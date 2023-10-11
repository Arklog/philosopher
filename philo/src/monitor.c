/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:39:24 by pducloux          #+#    #+#             */
/*   Updated: 2023/10/11 02:14:58 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <sys/types.h>

void	monitor(t_philo_data *d)
{
	int		i;
	int64_t	still_eating;

	while (!is_philo_finished(d))
	{
		i = 0;
		while (i < d->nphilos)
		{
			if (is_philosopher_dead(d->philosophers + i++))
			{
				philosopher_die(d->philosophers + i - 1);
				return ;
			}
		}
		pthread_mutex_lock(&(d->still_eating_mutex.m));
		still_eating = d->still_eating;
		pthread_mutex_unlock(&(d->still_eating_mutex.m));
		if (!still_eating)
			set_philo_finished(d);
		usleep(5000);
	}
}
