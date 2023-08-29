#ifndef PHILO_H
# define PHILO_H

# include "defines.h"
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>

/*********************
 * Main functions
*********************/

/**
 * Parse the arguments
 *
 * @param philo_data
 * @param argc
 * @param argv
 */
void	philo_parse_args(t_philo_data_main *philo_data, int argc, char **argv);

/**
 * Initialize datas
 *
 * @param philo_data
 */
void	philo_init(t_philo_data_main *philo_data);

/**
 * Exit philosopher with given exit code
 *
 * @param philo_data
 * @param exit_code
 */
void	philo_exit(t_philo_data_main *philo_data, int exit_code);

/**
 * Start a child
 *
 * @param d
 */
void	philo_fork(t_philo_data_main *d);

/**
 * Monitor childs and kill them all when one dies
 *
 * @param philo_data
 */
void	monitor_and_kill(t_philo_data_main *philo_data);

/*********************
 * Philo actions
*********************/

void	*philo_algo(t_philo_data *d);

void	philo_eat(t_philo_data *d);

void	philo_sleep(t_philo_data *d);

void	philo_think(t_philo_data *d);

void	philo_die(t_philo_data *d);

void	philo_print(t_philo_data *d, char *str);

t_bool	philo_is_dead(t_philo_data *d);

/**
 * Monitor the current process and exit it on death
 * @param arg
 * @return
 */
void	*monitor(void *arg);

/********************
 * Utils
********************/

u_int64_t	get_timestamp(void);

#endif