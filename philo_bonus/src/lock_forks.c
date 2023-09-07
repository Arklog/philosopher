#include "philo.h"

void	lock_forks(t_philo_data *d)
{
	sem_wait(d->forks_prelock.sem);
	sem_wait(d->forks.sem);
	philo_print(d, "has taken a fork");
	sem_wait(d->forks.sem);
	philo_print(d, "has taken a fork");
	sem_post(d->forks_prelock.sem);
}

void	unlock_forks(t_philo_data *d)
{
	sem_post(d->forks.sem);
	sem_post(d->forks.sem);
}
