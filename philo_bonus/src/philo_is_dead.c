#include "philo.h"

t_bool	philo_is_dead(t_philo_data *d)
{
	t_bool	dead;

	pthread_mutex_lock(&(d->mutex_last_eat));
	dead = (t_bool)((get_timestamp() - d->last_eat) > (unsigned int)d->ttd);
	pthread_mutex_unlock(&(d->mutex_last_eat));
	return (dead);
}
