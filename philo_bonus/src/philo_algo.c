#include "philo.h"

void	*philo_algo(t_philo_data *d)
{
	int	i;

	while (d->max_eat && !philo_is_dead(d))
	{
		philo_eat(d);
		philo_sleep(d);
		philo_think(d);
		(d->max_eat)--;
	}
	d->is_finished = 1;
	i = 0;
	while (i++ < d->nphilos)
		sem_post(d->sem_finished.sem);
	return (NULL);
}
