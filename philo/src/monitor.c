#include "philo.h"
#include <sys/types.h>

void	monitor(t_philo_data *d)
{
	int		i;
	int64_t	eat_sum;

	while (!is_philo_finished(d))
	{
		i = 0;
		eat_sum = 0;
		while (i < d->nphilos)
		{
			if (is_philosopher_dead(d->philosophers + i++))
			{
				set_philo_finished(d);
				philosopher_die(d->philosophers + i - 1);
//				return ;
			}
			pthread_mutex_lock(&(d->philosophers[i - 1].remaining_eat_mutex.m));
			eat_sum += d->philosophers[i - 1].remaining_eat;
			pthread_mutex_unlock(&(d->philosophers[i - 1].remaining_eat_mutex.m));
		}
		if (eat_sum == 0)
			set_philo_finished(d);
		usleep(5000);
	}
}
