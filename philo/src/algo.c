/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:39:12 by pducloux          #+#    #+#             */
/*   Updated: 2023/10/11 05:31:38 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*algo(void *arg)
{
	t_philosopher	*p;

	p = (t_philosopher *)arg;
	if (p->id % 2)
		usleep(p->datas->tte * 1000);
	while (!is_philo_finished(p->datas))
	{
		philosopher_eat(p);
		philosopher_sleep(p);
		philosopher_think(p);
	}
	return (NULL);
}
