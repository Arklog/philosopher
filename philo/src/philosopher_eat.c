/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_eat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:39:47 by pducloux          #+#    #+#             */
/*   Updated: 2023/09/07 19:39:48 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	eat(t_philosopher *p)
{
	t_philo_data	*datas;

	datas = p->datas;
	pthread_mutex_lock(&(p->last_eat_mutex.m));
	p->last_eat = gettimestamp();
	pthread_mutex_unlock(&(p->last_eat_mutex.m));
	printf("%lu %d is eating\n", p->last_eat - p->datas->start_time, p->id);
	pthread_mutex_lock(&(p->remaining_eat_mutex.m));
	p->remaining_eat--;
	pthread_mutex_unlock(&(p->remaining_eat_mutex.m));
	usleep(datas->tte * 1000);
	pthread_mutex_lock(&(p->last_eat_mutex.m));
	p->last_eat = gettimestamp();
	pthread_mutex_unlock(&(p->last_eat_mutex.m));
}

void	philosopher_eat(t_philosopher *p)
{
	t_philo_data	*datas;

	datas = p->datas;
	if (p->first == p->second)
	{
		printf("%lu %d is eating\n",
			gettimestamp() - p->datas->start_time, p->id);
		usleep(datas->ttd * 1000 + 1000);
		return ;
	}
	pthread_mutex_lock(&(p->first->m));
	printf("%lu %d has taken a fork\n", gettimestamp() - datas->start_time,
		   p->id);
	pthread_mutex_lock(&(p->second->m));
	printf("%lu %d has taken a fork\n", gettimestamp() - datas->start_time,
		   p->id);
	if (!datas->is_finished)
		eat(p);
	pthread_mutex_unlock(&(p->second->m));
	pthread_mutex_unlock(&(p->first->m));
}
