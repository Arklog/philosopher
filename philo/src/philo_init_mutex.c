/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init_mutex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:05:49 by pducloux          #+#    #+#             */
/*   Updated: 2023/10/11 16:17:06 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "philo.h"

int	philo_init_mutex(t_mutex *m)
{
	if (pthread_mutex_init(&(m->m), NULL))
	{
		return (FALSE);
	}
	else
	{
		m->i = TRUE;
		return (TRUE);
	}
}