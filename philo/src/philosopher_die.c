/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_die.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:39:44 by pducloux          #+#    #+#             */
/*   Updated: 2023/10/11 02:39:34 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philosopher_die(t_philosopher *p)
{
	set_philo_finished(p->datas);
	print_text(p, "died\n");
	// printf("%lu %d died\n", gettimestamp() - p->datas->start_time, p->id);
}
