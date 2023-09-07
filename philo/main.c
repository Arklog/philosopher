/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:37:42 by pducloux          #+#    #+#             */
/*   Updated: 2023/09/07 19:37:48 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "philo.h"

int	main(int argc, char **argv)
{
	unsigned int	i;
	t_philo_data	d;

	philo_init(argc, argv, &d);
	i = 0;
	while (i < (u_int64_t)d.nphilos)
	{
		d.philosophers[i].last_eat = gettimestamp();
		pthread_create(d.threads + i, NULL, &algo, d.philosophers + i);
		++i;
	}
	monitor(&d);
	philo_exit(&d);
	return (0);
}
