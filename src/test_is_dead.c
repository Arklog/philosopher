#include "philo.h"

bool	test_is_dead(t_philosopher *d)
{
	pthread_mutex_lock(&(d->mutex_is_dead.mutex));
	if (d->is_dead)
	{
		pthread_mutex_unlock(&(d->mutex_is_dead.mutex));
		return (true);
	}
	else
	{
		pthread_mutex_unlock(&(d->mutex_is_dead.mutex));
		return (false);
	}
}
