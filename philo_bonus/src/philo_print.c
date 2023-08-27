#include "philo.h"

void	philo_print(t_philo_data *d, char *str)
{
	sem_wait(d->output_sem);
	printf("%lu %d %s\n", get_timestamp, d->id, str);
	sem_post(d->output_sem);
}
