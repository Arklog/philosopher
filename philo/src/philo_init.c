#include "init.h"
#include "ft_string.h"
#include "ft_stdlib.h"

static void	rev_forks(t_philo_data *d)
{
	unsigned int	i;
	t_mutex			*tmp;
	t_philosopher	*p;

	i = 0;
	while (i < d->nphilos)
	{
		if (i & 1)
		{
			p = d->philosophers + i;
			tmp = p->first;
			p->first = p->second;
			p->second = tmp;
		}
	}
}

static void	init_philos(t_philo_data *d)
{
	unsigned int	i;
	t_philosopher	*p;

	d->philosophers = malloc(d->nphilos * sizeof(t_philosopher));
	if (!d->philosophers)
		philo_exit(d);
	ft_memset(d->philosophers, 0, sizeof (t_philosopher) * d->nphilos);
	i = 0;
	while (i < d->nphilos)
	{
		p = d->philosophers + i;
		p->id = i + 1;
		if (!pthread_mutex_init(&(p->last_eat_mutex.m), NULL))
			philo_exit(d);
		else
			p->last_eat_mutex.i = TRUE;
		p->first = d->forks + i;
		if (i == d->nphilos - 1)
			p->second = d->forks;
		else
			p->second = d->forks + i + 1;
		p->datas = d;
	}
	rev_forks(d);
}

static void	init_mutexes(t_philo_data *d)
{
	unsigned int	i;

	if (!pthread_mutex_init(&(d->is_finished_mutex.m), NULL))
		philo_exit(d);
	else
		d->is_finished_mutex.i = TRUE;
	d->forks = malloc(sizeof(t_mutex) * d->nphilos);
	if (!d->forks)
		philo_exit(d);
	ft_memset(d->forks, 0, d->nphilos * sizeof(t_mutex));
	i = 0;
	while (i < d->nphilos)
	{
		if (!pthread_mutex_init(&(d->forks[i].m), NULL))
			philo_exit(d);
		else
			d->forks[i].i = TRUE;
	}
}

void	philo_init(int argc, char **argv, t_philo_data *d)
{
	char	*endptr;

	ft_memset(d, 0, sizeof(t_philo_data));
	if (argc < 5 || argc > 6)
		philo_exit(d);
	d->nphilos = ft_strtoi(argv[1], &endptr, 10);
	if (endptr != argv[1] + ft_strlen(argv[1]))
		philo_exit(d);
	d->ttd = ft_strtoi(argv[2], &endptr, 10);
	if (endptr != argv[2] + ft_strlen(argv[2]))
		philo_exit(d);
	d->tte = ft_strtoi(argv[3], &endptr, 10);
	if (endptr != argv[3] + ft_strlen(argv[3]))
		philo_exit(d);
	d->tts = ft_strtoi(argv[4], &endptr, 10);
	if (endptr != argv[4] + ft_strlen(argv[4]))
		philo_exit(d);
	init_mutexes(d);
	init_philos(d);
}