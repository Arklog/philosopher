#include "philo.h"

bool	philo_is_finished(t_philo_data *pd)
{
	bool	is_finished;

	pthread_mutex_lock(&(pd->mutex_is_finished));
	is_finished = pd->is_finished;
	pthread_mutex_unlock(&(pd->mutex_is_finished));
	return (is_finished);
}
