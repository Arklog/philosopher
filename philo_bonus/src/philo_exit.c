#include "philo.h"

void	philo_exit(t_philo_data_main *d, int exit_code)
{
	int	i;

	i = 0;
	while (i < d->_data.nphilos)
	{
		if (d->forks[i] != SEM_FAILED)
			sem_close(d->forks[i]);
		++i;
	}
	sem_close(d->_data.output_sem);
	pthread_mutex_destroy(&(d->_data.mutex_last_eat));
	if (d->childs)
		free(d->childs);
	if (d->forks)
		free(d->forks);
	exit(exit_code);
}