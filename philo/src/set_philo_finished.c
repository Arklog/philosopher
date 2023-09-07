/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_philo_finished.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:39:59 by pducloux          #+#    #+#             */
/*   Updated: 2023/09/07 19:40:00 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_philo_finished(t_philo_data *d)
{
	pthread_mutex_lock(&(d->is_finished_mutex.m));
	d->is_finished = TRUE;
	pthread_mutex_unlock(&(d->is_finished_mutex.m));
}
