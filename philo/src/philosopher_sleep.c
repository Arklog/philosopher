#include "philo.h"
#include "ft_math.h"

void	philosopher_sleep(t_philosopher *p)
{
	if (!is_philo_finished(p->datas))
	{
		printf("%lu %d is sleeping\n", gettimestamp(), p->id);
		usleep(p->datas->tts * 1000);
	}
}
