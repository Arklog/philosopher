#include "philo.h"

int	test_is_dead(t_philosopher *d)
{
	pthread_mutex_lock(&d->mutex_is_dead);
	if (d->is_dead)
	{
		pthread_mutex_unlock(&d->mutex_is_dead);
		return (1);
	}
	else
	{
		pthread_mutex_unlock(&d->mutex_is_dead);
		return (0);
	}
}