/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:39:12 by pducloux          #+#    #+#             */
/*   Updated: 2023/10/11 16:14:15 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*algo(void *arg)
{
	t_philosopher	*p;
	t_philo_data	*d;

	p = (t_philosopher *)arg;
	d = p->datas;
	pthread_mutex_lock(&(d->thread_init_mutex.m));
	if (d->thread_init != d->nphilos)
	{
		pthread_mutex_unlock(&(d->thread_init_mutex.m));
		return (NULL);
	}
	pthread_mutex_unlock(&(d->thread_init_mutex.m));
	if (p->id % 2)
		usleep(p->datas->tte * 1000);
	while (!is_philo_finished(p->datas))
	{
		philosopher_eat(p);
		philosopher_sleep(p);
		philosopher_think(p);
	}
	return (NULL);
}
