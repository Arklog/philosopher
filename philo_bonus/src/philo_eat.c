#include "philo.h"

void	philo_eat(t_philo_data *d)
{
	u_int64_t	timestamp;

	sem_wait((sem_t *)d->forks);
	if (!philo_is_dead(d))
		philo_print(d, "has taken a fork");
	sem_wait((sem_t *)(d->forks + 1));
	timestamp = get_timestamp();
	pthread_mutex_lock(&(d->mutex_last_eat));
	d->last_eat = timestamp;
	pthread_mutex_unlock(&(d->mutex_last_eat));
	if (!philo_is_dead(d))
	{
		philo_print(d, "has taken a fork");
		philo_print(d, "is eating");
	}
	usleep(timestamp + d->tte - get_timestamp());
	sem_post((sem_t *)d->forks);
	sem_post((sem_t *)(d->forks + 1));
}
