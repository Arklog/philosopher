/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   have_philosopher_eaten.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:39:06 by pducloux          #+#    #+#             */
/*   Updated: 2023/09/07 19:39:07 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	have_philosopher_eaten(t_philosopher *p)
{
	t_bool	ret;

	pthread_mutex_lock(&(p->remaining_eat_mutex.m));
	ret = p->remaining_eat == 0;
	pthread_mutex_unlock(&(p->remaining_eat_mutex.m));
	return (ret);
}
