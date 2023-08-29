#include "philo.h"

void	philo_die(t_philo_data *d)
{
	philo_print(d, "died");
	philo_exit((t_philo_data_main *)d, 0);
}
