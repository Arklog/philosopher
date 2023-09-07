#include "philo.h"

static void	*child_monitor(t_philo_data *d)
{
	while (!philo_is_dead(d) && !d->is_finished)
		usleep(5000);
	return (NULL);
}

static void	algo(t_philo_data *d)
{
	pthread_t	ths[2];
	int			tids[2];

	d->is_finished = 0;
	d->last_eat = get_timestamp();
	tids[0] = pthread_create(&(ths[0]), NULL,
			(void *(*)(void *))philo_algo, d);
	if (tids[0])
		exit(1);
	tids[1] = pthread_create(&(ths[1]), NULL,
			(void *(*)(void *))child_monitor, d);
	if (tids[1])
		exit(1);
	sem_wait(d->sem_finished.sem);
	d->is_finished = 1;
	pthread_join(ths[0], NULL);
	pthread_join(ths[1], NULL);
	philo_exit_child(d);
}

void	philo_fork(t_philo_data_main *d)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		philo_exit(d, 1);
	else if (pid == 0)
		algo((t_philo_data *)d);
	else
		d->childs[d->_data.id - 1] = pid;
}
