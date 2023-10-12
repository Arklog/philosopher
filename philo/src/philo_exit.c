/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:39:38 by pducloux          #+#    #+#             */
/*   Updated: 2023/10/11 16:17:39 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

static void	free_forks(t_philo_data *d)
{
	unsigned int	i;

	i = 0;
	while (i < (u_int64_t)d->nphilos && d->forks)
	{
		if (d->forks[i].i)
			pthread_mutex_destroy(&(d->forks[i].m));
		++i;
	}
	free(d->forks);
}

static void	free_threads(t_philo_data *d)
{
	unsigned int	i;
	unsigned int	max;

	if (!d->threads)
		return ;
	pthread_mutex_lock(&(d->thread_init_mutex.m));
	max = (unsigned int)d->thread_init;
	pthread_mutex_unlock(&(d->thread_init_mutex.m));
	i = 0;
	while (i < max)
	{
		pthread_join(d->threads[i++], NULL);
	}
	free(d->threads);
}

void	philo_exit(t_philo_data *d)
{
	unsigned int	i;

	i = 0;
	free_threads(d);
	while (i < (u_int64_t)d->nphilos && d->philosophers)
	{
		if (d->philosophers[i].last_eat_mutex.i)
			pthread_mutex_destroy(&(d->philosophers[i].last_eat_mutex.m));
		if (d->philosophers[i].remaining_eat_mutex.i)
			pthread_mutex_destroy(&(d->philosophers[i].remaining_eat_mutex.m));
		++i;
	}
	if (d->is_finished_mutex.i)
		pthread_mutex_destroy(&(d->is_finished_mutex.m));
	if (d->thread_init_mutex.i)
		pthread_mutex_destroy(&(d->thread_init_mutex.m));
	free_forks(d);
	free(d->philosophers);
	exit(0);
}
