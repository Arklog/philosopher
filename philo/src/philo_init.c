/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducloux <pducloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:39:41 by pducloux          #+#    #+#             */
/*   Updated: 2023/10/12 19:43:24 by pducloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "ft_string.h"
#include "ft_stdlib.h"

static void	rev_forks(t_philo_data *d)
{
	unsigned int	i;
	t_mutex			*tmp;
	t_philosopher	*p;

	i = 0;
	while (i < (u_int64_t)d->nphilos)
	{
		if (i & 1)
		{
			p = d->philosophers + i;
			tmp = p->first;
			p->first = p->second;
			p->second = tmp;
		}
		++i;
	}
}

static int	init_one_philo(t_philosopher *p, t_philo_data *d, unsigned int i)
{
	p->id = i + 1;
	if (pthread_mutex_init(&(p->last_eat_mutex.m), NULL))
		return (0);
	else
		p->last_eat_mutex.i = TRUE;
	if (pthread_mutex_init(&(p->remaining_eat_mutex.m), NULL))
		return (0);
	else
		p->remaining_eat_mutex.i = TRUE;
	p->remaining_eat = d->max_eat;
	p->first = d->forks + i;
	if ((int)i == d->nphilos - 1)
		p->second = d->forks;
	else
		p->second = d->forks + i + 1;
	p->datas = d;
	return (1);
}

static int	init_philos(t_philo_data *d)
{
	unsigned int	i;

	d->philosophers = malloc(d->nphilos * sizeof(t_philosopher));
	if (!d->philosophers)
		return (0);
	ft_memset(d->philosophers, 0, sizeof(t_philosopher) * d->nphilos);
	i = 0;
	while (i < (u_int64_t)d->nphilos)
	{
		init_one_philo(d->philosophers + i, d, i);
		++i;
	}
	rev_forks(d);
	return (1);
}

static int	init_mutexes(t_philo_data *d)
{
	unsigned int	i;

	if (!philo_init_mutex(&(d->is_finished_mutex)))
		return (0);
	d->forks = malloc(sizeof(t_mutex) * d->nphilos);
	if (!d->forks)
		return (0);
	ft_memset(d->forks, 0, d->nphilos * sizeof(t_mutex));
	i = 0;
	while ((int)i < d->nphilos)
	{
		if (!philo_init_mutex(&(d->forks[i])))
			return (0);
		++i;
	}
	if (!philo_init_mutex(&(d->still_eating_mutex)))
		return (0);
	if (!philo_init_mutex(&(d->thread_init_mutex)))
		return (0);
	return (1);
}

int	philo_init(int argc, char **argv, t_philo_data *d)
{
	char	*endptr;

	ft_memset(d, 0, sizeof(t_philo_data));
	if (!philo_parse_args(argc, argv, d))
		return (0);
	if (argc == 6)
	{
		d->max_eat = ft_strtoi(argv[5], &endptr, 10);
		if (endptr != argv[5] + ft_strlen(argv[5]) || d->max_eat < 0)
			return (0);
	}
	else
		d->max_eat = -1;
	if (!init_mutexes(d))
		return (0);
	if (!init_philos(d))
		return (0);
	d->threads = malloc(sizeof(pthread_t) * d->nphilos);
	return (1);
}
