#include "philo.h"

void	philo_set_finished(t_philo_data *d)
{
	pthread_mutex_lock(&(d->mutex_is_finished));
	d->is_finished = true;
	pthread_mutex_unlock(&(d->mutex_is_finished));
}
