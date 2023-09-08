/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_think.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:39:56 by pducloux          #+#    #+#             */
/*   Updated: 2023/09/07 19:39:57 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philosopher_think(t_philosopher *p)
{
	if (!is_philo_finished(p->datas))
		printf("%lu %d is thinking\n",
			gettimestamp() - p->datas->start_time, p->id);
}
