#include "philo.h"
#include "ft_string.h"
#include "ft_stdlib.h"
#include <fcntl.h>

static void	init_sems(t_philo_data_main *philo_data)
{
	int		i;

	philo_data->_data.output_sem = sem_open("philo_output", O_CREAT, 0644, 1);
	if (philo_data->_data.output_sem == SEM_FAILED)
		philo_exit(philo_data, 1);
	i = 0;
	while (i < philo_data->_data.nphilos)
	{
		philo_data->forks[i] = sem_open(ft_itoa(i), O_CREAT, 0644, 1);
		if (philo_data->forks[i] == SEM_FAILED)
			philo_exit(philo_data, 1);
		++i;
	}
}

void	philo_init(t_philo_data_main *philo_data)
{
	int	i;

	i = philo_data->_data.nphilos;
	philo_data->childs = malloc(sizeof(pid_t) * i);
	if (!philo_data->childs)
		philo_exit(philo_data, 1);
	philo_data->forks = malloc(sizeof(sem_t *) * i);
	if (!philo_data->forks)
		philo_exit(philo_data, 1);
	ft_memset(philo_data->childs, 0, sizeof(pid_t) * i);
	ft_memset(philo_data->forks, 0, sizeof(sem_t *) * i);
	init_sems(philo_data);
	pthread_mutex_init(&(philo_data->_data.mutex_last_eat), NULL);
}
