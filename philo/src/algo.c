/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:39:12 by pducloux          #+#    #+#             */
/*   Updated: 2023/09/07 19:39:13 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*algo(void *arg)
{
	t_philosopher	*p;

	p = (t_philosopher *)arg;
	p->last_eat = gettimestamp();
	while (!is_philo_finished(p->datas) && p->remaining_eat)
	{
		philosopher_eat(p);
		philosopher_sleep(p);
		philosopher_think(p);
	}
	return (NULL);
}
