#include "philo.h"

void	philo_sleep(t_philo_data *d)
{
	philo_print(d, "is sleeping");
	usleep(d->tts * 1000);
}
