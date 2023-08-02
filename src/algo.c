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

void	*algo(void *td)
{
	t_philosopher	*d;

	d = td;
	while (!test_is_dead(d))
	{
		do_eat(d);
		do_sleep(d);
		do_think(d);
		if (get_timestamp() - d->last_eat > d->philo_data->ttd)
			do_die(d);
	}
	return (NULL);
}
