#include "philo.h"

static void	eat(t_philosopher *p)
{
	t_philo_data	*datas;

	datas = p->datas;
	pthread_mutex_lock(&(p->last_eat_mutex.m));
	p->last_eat = gettimestamp();
	pthread_mutex_unlock(&(p->last_eat_mutex.m));
	printf("%lu %d is eating\n", p->last_eat, p->id);
	pthread_mutex_lock(&(p->remaining_eat_mutex.m));
	p->remaining_eat--;
	pthread_mutex_unlock(&(p->remaining_eat_mutex.m));
	usleep(datas->tte * 1000);
}

void	philosopher_eat(t_philosopher *p)
{
	t_philo_data	*datas;

	datas = p->datas;
	if (p->first == p->second)
	{
		printf("%lu %d is eating\n", gettimestamp(), p->id);
		usleep(datas->ttd * 1000 + 1000);
		return ;
	}
	pthread_mutex_lock(&(p->first->m));
	pthread_mutex_lock(&(p->second->m));
	if (!is_philo_finished(datas))
		eat(p);
	pthread_mutex_unlock(&(p->second->m));
	pthread_mutex_unlock(&(p->first->m));
}
