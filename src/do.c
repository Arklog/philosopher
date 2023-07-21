#include "do.h"

void	do_sleep(t_thread_data *d)
{
	t_philo_data	*pd;

	pd = d->philo_data;
	is_sleeping(d);
	usleep(pd->tts * 1000);
}

void	do_think(t_thread_data *d)
{
	is_thinking(d);
}

void	do_die(t_thread_data *d)
{
	pthread_mutex_lock(&d->mutex_is_dead);
	d->is_dead = 1;
	is_dead(d);
	pthread_mutex_unlock(&d->mutex_is_dead);
}

void	do_eat(t_thread_data *d)
{
	pthread_mutex_lock(d->fork_l);
	pthread_mutex_lock(d->fork_r);
	d->last_eat = get_timestamp();
	is_eating(d);
	pthread_mutex_unlock(d->fork_l);
	pthread_mutex_unlock(d->fork_r);
}
