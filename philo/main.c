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

static int check_vals(t_philo_data d)
{
	if (d.nphilos < 1)
		return (FALSE);
	else if (d.ttd < 0)
		return (FALSE);
	else if (d.tte < 0)
		return (FALSE);
	else if (d.tts < 0)
		return (FALSE);
	return (TRUE);
}

int	main(int argc, char **argv)
{
	unsigned int	i;
	t_philo_data	d;

	philo_init(argc, argv, &d);
	if (!check_vals(d))
		philo_exit(&d);
	d.start_time = gettimestamp();
	d.still_eating = d.nphilos;
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
