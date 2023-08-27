#include "philo.h"

void	philo_eat(t_philo_data *d)
{
	u_int64_t	timestamp;

	sem_wait(d->forks);
	philo_print(d, "has taken a fork");
	sem_wait(d->forks + 1);
	timestamp = get_timestamp();
	d->last_eat = timestamp;
	philo_print(d, "has taken a fork");
	philo_print(d, "is eating");
	usleep(timestamp + d->tte - get_timestamp());
	sem_post(d->forks);
	sem_post(d->forks + 1);
}
