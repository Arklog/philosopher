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
	print_eat(p);
	pthread_mutex_lock(&(p->remaining_eat_mutex.m));
	p->remaining_eat--;
	if (!p->remaining_eat)
	{
		pthread_mutex_lock(&(datas->still_eating_mutex.m));
		datas->still_eating--;
		pthread_mutex_unlock(&(datas->still_eating_mutex.m));
	}
	pthread_mutex_unlock(&(p->remaining_eat_mutex.m));
	usleep(datas->tte * 1000);
	print_text(p, "finished eating");
	// pthread_mutex_lock(&(p->last_eat_mutex.m));
	// p->last_eat = gettimestamp();
	// pthread_mutex_unlock(&(p->last_eat_mutex.m));
}

void	philosopher_eat(t_philosopher *p)
{
	t_philo_data	*datas;

	datas = p->datas;
	if (p->first == p->second)
	{
		print_take_fork(p);
		usleep(datas->ttd * 1000 + 1000);
		return ;
	}
	if (is_philo_finished(p->datas))
		return ;
	pthread_mutex_lock(&(p->first->m));
	print_take_fork(p);
	pthread_mutex_lock(&(p->second->m));
	print_take_fork(p);
	eat(p);
	pthread_mutex_unlock(&(p->second->m));
	pthread_mutex_unlock(&(p->first->m));
}
