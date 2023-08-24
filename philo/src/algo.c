#include "philo.h"

void	*algo(void *arg)
{
	t_philosopher	*p;

	p = (t_philosopher *)arg;
	p->last_eat = gettimestamp();
	while (!is_philo_finished(p->datas) && p->remaining_eat)
	{
		philosopher_eat(p);
		philosopher_sleep(p);
		philosopher_think(p);
	}
	return (NULL);
}
