#include "philo.h"

void	monitor_and_kill(t_philo_data_main *philo_data)
{
	int i;

	i = 0;
	while (i < philo_data->_data.nphilos)
		waitpid(philo_data->childs[i++], NULL, 0);
	philo_exit(philo_data, 0);
}
