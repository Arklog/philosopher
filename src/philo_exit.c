/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 02:34:37 by pducloux          #+#    #+#             */
/*   Updated: 2023/08/02 15:29:26 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "libft.h"

static void	free_one_philosopher(t_philosopher *p)
{
	if (p->mutex_is_dead.is_initialized)
		pthread_mutex_destroy(&(p->mutex_is_dead.mutex));
	if (p->neat_mutex.is_initialized)
		pthread_mutex_destroy(&(p->neat_mutex.mutex));
}

static void	free_all(void)
{
	t_philo_data	*p;

	p = philo();
	while (p->iforks > 0)
		pthread_mutex_destroy(p->forks + (--p->iforks));
	if (p->forks)
		free(p->forks);
	if (p->philos)
	{
		while (p->nphilo > 0)
			free_one_philosopher(p->philos + --(p->nphilo));
		free(p->philos);
	}
	if (p->threads)
		free(p->threads);
	if (p->is_finished_initialized)
		pthread_mutex_destroy(&(p->mutex_is_finished));
}

void	philo_exit(int code, char *msg)
{
	free_all();
	if (msg)
		ft_putstrfd(msg, (int)(code > 0));
	exit(code);
}
