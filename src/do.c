#include "do.h"

void	do_sleep(t_philosopher *d)
{
	t_philo_data	*pd;

	pd = d->philo_data;
	is_sleeping(d);
	usleep(pd->tts * 1000);
}

void	do_think(t_philosopher *d)
{
	is_thinking(d);
}

void	do_die(t_philosopher *d)
{
	philo_set_finished(d->philo_data);
	is_dead(d);
}

void	do_eat(t_philosopher *d)
{
	pthread_mutex_lock(d->fork_l);
	pthread_mutex_lock(d->fork_r);
	d->last_eat = get_timestamp();
	is_eating(d);
	pthread_mutex_unlock(d->fork_l);
	pthread_mutex_unlock(d->fork_r);
}
