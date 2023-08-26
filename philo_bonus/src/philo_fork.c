#include "philo.h"

void	philo_fork(t_philo_data_main *philo_data)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		philo_exit(&philo_data->_data, 1);
	if (pid == 0)
	{
		philo_data->_data.id = philo_data->_data.id + 1;
		philo_data->childs[philo_data->_data.id - 1] = getpid();
	}
}