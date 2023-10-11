/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:37:42 by pducloux          #+#    #+#             */
/*   Updated: 2023/10/10 18:35:25 by pierre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "philo.h"

int fork_index(t_mutex *fork, t_mutex *forks, int n)
{
	int	i = 0;

	while (i < n)
	{
		if (fork == forks + i)
			return i + 1;
		++i;
	}
	return (-1);
}

void debug_forks(t_philo_data *d)
{
	int i = 0;

	printf("FORK ASSIGNMENT PREVIEW\n");
	while (i < d->nphilos)
	{
		t_philosopher	*p = d->philosophers + i;
		printf("%d => (%d, %d)\n", i + 1, fork_index(p->first, d->forks, d->nphilos), fork_index(p->second, d->forks, d->nphilos));
		++i;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	unsigned int	i;
	t_philo_data	d;

	philo_init(argc, argv, &d);
	d.start_time = gettimestamp();
	d.still_eating = d.nphilos;
	debug_forks(&d);
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
