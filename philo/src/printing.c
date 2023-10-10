/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre </var/spool/mail/pierre>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:41:42 by pierre            #+#    #+#             */
/*   Updated: 2023/10/10 12:41:42 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre </var/spool/mail/pierre>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:58:09 by pierre            #+#    #+#             */
/*   Updated: 2023/09/21 14:58:09 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_take_fork(t_philosopher *p)
{
	if (!is_philo_finished(p->datas))
		printf("%lu %d has taken a fork\n",
			gettimestamp() - p->datas->start_time, p->id);
}

void	print_eat(t_philosopher *p)
{
	if (!is_philo_finished(p->datas))
		printf("%lu %d is eating\n",
			gettimestamp() - p->datas->start_time, p->id);
}

void	print_think(t_philosopher *p)
{
	if (!is_philo_finished(p->datas))
		printf("%lu %d is thinking\n",
			gettimestamp() - p->datas->start_time, p->id);
}

void	print_sleep(t_philosopher *p)
{
	if (!is_philo_finished(p->datas))
		printf("%lu %d is sleeping\n",
			gettimestamp() - p->datas->start_time, p->id);
}
