#include "philo.h"

void	philo_die(t_philo_data *d)
{
	d->is_finished = 1;
	philo_print(d, "died");
}
