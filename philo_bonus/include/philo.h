#ifndef PHILO_H
# define PHILO_H

# include "defines.h"


/*********************
 * Main functions
*********************/

void	philo_parse_args(t_philo_data *philo_data, int argc, char **argv);

void	philo_exit(t_philo_data *philo_data, int exit_code);

void	philo_fork(t_philo_data_main *philo_data);

void	monitor_and_kill(t_philo_data_main *philo_data);

/*********************
 * Philo actions
*********************/

void	philo_algo(t_philo_data *d);

void	philo_eat(t_philo_data *d);

void	philo_sleep(t_philo_data *d);

void	philo_think(t_philo_data *d);

void	philo_die(t_philo_data *d);

void	philo_print(t_philo_data *d, char *str);


/********************
 * Utils
********************/

u_int64_t	get_timestamp(void);

#endif