/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 02:43:32 by pducloux          #+#    #+#             */
/*   Updated: 2023/08/02 14:26:20 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	do_actions(t_philosopher *d)
{
	if (test_is_dead(d) || philo_is_finished(d->philo_data))
		return ;
	do_eat(d);
	if (test_is_dead(d) || philo_is_finished(d->philo_data))
		return ;
	do_sleep(d);
	if (test_is_dead(d) || philo_is_finished(d->philo_data))
		return ;
	do_think(d);
	if (test_is_dead(d) || philo_is_finished(d->philo_data))
		return ;
	if (get_timestamp() - d->last_eat > d->philo_data->ttd)
		do_die(d);
}

void	*algo(void *td)
{
	t_philosopher	*d;

	d = td;
	while (!test_is_dead(d) && !philo_is_finished(d->philo_data))
		do_actions(d);
	return (NULL);
}
