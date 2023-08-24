#include "philo.h"

t_bool	is_philo_finished(t_philo_data *d)
{
	t_bool	is_finished;

	pthread_mutex_lock(&(d->is_finished_mutex.m));
	is_finished = d->is_finished;
	pthread_mutex_unlock(&(d->is_finished_mutex.m));
	return (is_finished);
}
