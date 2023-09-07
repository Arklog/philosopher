/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:39:38 by pducloux          #+#    #+#             */
/*   Updated: 2023/09/07 19:39:38 by pducloux         ###   ########.fr       */
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

	if (!d->threads)
		return ;
	i = 0;
	while (i < (u_int64_t)d->nphilos && d->threads)
	{
		pthread_join(d->threads[i++], NULL);
	}
	free(d->threads);
}

void	philo_exit(t_philo_data *d)
{
	unsigned int	i;

	i = 0;
	while (i < (u_int64_t)d->nphilos && d->philosophers)
	{
		if (d->philosophers[i].last_eat_mutex.i)
			pthread_mutex_destroy(&(d->philosophers[i].last_eat_mutex.m));
		if (d->philosophers[i].remaining_eat_mutex.i)
			pthread_mutex_destroy(&(d->philosophers[i].remaining_eat_mutex.m));
		++i;
	}
	free_threads(d);
	free_forks(d);
	free(d->philosophers);
	exit(0);
}
