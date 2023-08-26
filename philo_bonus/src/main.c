#include "defines.h"
#include "philo.h"
#include "ft_string.h"

int	main(int argc, char **argv)
{
	t_philo_data_main	datas;
	t_philo_data		*child_datas;
	unsigned int		i;

	child_datas = &datas;
	philo_parse_args(child_datas, argc, argv);
	datas.childs = malloc(sizeof(pid_t) * child_datas->nphilos);
	if (!datas.childs)
		philo_exit(child_datas, 1);
	ft_memset(datas.childs, -1, sizeof(pid_t) * child_datas->nphilos);
	i = 0;
	while (i < child_datas->nphilos)
	{
		child_datas->id = i + 1;
		philo_fork(child_datas);
	}
	monitor_and_kill(&datas);
}