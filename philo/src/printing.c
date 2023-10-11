/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:41:42 by pierre            #+#    #+#             */
/*   Updated: 2023/10/11 02:38:48 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_text(t_philosopher *p, char *text)
{
	static pthread_mutex_t	mutex = PTHREAD_MUTEX_INITIALIZER;

	pthread_mutex_lock(&mutex);
	printf("%lu %d %s\n", gettimestamp() - p->datas->start_time,
		p->id, text);
	pthread_mutex_unlock(&mutex);
}

void	print_take_fork(t_philosopher *p)
{
	if (!is_philo_finished(p->datas))
		print_text(p, "has taken a fork");
}

void	print_eat(t_philosopher *p)
{
	if (!is_philo_finished(p->datas))
		print_text(p, "is eating");
}

void	print_think(t_philosopher *p)
{
	if (!is_philo_finished(p->datas))
		print_text(p, "is thinking");
}

void	print_sleep(t_philosopher *p)
{
	if (!is_philo_finished(p->datas))
		print_text(p, "is sleeping");
}
