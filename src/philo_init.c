/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 02:23:18 by pducloux          #+#    #+#             */
/*   Updated: 2023/07/19 02:26:22 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "ft_stdlib.h"
#include "ft_string.h"

static void	philo_init_mutex(t_philo_data *p)
{
	p->forks = malloc(sizeof(pthread_mutex_t) * p->nphilo);
	if (!p->forks)
		philo_exit(1, "Malloc error\n");
	while (p->iforks < p->nphilo)
	{
		if (pthread_mutex_init(p->forks + p->iforks, NULL))
			philo_exit(1, "Mutex initialization failure\n");
		++(p->iforks);
	}
}

static void philo_init_one(t_philo_data *pd, t_thread_data *d, unsigned int i)
{
	ft_memset(d, 0, sizeof(t_thread_data));
	d->tid = i;
	d->philo_data = pd;
	d->fork_l = pd->forks + i;
	if (i == pd->nphilo - 1)
		d->fork_r = pd->forks;
	else
		d->fork_r = pd->forks + i + 1;
}

static void	philo_init_philo(t_philo_data *p)
{
	unsigned int	i;

	p->philos = malloc(sizeof(t_thread_data) * p->nphilo);
	if (!p->philos)
		philo_exit(1, "Malloc error\n");
	ft_memset(p->philos, 0, sizeof(t_thread_data) * p->nphilo);
	i = 0;
	while (i < p->nphilo)
	{
		p->philos[i].tid = i;
		philo_init_one(p, p->philos + i, i);
		++i;
	}
	p->threads = malloc(sizeof(pthread_t) * p->nphilo);
	if (!p->threads)
		philo_exit(1, "Malloc error\n");
}

void	philo_init(int argc, char **argv)
{
	char			*endptr;
	t_philo_data	*p;

	p = philo();
	if (argc < 5)
		philo_exit(1, "Not enought arguments\n");
	else if (argc > 6)
		philo_exit(1, "Too many arguments\n");
	p->nphilo = ft_strtol(argv[1], &endptr, 10);
	if (endptr != argv[1] + ft_strlen(argv[1]))
		philo_exit(1, "Wrond argument\n");
	p->ttd = ft_strtol(argv[2], &endptr, 10);
	if (endptr != argv[2] + ft_strlen(argv[2]))
		philo_exit(1, "Wrong argument\n");
	p->tte = ft_strtol(argv[3], &endptr, 10);
	if (endptr != argv[3] + ft_strlen(argv[3]))
		philo_exit(1, "Wrong argument\n");
	p->tts = ft_strtol(argv[4], &endptr, 10);
	if (endptr != argv[4] + ft_strlen(argv[4]))
		philo_exit(1, "Wrong argument\n");
	philo_init_mutex(p);
	philo_init_philo(p);
}
