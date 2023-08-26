#ifndef PHILO_H
# define PHILO_H

# include "defines.h"

void	philo_parse_args(t_philo_data *philo_data, int argc, char **argv);

void	philo_exit(t_philo_data *philo_data, int exit_code);

void	philo_fork(t_philo_data_main *philo_data);

void	monitor_and_kill(t_philo_data_main *philo_data);

#endif