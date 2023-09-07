#include "philo.h"

void	philo_eat(t_philo_data *d)
{
	u_int64_t	timestamp;

	lock_forks(d);
	timestamp = get_timestamp();
	pthread_mutex_lock(&(d->mutex_last_eat));
	d->last_eat = timestamp;
	pthread_mutex_unlock(&(d->mutex_last_eat));
	philo_print(d, "has taken a fork");
	philo_print(d, "is eating");
	usleep(d->tte * 1000);
	unlock_forks(d);
}
