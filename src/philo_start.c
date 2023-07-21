#include "philo.h"

void	philo_start(t_philo_data *d)
{
	unsigned int	i;

	i = 0;
	while (i < d->nphilo)
	{
		pthread_create(&d->threads[i], NULL, algo, d->philos + i);
		++i;
	}
}
