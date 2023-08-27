#include "philo.h"

void	philo_die(t_philo_data *d)
{
	philo_print(d, "died");
	exit(0);
}
