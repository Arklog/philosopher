#include "philo.h"

t_bool	have_philosopher_eaten(t_philosopher *p)
{
	t_bool	ret;

	pthread_mutex_lock(&(p->remaining_eat_mutex.m));
	ret = p->remaining_eat == 0;
	pthread_mutex_unlock(&(p->remaining_eat_mutex.m));
	return (ret);
}
