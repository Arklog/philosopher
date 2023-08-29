#include "defines.h"
#include "philo.h"
#include "ft_string.h"

int	main(int argc, char **argv)
{
	t_philo_data_main	datas;
	t_philo_data		*child_datas;
	int		i;

	ft_memset(&datas, 0, sizeof(t_philo_data_main));
	child_datas = (t_philo_data *)&datas;
	philo_parse_args(&datas, argc, argv);
	philo_init(&datas);
	i = 0;
	while (i < child_datas->nphilos)
	{
		child_datas->id = (int)++i;
		philo_fork(&datas);
	}
	monitor_and_kill(&datas);
}
