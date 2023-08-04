#include "do.h"
#include "philo.h"

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
	is_dead(d);
}

void	do_eat(t_philosopher *d)
{
	pthread_mutex_lock(d->fork_l);
	pthread_mutex_lock(d->fork_r);
	d->last_eat = get_timestamp();
	is_eating(d);
	usleep(d->philo_data->tte * 1000);
	pthread_mutex_unlock(d->fork_l);
	pthread_mutex_unlock(d->fork_r);
}
