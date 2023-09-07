#include "philo.h"

void	philo_think(t_philo_data *d)
{
	if (!philo_is_dead(d))
		philo_print(d, "is thinking");
}
