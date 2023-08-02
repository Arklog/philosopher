#include "philo.h"

static bool	all_ate(t_philo_data *d)
{
	unsigned int	i;
	unsigned int	sum;

	i = 0;
	sum = 0;
	while (i < d->nphilo)
	{
		pthread_mutex_lock(&(d->philos[i].neat_mutex.mutex));
		sum += d->philos[i].neat;
		pthread_mutex_unlock(&(d->philos[i].neat_mutex.mutex));
		++i;
	}
	return (!sum);
}

void	main_loop(t_philo_data *d)
{
	if (d->neat < 0)
	{
		while (!philo_is_finished(d))
			usleep(5);
	}
	else
	{
		while (!philo_is_finished(d) || !all_ate(d))
			usleep(5);
	}
}