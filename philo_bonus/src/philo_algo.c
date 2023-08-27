#include "philo.h"

void	philo_algo(t_philo_data *d)
{
	while (d->max_eat)
	{
		philo_eat(d);
		philo_sleep(d);
		philo_think(d);
		(d->max_eat)--;
	}
}
