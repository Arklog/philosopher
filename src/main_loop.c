#include "philo.h"

void	main_loop(t_philo_data *d)
{
	unsigned int	i;

	while (!d->finished)
	{
		i = 0;
		while (i < d->nthreads)
		{
			if (test_is_dead(d->philos + i))
			{
				d->finished = 1;
			}
			i++;
		}
		usleep(5);
	}
}
