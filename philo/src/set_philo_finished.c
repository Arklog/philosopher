#include "philo.h"

void	set_philo_finished(t_philo_data *d)
{
	pthread_mutex_lock(&(d->is_finished_mutex.m));
	d->is_finished = TRUE;
	pthread_mutex_unlock(&(d->is_finished_mutex.m));
}
