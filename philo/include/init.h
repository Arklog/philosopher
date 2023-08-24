#ifndef INIT_H
# define INIT_H

# include <stdlib.h>
# include "defines.h"

/**
 * Initialize philo
 *
 * @param argc
 * @param argv
 * @param d
 */
void	philo_init(int argc, char **argv, t_philo_data *d);

void	philo_exit(t_philo_data *d);

#endif
