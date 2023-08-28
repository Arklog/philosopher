#include "philo.h"

static void	algo(t_philo_data *d)
{
	pthread_t	th;
	int			i;

	d->last_eat = get_timestamp();
	i = pthread_create(&th, NULL,
			(void *(*)(void *))philo_algo, d);
	if (!i)
		exit(1);
	i = pthread_detach(th);
	if (!i)
		exit(1);
	while (!philo_is_dead(d))
		usleep(5000);
	philo_die(d);
	exit(0);
}

void	philo_fork(t_philo_data_main *d)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		philo_exit(&d->_data, 1);
	else if (pid == 0)
		algo((t_philo_data *)d);
	else
		d->childs[d->_data.id - 1] = pid;
}
