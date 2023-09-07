#include "philo.h"
#include "ft_string.h"
#include "ft_stdlib.h"
#include <fcntl.h>

static void	init_sems(t_philo_data_main *d)
{
	d->_data.output_sem.name = "philo_output";
	d->_data.output_sem.sem = sem_open("philo_output", O_CREAT, 0644, 1);
	if (d->_data.output_sem.sem == SEM_FAILED)
		philo_exit(d, 1);
	d->_data.forks.name = "philo_forks";
	d->_data.forks.sem = sem_open("philo_forks", O_CREAT, 0644, d->_data.nphilos);
	if (d->_data.forks.sem == SEM_FAILED)
		philo_exit(d, 1);
	d->_data.forks_prelock.name = "philo_forks_prelock";
	d->_data.forks_prelock.sem = sem_open("philo_forks_prelock", O_CREAT, 0644, 1);
	if (d->_data.forks_prelock.sem == SEM_FAILED)
		philo_exit(d, 1);
	d->_data.sem_finished.name = "philo_finished";
	d->_data.sem_finished.sem = sem_open("philo_finished", O_CREAT, 0644, 0);
	if (d->_data.sem_finished.sem == SEM_FAILED)
		philo_exit(d, 1);
}

void	philo_init(t_philo_data_main *philo_data)
{
	int	i;

	i = philo_data->_data.nphilos;
	philo_data->childs = malloc(sizeof(pid_t) * i);
	if (!philo_data->childs)
		philo_exit(philo_data, 1);
	ft_memset(philo_data->childs, 0, sizeof(pid_t) * i);
	init_sems(philo_data);
	pthread_mutex_init(&(philo_data->_data.mutex_last_eat), NULL);
}
