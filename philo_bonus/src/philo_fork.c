#include "philo.h"

static void	algo(t_philo_data *d)
{
	
}

void	philo_fork(t_philo_data_main *philo_data)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		philo_exit(&philo_data->_data, 1);
	if (pid == 0)
	{
		
	}
}