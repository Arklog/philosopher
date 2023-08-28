#include "philo.h"

void	monitor_and_kill(t_philo_data_main *philo_data)
{
	pid_t	pid;
	pid_t	tmp;
	int		i;

	pid = waitpid(0, NULL, 0);
	i = 0;
	while (i < philo_data->_data.nphilos)
	{
		tmp = philo_data->childs[i];
		if (tmp != pid)
			kill(tmp, SIGKILL);
		++i;
	}
	philo_exit(philo_data, 0);
}
