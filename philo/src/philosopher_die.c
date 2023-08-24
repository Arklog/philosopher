#include "philo.h"

void	philosopher_die(t_philosopher *p)
{
	printf("%lu %d died\n", gettimestamp(), p->id);
}
