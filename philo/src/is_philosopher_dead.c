/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_philosopher_dead.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:39:16 by pducloux          #+#    #+#             */
/*   Updated: 2023/10/11 02:37:02 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	is_philosopher_dead(t_philosopher *d)
{
	t_philo_data	*datas;
	int64_t			since_last_eat;

	datas = d->datas;
	pthread_mutex_lock(&(d->last_eat_mutex.m));
	since_last_eat = (int64_t)gettimestamp() - (int64_t)d->last_eat;
	pthread_mutex_unlock(&(d->last_eat_mutex.m));
	return (since_last_eat >= datas->ttd);
}
