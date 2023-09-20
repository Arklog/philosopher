#include "philo.h"

void	print_take_fork(t_philosopher *p)
{
	if (!is_philo_finished(p->datas))
		printf("%lu %d has taken a fork\n",
			gettimestamp() - p->datas->start_time, p->id);
}

void	print_eat(t_philosopher *p)
{
	if (!is_philo_finished(p->datas))
		printf("%lu %d is eating\n",
			gettimestamp() - p->datas->start_time, p->id);
}

void	print_think(t_philosopher *p)
{
	if (!is_philo_finished(p->datas))
		printf("%lu %d is thinking\n",
			gettimestamp() - p->datas->start_time, p->id);
}

void	print_sleep(t_philosopher *p)
{
	if (!is_philo_finished(p->datas))
		printf("%lu %d is sleeping\n",
			gettimestamp() - p->datas->start_time, p->id);
}
