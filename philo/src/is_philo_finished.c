/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_philo_finished.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:38:47 by pducloux          #+#    #+#             */
/*   Updated: 2023/09/07 19:38:47 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	is_philo_finished(t_philo_data *d)
{
	t_bool	is_finished;

	pthread_mutex_lock(&(d->is_finished_mutex.m));
	is_finished = d->is_finished;
	pthread_mutex_unlock(&(d->is_finished_mutex.m));
	return (is_finished);
}
