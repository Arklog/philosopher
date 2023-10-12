/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:37:42 by pducloux          #+#    #+#             */
/*   Updated: 2023/10/12 20:24:26 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "philo.h"

static void	start_threads(t_philo_data *data)
{
	t_philo_data	d;
	unsigned int	i;
	int				isuccess;

	d = *data;
	i = 0;
	d.thread_init = 0;
	isuccess = 1;
	while (i < (u_int64_t)d.nphilos && isuccess)
	{
		d.philosophers[i].last_eat = gettimestamp();
		if (pthread_create(d.threads + i, NULL, &algo, d.philosophers + i))
		{
			isuccess = 0;
			set_philo_finished(data);
		}
		else
			data->thread_init++;
		++i;
	}
}

int	main(int argc, char **argv)
{
	t_philo_data	d;

	if (philo_init(argc, argv, &d))
	{
		d.start_time = gettimestamp();
		d.still_eating = d.nphilos;
		pthread_mutex_lock(&(d.thread_init_mutex.m));
		start_threads(&d);
		pthread_mutex_unlock(&(d.thread_init_mutex.m));
		monitor(&d);
	}
	philo_exit(&d);
	return (0);
}
