#include "philo.h"

void	philosopher_think(t_philosopher *p)
{
	if (!is_philo_finished(p->datas))
		printf("%lu %d is thinking\n", gettimestamp(), p->id);
}
