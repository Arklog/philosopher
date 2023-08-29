#include "philo.h"
#include "ft_stdlib.h"
#include "ft_string.h"

static void	parse_mandatory(t_philo_data_main *philo_data, int argc, char **argv)
{
	char	*endptr;

	(void)argc;
	philo_data->_data.nphilos = ft_strtoi(argv[1], &endptr, 10);
	if (endptr != argv[1] + ft_strlen(argv[1]))
		philo_exit(philo_data, 1);
	philo_data->_data.ttd = ft_strtoi(argv[2], &endptr, 10);
	if (endptr != argv[2] + ft_strlen(argv[2]))
		philo_exit(philo_data, 1);
	philo_data->_data.tte = ft_strtoi(argv[3], &endptr, 10);
	if (endptr != argv[3] + ft_strlen(argv[3]))
		philo_exit(philo_data, 1);
	philo_data->_data.tts = ft_strtoi(argv[4], &endptr, 10);
	if (endptr != argv[4] + ft_strlen(argv[4]))
		philo_exit(philo_data, 1);
}

static void	check_args(t_philo_data_main *d, int argc)
{
	if (d->_data.nphilos <= 0)
		philo_exit(d, 1);
	else if (d->_data.ttd < 0)
		philo_exit(d, 1);
	else if (d->_data.tte < 0)
		philo_exit(d, 1);
	else if (d->_data.tts < 0)
		philo_exit(d, 1);
	else if (argc == 6 && d->_data.max_eat < 0)
		philo_exit(d, 1);
}

void	philo_parse_args(t_philo_data_main *philo_data, int argc, char **argv)
{
	char	*endptr;

	if (argc < 5 || argc > 6)
		philo_exit(philo_data, 1);
	parse_mandatory(philo_data, argc, argv);
	if (argc == 5)
		philo_data->_data.max_eat = -1;
	else
	{
		philo_data->_data.max_eat = ft_strtoi(argv[5], &endptr, 10);
		if (endptr != argv[5] + ft_strlen(argv[5]))
			philo_exit(philo_data, 1);
	}
	check_args(philo_data, argc);
}
